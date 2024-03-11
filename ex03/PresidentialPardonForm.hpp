#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

class AForm;

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &name, const int gradeToExecute, const int gradeToSign, const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &obj);
	PresidentialPardonForm &operator = (const PresidentialPardonForm &obj);
	PresidentialPardonForm(const std::string &target);
	virtual ~PresidentialPardonForm();

	const static int gradeToExePP_;
	const static int gradeToSignPP_;

private:
	virtual void	executeConcreteAction() const;
};

#endif //PRESIDENTIAL_PARDON_FORM_HPP
