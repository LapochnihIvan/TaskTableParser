#ifndef TASKTABLEPARSER_STRINGOPERATIONS_HPP
#define TASKTABLEPARSER_STRINGOPERATIONS_HPP


#include <utility>
#include <string>

#include "Utility.hpp"


class StringOperations
{
public:
    using StrBorders = std::pair<std::string::iterator, std::string::iterator>;

    StringOperations() = delete;

    static void cyrillicToLowetCase(std::string::iterator symBeg) noexcept;

    template<
        typename StrBordersT,
        typename = std::enable_if_t<isType<StrBordersT, StrBorders>>
    >
    static void transformUTF8StrToLowercase(StrBordersT&& strBorders) noexcept
    {
        for (auto symPtr(strBorders.first);
            symPtr != strBorders.second;
            ++symPtr)
        {
            if (*symPtr < '\000')
            {
                cyrillicToLowetCase(symPtr++);
            }
            else
            {
                *symPtr = static_cast<char>(std::tolower(*symPtr));
            }
        }
    }

    static void skipWhitespaces(std::string::iterator& begPtr) noexcept;
};


#endif //!TASKTABLEPARSER_STRINGOPERATIONS_HPP