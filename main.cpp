#include <cassert>
#include <iostream>
#include <list>
#include <vector>

template <template<typename...> typename Container, typename T>
void square(Container<T>& values) {
    for(T& value : values) {
        value *= value;
    }
}

template <typename T>
void square(T& value) {
    value *= value;
}

int main() {
    int value_int = 2;
    double value_double = 3.0;
    std::vector<int> values_vector = {-1, 4, 8};
    std::list<double> values_list = {-1, 4, 8};

    square(value_int);
    square(value_double);
    square(values_vector);
    square(values_list);

    assert(value_int == 4);
    assert(value_double == 9.0);
    {
        std::vector<int> expected{1, 16, 64};
        assert(values_vector == expected);
    }
    {
        std::list<double> expected{1, 16, 64};
        assert(values_list == expected);
    }
    return 0;
}
