#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(std::ifstream &data) {
    std::string line, date;
    float value;
	int i = 0;

    std::getline(data, line);

    while (std::getline(data, line)) {
        std::stringstream line_stream(line);
        std::string value_str;

        if (std::getline(line_stream, date, ',') && std::getline(line_stream, value_str)) {
            try {
                value = std::stof(value_str);
				_date[i] = date;
				_value[i] = value;
            }
			catch (const std::invalid_argument& e) {
                std::cerr << "Erreur de conversion pour la ligne: " << line << std::endl;
            }
			i++;
        }
    }
	// for (size_t i = 0; i < _date.size(); i++) { //? DEBUG
	// 	std::cout << _date[i] << "," << _value[i] << std::endl;
	// }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	_date = src._date;
	_value = src._value;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange() {
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		;
	}
	return *this;
}

std::ostream &			operator<<(std::ostream &o, const BitcoinExchange &i) {
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

static bool check_date(const std::string &date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return true;

    std::string year_str = date.substr(0, 4);
    std::string month_str = date.substr(5, 2);
    std::string day_str = date.substr(8, 2);

    if (!std::all_of(year_str.begin(), year_str.end(), ::isdigit) ||
        !std::all_of(month_str.begin(), month_str.end(), ::isdigit) ||
        !std::all_of(day_str.begin(), day_str.end(), ::isdigit)) {
        return true;
    }

    int year = std::stoi(year_str);
    int month = std::stoi(month_str);
    int day = std::stoi(day_str);

    if (month < 1 || month > 12)
        return true;
    if (day < 1 || day > 31)
        return true;
    if (month == 2) {
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (leap ? 29 : 28))
            return true;
    }
	else if (month == 4 || month == 6 || month == 9 || month == 11)
        if (day > 30)
            return true;

    return false;
}

int dateToInt(const std::string &date) {
    int year, month, day;
    char dash1, dash2;
    std::istringstream iss(date);
    iss >> year >> dash1 >> month >> dash2 >> day;
    return year * 10000 + month * 100 + day; // Format YYYYMMDD
}

int BitcoinExchange::findNearestDate(const std::string &date) {
    int targetDateInt = dateToInt(date);

    int nearestKey = -1;
    int minDiff = INT_MAX;

    for (std::map<int, std::string>::const_iterator it = _date.begin(); it != _date.end(); ++it) {
        int mapDateInt = dateToInt(it->second);
        int diff = std::abs(mapDateInt - targetDateInt);

        if (diff < minDiff) {
            minDiff = diff;
            nearestKey = it->first;
        }
    }
    return nearestKey;
}

void BitcoinExchange::processLine(const std::string &line) {
	static unsigned int count = 2;
	std::string date, value_str;
	float value;
	date = line.substr(0, 10);
	if (check_date(date)) {
		std::cout << count << "." << Y << "\tdate format is not correct" << C << std::endl;
		count ++;
		return ;
	}
	std::string::size_type pos = line.find(" | ");
	if (pos == std::string::npos) {
		std::cout << count << "." << Y << "\tno value found" << C << std::endl;
		count ++;
		return ;
	}
	value_str = line.substr(pos + 3);
	try {
		value = std::stof(value_str);
		if (value < 0 || value > 1000) {
			std::cout << count << "." << Y << "\tvalue is not beetwen 0 and 1000" << C << std::endl;
			count ++;
			return ;
		}
	}
	catch (const std::invalid_argument& e) {
		std::cout << count << "." << Y << "\tvalue format is not correct" << C << std::endl;
		count ++;
		return ;
	}
	int nearest = findNearestDate(date);
	std::cout 	<< count << "." << G << "\t" << date << " => " << value_str << C \
				<< " = " << _value[nearest] * value << std::endl; 
	count ++;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */