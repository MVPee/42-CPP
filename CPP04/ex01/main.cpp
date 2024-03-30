#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

# define N 4

int main(void)
{
    Animal* animal[N];

    std::cout << ORANGE << "PART1--- CREATE" << NONE << std::endl;
    for (int i = 0; i < N; i++) {
        if (i % 2)
            animal[i] = new Dog();
        else
            animal[i] = new Cat();
        std::cout << std::endl;
    }

    std::cout << ORANGE << "PART2--- SOUND" << NONE << std::endl;
    for (int i = 0; i < N; i++)
        animal[i]->makeSound();
    std::cout << std::endl;

    std::cout << ORANGE << "PART3--- DELETE" << NONE << std::endl;
    for (int i = 0; i < N; i++) {
        delete animal[i];
        std::cout << std::endl;
    }

    std::cout << ORANGE << "PART4--- DEEP COPY" << NONE << std::endl;
    Dog test;
    Dog tmp = test;

    Cat test2;
    Cat tmp2 = test2;
    return (0);
}