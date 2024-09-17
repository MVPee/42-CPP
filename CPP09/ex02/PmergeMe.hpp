#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <deque>
# include <ctime>
# include <cstdlib>
# include <utility>
# include <limits.h>

class PmergeMe {
	private:
		std::list<int> 	_list;
		std::deque<int>	_deque;

		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &rhs);
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();
};

std::ostream &operator<<(std::ostream &o, const PmergeMe &i);

#endif /* ******************************************************** PMERGEME_H */