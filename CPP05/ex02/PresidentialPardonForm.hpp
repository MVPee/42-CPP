#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	private:
		const std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm& operator=(PresidentialPardonForm const & rhs);

		void	execute(Bureaucrat const &bureaucrat) const;
};

std::ostream& operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif /* ******************************************* PRESIDENTIALPARDONFORM_H */