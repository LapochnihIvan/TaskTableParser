#include <iostream>

#include "TableParser.hpp"

int main()
{
    TableParser& reader(TableParser::getInstance());

    (void)reader.parseFile("../input.txt");

    for (const auto& taskSetting : reader.getData().value)
    {
        for (const auto& value : taskSetting)
        {
            if (!value.empty())
            {
                std::cout << value << '\n';
            }
        }
    }

    for (const auto& taskSetting : reader.getData().additionalInfo)
    {
        for (const auto& additionalInfo : taskSetting)
        {
            if (!additionalInfo.empty())
            {
                std::cout << additionalInfo << '\n';
            }
        }
    }
}
