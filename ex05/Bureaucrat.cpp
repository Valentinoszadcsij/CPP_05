#include "Bureaucrat.hpp"

//default constructor
Bureaucrat::Bureaucrat()  : _name("Unknown"), _grade(0)
{
 std::cout << "Default Bureaucrat constuctor called: name initialized to " << this->_name << "with grade set to " << this->_grade << std::endl;   
}

//constructor with parameters
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Parameter Bureaucrat constuctor called: name initialized to " << this->_name << " with grade set to " << this->_grade << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name)
{
	*this = copy;
	std::cout << "Copy Bureaucrat constructor called" << std::endl;
}

// = operator overload
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
		this->_grade = copy._grade;
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

//getter functions
std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

//member functions
void Bureaucrat::increaseGrade(int value)
{
	if (this->_grade - value < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = this->_grade - value;
}

void Bureaucrat::decreaseGrade(int value)
{
	if (this->_grade + value > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = this->_grade + value;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return (out);
}

//exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}