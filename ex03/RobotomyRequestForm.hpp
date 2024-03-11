#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

class AForm;

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &name, const int gradeToExecute, const int gradeToSign, const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &obj);
	RobotomyRequestForm &operator = (const RobotomyRequestForm &obj);
	RobotomyRequestForm(const std::string &target);
	virtual ~RobotomyRequestForm();

	const static int gradeToExeRR_;
	const static int gradeToSignRR_;

private:
	virtual void	executeConcreteAction() const;
};

#endif //ROBOTOMY_REQUEST_FORM_HPP
