#include "Bureaucrat.hpp"

try
{
/* do some stuff with bureaucrats */
}
catch (std::exception & e)
{
/* handle exception */
}


std::ostream &operator << (std::ostream &c_out, const Bureaucrat &bur)
{
	c_out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
	return (c_out);
}