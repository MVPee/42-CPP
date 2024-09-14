#include "PmergeMe.hpp"

/*
** ------------------------------- STATIC -------------------------------------
*/

template <typename T>
static void displayContainer(const T &container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(int ac, char **av) {
	for (int i = 1; i < ac; i++) {
		int nb = atoi(av[i]);
		if (nb <= 0 || std::string(av[i]).length() > 10) {
			std::cerr << "Error: Only positif integers allowed. (" + std::string(av[i]) + ")" << std::endl;
			exit(1);
		}
		_deque.push_back(nb);
		_list.push_back(nb);
	}
	std::cout << "Before: ";
	displayContainer(_deque);
}

PmergeMe::PmergeMe(const PmergeMe &src) {
	_list = src._list;
	_deque = src._deque;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe() {
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		_list = rhs._list;
		_deque = rhs._deque;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, const PmergeMe &i) {
	(void)i;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */