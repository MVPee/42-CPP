# define R "\x1b[1;31m"
# define G "\x1b[1;32m"
# define B "\x1b[1;36m"
# define Y "\x1b[1;33m"
# define M "\x1b[1;35m"
# define C "\x1b[0m"

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <map>
# include <string>
# include <climits>
# include <cstdlib>

class BitcoinExchange {
	private:
		std::map<int, std::string> _date;
    	std::map<int, float> _value;

		int findNearestDate(const std::string &date);
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
	public:
		BitcoinExchange(std::ifstream &file);
		~BitcoinExchange();

		void processLine(const std::string &line);
};

std::ostream &operator<<(std::ostream &o, const BitcoinExchange &i);

#endif /* ************************************************* BITCOINEXCHANGE_H */