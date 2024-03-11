#include"cppSnips.h"
#include <iomanip>
#include <iterator>
#include <numeric>



void printString(const std::string& s) {
  std::cout << std::quoted(s) << "\n";
}


std::string dashFoldPrint(const std::vector<int>& v) {
  auto dashFold = [](std::string a, int b){ return std::move(a) + '-' + std::to_string(b);};
  std::string dfs = std::accumulate(std::next(v.begin()), v.end(), std::to_string(v.at(0)),dashFold);
  return dfs;
}

template<class ForwardIt, class T> 
void fill(ForwardIt first, ForwardIt last, const T& value) {
  for(; first!=last; ++first)
      *first = value;
}

//std::transform applies the given function to a range and stores the result in another range, keeping the original elements order and beginning at d_first.

template<class InputIt1, class InputIt2, 
         class OutputIt, class BinaryOperation>
OutputIt transform(InputIt1 first1, InputIt1 last1,
                   InputIt2 first2, OutputIt d_first,
                   BinaryOperation binary_op)
{
    while (first1 != last1)
        *d_first++ = binary_op(*first1++, *first2++);
 
    return d_first;
}

template<class InputIt, class Size, class UnaryFunction>
InputIt for_each_n(InputIt first, Size n, UnaryFunction f)
{
    for (Size i = 0; i < n; ++first, (void) ++i)
        f(*first);
 
    return first;
}


void println(auto const& v)
{
    for (auto count{v.size()}; auto const& e : v)
        std::cout << e << (--count ? ", " : "\n");
}
 

void foo() {
    std::string s{"hello"};
    auto op = [](unsigned char c) -> unsigned char { return std::toupper(c); };
 
    namespace ranges = std::ranges;
 
    // uppercase the string in-place
    ranges::transform(s.begin(), s.end(), s.begin(), op );
 
    std::vector<std::size_t> ordinals;
    // convert each char to size_t
    ranges::transform(s, std::back_inserter(ordinals),
                      [](unsigned char c) -> std::size_t { return c; });
 
    std::cout << s << ':';
    for (auto ord : ordinals)
        std::cout << ' ' << ord;
 
    // double each ordinal
    ranges::transform(ordinals, ordinals, ordinals.begin(), std::plus {});
 
    std::cout << '\n';
    for (auto ord : ordinals)
        std::cout << ord << ' ';
    std::cout << '\n';
 
    struct Foo
    {
        char bar;
    };
    const std::vector<Foo> f = {{'h'},{'e'},{'l'},{'l'},{'o'}};
    std::string result;
    // project, then uppercase
    ranges::transform(f, std::back_inserter(result), op, &Foo::bar);
    std::cout << result << '\n';
}

void func() {
    std::string s{"hello"};
    std::transform(s.cbegin(), s.cend(),
                   s.begin(), // write to the same location
                   [](unsigned char c) { return std::toupper(c); });

    std::cout << "s = " << std::quoted(s) << '\n';
 
    // achieving the same with std::for_each (see Notes above)
    std::string g{"hello"};
    std::for_each(g.begin(), g.end(), [](char& c) // modify in-place
    {
        c = std::toupper(static_cast<unsigned char>(c));
    });
    std::cout << "g = " << std::quoted(g) << '\n';
 
    std::vector<std::size_t> ordinals;
    std::transform(s.cbegin(), s.cend(), std::back_inserter(ordinals),
                   [](unsigned char c) { return c; });
 
 
    std::transform(ordinals.cbegin(), ordinals.cend(), ordinals.cbegin(),
                   ordinals.begin(), std::plus<>{});
 
}


// Look into std::prev, std::next
int main() {
  std::vector<int>  v(10);
  std::iota(v.begin(),v.end(),0);


  std::for_each(v.begin(),v.end(), [](const int& i){std::cout << i << " ";});

  auto ss = dashFoldPrint(v);  
  std::cout << ss << std::endl;


  std::for_each(v.begin(),v.end(), [](const int& i){std::cout << i << " ";});
  return 0;
}
