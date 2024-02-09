#include "Zombie.hpp"

int main(void) {
    
    std::cout << "Creating zombie one on the stack." << std::endl;
    Zombie one("one");
    one.annonce();

    std::cout << "Creating zombie two on the heap." << std::endl;
    Zombie *two = newZombie("two");
    two->annonce();

    std::cout << "Creating zombie three with randomChump." << std::endl;
    randomChump("three");
    
    // Need to free two 
    delete(two);

    return (0);
}