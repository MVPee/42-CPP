#include "Zombie.hpp"

#define N 5

int main(void) {
    Zombie *horde = zombieHorde(N, "zombard");
    for (int i = 0; i < N; i++) {
        horde[i].annonce();
    }
    delete[] horde;
    return (0);
}