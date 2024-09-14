#include "PmergeMe.hpp"

/*
** ------------------------------- STATIC -------------------------------------
*/

/*
		[3, 1, 4, 1, 5, 9]

	[3, 1, 4]		[1, 5, 9]
	[3] [1, 4]		[1] [5, 9]
	[3] [1] [4]		[1] [5] [9]
	[1, 3] [4]		[1, 5] [9]
	[1, 3, 4]		[1, 5, 9]

		[1, 1, 3, 4, 5, 9]
*/
template <typename T>
static void displayContainer(const T &container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template<typename Container>
static Container merge(const Container& left, const Container& right) {
    Container result;
    typename Container::const_iterator it1 = left.begin();
    typename Container::const_iterator it2 = right.begin();

    while (it1 != left.end() && it2 != right.end()) {
        if (*it1 < *it2) result.push_back(*it1++);
        else result.push_back(*it2++);
    }
    result.insert(result.end(), it1, left.end());
    result.insert(result.end(), it2, right.end());

    return result;
}

template<typename Container>
static std::pair<Container, Container> split(const Container& c) {
    Container left, right;
    typename Container::const_iterator it = c.begin();
    std::advance(it, c.size() / 2);
    left.assign(c.begin(), it);
    right.assign(it, c.end());
    return std::make_pair(left, right);
}

/*
	Divide by two the list in recursive 
	into many sublists of size 0 or 1 using the split function.
	Then merge the sublists to get a sorted list.
*/
template<typename Container>
static Container fordJohnsonSort(const Container& c) {
    if (c.size() <= 1) return c;
    std::pair<Container, Container> parts = split(c);
    Container left = fordJohnsonSort(parts.first);
    Container right = fordJohnsonSort(parts.second);

    return merge(left, right);
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

	std::clock_t start; 
	std::clock_t end;

	start = std::clock();
	_list = fordJohnsonSort(_list);
	end = std::clock();
	double time_list = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

	start = std::clock();
	_deque = fordJohnsonSort(_deque);
	end = std::clock();
	double time_deque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

	std::cout << "After: ";
    displayContainer(_list);

    std::cout << "Time to process a range of " << _list.size() << " elements with std::list: " << time_list << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque: " << time_deque << " us" << std::endl;
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