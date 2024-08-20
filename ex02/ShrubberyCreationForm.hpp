#if !defined(_SHRUBBERYCREATIONFORM_)
#define _SHRUBBERYCREATIONFORM_

#include "AForm.hpp"
#include <iostream>
#include <exception>

class ShrubberyCreationForm : public Form
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		void	execute(Bureaucrat const &executor) const;
};

#endif // _SHRUBBERYCREATIONFORM_
