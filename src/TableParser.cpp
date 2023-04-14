#include "TableParser.hpp"


#define END_TAG_POS 4

TableParser&
TableParser::getInstance() noexcept
{
    static TableParser instance;
    
    return instance;
}

bool
TableParser::parseFile(const char* const fileName) noexcept
{
    std::ifstream inputFileStrem(fileName);

    if (!inputFileStrem.is_open())
    {
        return false;
    }

    addNewTask();

    std::string line;
    while (std::getline(inputFileStrem, line))
    {
        if (isHasTag(line))
        {
            auto tagBorders(getTagBorders(line.begin() + 1));

            StringOperations::transformUTF8StrToLowercase(tagBorders);

            tagsPositionsKey tag(tagBorders.first, tagBorders.second);

            std::string::iterator& afterTagIterator(++tagBorders.second);
            StringOperations::skipWhitespaces(afterTagIterator);

            auto tagPosIterator(mTagsPositions.find(tag));

            if (tagPosIterator != mTagsPositions.end())
            {
                if (tagPosIterator->second == END_TAG_POS)
                {
                    addNewTask();

                    continue;
                }

                mData.value.back()[tagPosIterator->second] = 
                    std::string(afterTagIterator, line.end());
            }
            else
            {

            }
        }
        else
        {
            mData.additionalInfo.back().emplace_back(line);
        }
    }

    return true;
}

TableParser::TableParser() noexcept :
    mTagsPositions{
        {"название", 0},
        {"тип вопроса", 1},
        {"баллы", 2},
        {"ответ", 3},
        {"конец", END_TAG_POS}
    }
{

}

bool
TableParser::isHasTag(const std::string& line) noexcept
{
    return line.front() == '#';
}

StringOperations::StrBorders 
TableParser::getTagBorders(std::string::iterator tableLineBegPtr) noexcept
{
    StringOperations::skipWhitespaces(tableLineBegPtr);
    
    auto tagEndPtr(tableLineBegPtr);
    
    while (*tagEndPtr != ':' && *tagEndPtr != '\000')
    {
        ++tagEndPtr;
    }
    
    return StringOperations::StrBorders (tableLineBegPtr, tagEndPtr);
}

void
TableParser::addNewTask() noexcept
{
    mData.value.emplace_back();
    mData.additionalInfo.emplace_back();

    mData.value.back().resize(mTagsPositions.size());
}
