#include <unistd.h> //for sleep
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat bob("Bob", 40);
    ShrubberyCreationForm shrubberyForm1; //default
    ShrubberyCreationForm shrubberyform2("Garden");
    ShrubberyCreationForm shrubberyform3(shrubberyform2);

    std::cout << shrubberyForm1;
    std::cout << shrubberyform2;
    std::cout << shrubberyform3;
    shrubberyForm1.execute(bob);
    return 0;
}
