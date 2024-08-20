#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Creation Form", 145, 137), _target("NO TARGET")
{
	std::cout << "No target defined." << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << "Target initialized to " << _target << std::endl;
}

//copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form(copy), _target(copy._target)
{
	*this = copy;
	std::cout << "Copy Form constructor called" << std::endl;
}

// = operator overload
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
		Form::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Nothing specific to clean up yet in derived class" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	std::cout << "Something will happen here !" << std::endl;
}