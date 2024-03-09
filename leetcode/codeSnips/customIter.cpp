
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

template<typename Func>
class FunctionOutputIterator {
public:
    using iterator_category = std::output_iterator_tag;
    using value_type = void;
    using difference_type = void;
    using pointer = void;
    using reference = void;

    explicit FunctionOutputIterator(Func f) : func(f) {}

    FunctionOutputIterator& operator*() { return *this; }
    FunctionOutputIterator& operator++() { return *this; }
    FunctionOutputIterator& operator++(int) { return *this; }

    template<typename T>
    FunctionOutputIterator& operator=(const T& value) {
        func(value);
        return *this;
    }

private:
    Func func;
};

template<typename Func>
FunctionOutputIterator<Func> make_function_output_iterator(Func f) {
    return FunctionOutputIterator<Func>(f);
}

int main() {
    std::vector<int> data{1, 2, 3, 4, 5};

    // Custom function to be used with the iterator
    auto print_with_space = [](int value) {
        std::cout << value << " ";
    };

    std::inclusive_scan(data.begin(), data.end(),
                        make_function_output_iterator(print_with_space));
    std::cout << std::endl;

    return 0;
}
