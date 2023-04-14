#include "StringOperations.hpp"


void
StringOperations::cyrillicToLowetCase(std::string::iterator symBeg) noexcept
{
    if (*symBeg == '\321' ||
        *(symBeg + 1) >= '\260' && *(symBeg + 1) <= '\277')
    {
        return;
    }

    if (*(symBeg + 1) == '\201')
    {
        *symBeg = '\321';
        *++symBeg = '\221';
    }
    else if (*(symBeg + 1) < '\240')
    {
        *symBeg = '\320';
        *++symBeg += ' ';
    }
    else
    {
        *symBeg = '\321';
        *++symBeg -= ' ';
    }
}

void
StringOperations::skipWhitespaces(std::string::iterator& begPtr) noexcept
{
    while (std::isspace(*begPtr))
    {
        ++begPtr;
    }
}
