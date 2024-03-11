#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

class AForm;

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &name, const int gradeToExecute, const int gradeToSign, const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &obj);
	ShrubberyCreationForm &operator = (const ShrubberyCreationForm &obj);
	ShrubberyCreationForm(const std::string &target);
	virtual ~ShrubberyCreationForm();

	const static int gradeToExeSC_;
	const static int gradeToSignSC_;

private:
	virtual void	executeConcreteAction() const;

	class CouldntOpenFile : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif //SHRUBBERY_CREATION_FORM_HPP
