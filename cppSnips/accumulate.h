#include"cppSnips.h"

template<class InputIt, class T>
constexpr // since C++20
T accumulate(InputIt first, InputIt last, T init)
{
    for (; first != last; ++first)
        init = std::move(init) + *first; // std::move since C++20
 
    return init;
}

//std::move basically moves the pointers in such a way that a copy is not created of the original data, but the reference get's passed to the 
//new owner

//return value of std::move = static_cast<typename std::remove_reference<T>::type&&> (t) 
template<class InputIt, class T, class BinaryOperation>
constexpr // since C++20
T accumulate(InputIt first, InputIt last, T init, BinaryOperation op)
{
    for (; first != last; ++first)
        init = op(std::move(init), *first); // std::move since C++20
 
    return init;
}


template<class InputIt, class OutputIt>
constexpr // since C++20
OutputIt adjacent_difference(InputIt first, InputIt last, OutputIt d_first)
{
    if (first == last)
        return d_first;
 
    typedef typename std::iterator_traits<InputIt>::value_type value_t;
    value_t acc = *first;
    *d_first = acc;
 
    while (++first != last)
    {
        value_t val = *first;
        *++d_first = val - std::move(acc); // std::move since C++11
        acc = std::move(val);
    }
 
    return ++d_first;
}
