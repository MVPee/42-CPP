#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <deque>
# include <time.h>
# include <cstdlib>

class PmergeMe {
	private:
		std::list<int> 	_list;
		std::deque<int>	_deque;
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &src);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &rhs);
};

std::ostream &operator<<(std::ostream &o, const PmergeMe &i);

#endif /* ******************************************************** PMERGEME_H */