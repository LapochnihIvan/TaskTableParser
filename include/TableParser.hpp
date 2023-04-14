#ifndef TASKTABLEPARSER_TASKTABLEPARSER_HPP
#define TASKTABLEPARSER_TASKTABLEPARSER_HPP


#include <limits>
#include <utility>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

#include "StringOperations.hpp"


class TableParser
{
public:
    struct TableData
    {
        std::vector<std::vector<std::string>> value;
        std::vector<std::vector<std::string>> additionalInfo;
    };

    TableParser(TableParser&) = delete;

    TableParser(TableParser&&) = delete;

    TableParser& operator=(TableParser&) = delete;

    static TableParser& getInstance() noexcept;

    [[nodiscard]] bool parseFile(const char* fileName) noexcept;

    template<
        typename StrT,
        typename = std::enable_if_t<
            isType<StrT, std::string> || isType<StrT, std::string_view>
        >
    >
    [[nodiscard]] bool parseFile(StrT&& fileName) noexcept
    {
        return parseFile(fileName.data());
    }

    const TableData& getData()
    {
        return mData;
    }

private:
    using tagsPositionsKey = std::string;

    const std::unordered_map<tagsPositionsKey, std::size_t> mTagsPositions;
    TableData mData;

    TableParser() noexcept;

    static bool isHasTag(const std::string& line) noexcept;

    static StringOperations::StrBorders
    getTagBorders(std::string::iterator tableLine) noexcept;

    void addNewTask() noexcept;
};


#endif //!TASKTABLEPARSER_TASKTABLEPARSER_HPP
