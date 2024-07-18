# include "iter.hpp"

# define SIZE 3

template <typename T>
void print(T &value) {
    std::cout << "value: " << value << std::endl;
}

template <typename T>
void increment(T &value) {
    value++;
}

int main(void) {
    int *int_array = new int[SIZE];
    for (size_t i = 0; i < SIZE; i++)
        int_array[i] = i * 3 % 2 + i;

    ::iter(int_array, SIZE, print<int>);
    ::iter(int_array, SIZE, increment<int>);
    std::cout << std::endl;

    ::iter(int_array, SIZE, print<int>);

    delete[] int_array;

    return (0);
}