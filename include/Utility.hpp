#ifndef TASKTABLEPARSER_UTILITY_HPP
#define TASKTABLEPARSER_UTILITY_HPP


template<typename CheckT, typename NeedT>
static constexpr bool isType{std::is_same_v<
    std::remove_reference_t<
        std::remove_const_t<
            std::remove_volatile_t<CheckT>
        >
    >,
    NeedT
>};


#endif //!TASKTABLEPARSER_UTILITY_HPP
