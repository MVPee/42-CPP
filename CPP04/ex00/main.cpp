#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;

    std::cout << std::endl;
    std::cout << "-----Part2-----" << std::endl;
    std::cout << std::endl;

    Animal animal;
    Dog dog;
    Cat cat;

    std::cout << std::endl;

    animal.makeSound();
    dog.makeSound();
    cat.makeSound();

    std::cout << std::endl;
    std::cout << "-----Part3-----" << std::endl;
    std::cout << std::endl;

    const WrongAnimal* test = new WrongCat();

    test->makeSound();
    std::cout << "That why you need to use virtual..." << std::endl;
    delete test;

    std::cout << std::endl;

    return (0);
}