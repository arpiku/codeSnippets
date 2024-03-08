template<class ForwardIt>
constexpr //< since C++20
ForwardIt is_sorted_until(ForwardIt first, ForwardIt last)
{
    return std::is_sorted_until(first, last, std::less<>());
}

template<class ForwardIt, class Compare>
constexpr //< since C++20
ForwardIt is_sorted_until(ForwardIt first, ForwardIt last, Compare comp)
{
    if (first != last)
    {
        ForwardIt next = first;
        while (++next != last)
        {
            if (comp(*next, *first))
                return next;
            first = next;
        }
    }
    return last;
}
