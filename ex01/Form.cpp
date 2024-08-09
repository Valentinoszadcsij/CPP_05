#include "Form.hpp"

//default constructor
Form::Form()  : _name("Unknown"), _grade(0)
{
 std::cout << "Default Form constuctor called: name initialized to " << this->_name << "with grade set to " << this->_grade << std::endl;   
}