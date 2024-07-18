# include "Serialization.hpp"

int main(void) {
    Data data;

    data.value = 42;
    std::cout << Serialization::serialize(&data) << std::endl;
    uintptr_t test = Serialization::serialize(&data);

    std::cout << Serialization::deserialize(Serialization::serialize(&data)) << ".value:" << std::endl;
    std::cout << Serialization::deserialize(Serialization::serialize(&data))->value << std::endl;
    
    std::cout << Serialization::deserialize(test) << ".value:" << std::endl;
    std::cout << Serialization::deserialize(test)->value << std::endl;
    
    data.value++;

    std::cout << Serialization::deserialize(test) << ".value:" << std::endl;
    std::cout << Serialization::deserialize(test)->value << std::endl;

    return (0);
}