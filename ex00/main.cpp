#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex00");
}

int main()
{
	{
		std::cout << "[test0] Animal" << std::endl;
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		//	Animal =>  WrongAnimal
		//	Cat => WrongCat
		std::cout << "[test1] WrongAnimal" << std::endl;
		const WrongAnimal *mw = new WrongAnimal();
		const WrongAnimal *iw = new WrongCat();
		iw->makeSound();
		mw->makeSound();
		delete mw;
		delete iw;
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test2] Default constructor" << std::endl;
		Cat cat0;
		Dog dog0;
		std::cout << cat0.getType() << std::endl;
		std::cout << dog0.getType() << std::endl;
		cat0.makeSound();
		dog0.makeSound();
		std::cout << "----------" << std::endl;

		std::cout << "[test3] Copy constructor" << std::endl;
		Cat cat1(cat0);
		Dog dog1(dog0);
		std::cout << cat1.getType() << std::endl;
		std::cout << dog1.getType() << std::endl;
		cat1.makeSound();
		dog1.makeSound();
		std::cout << "----------" << std::endl;

		std::cout << "[test4] Copy constructor" << std::endl;
		Cat &cat3a = cat0;
		Cat cat3 = cat3a;
		Dog &dog3a = dog0;
		Dog dog3 = dog3a;
		std::cout << cat3.getType() << std::endl;
		std::cout << dog3.getType() << std::endl;
		cat3.makeSound();
		dog3.makeSound();
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test5] Copy assignment & name constructor" << std::endl;
		Cat cat4 = Cat();
		Dog dog4 = Dog();
		std::cout << cat4.getType() << std::endl;
		std::cout << dog4.getType() << std::endl;
		cat4.makeSound();
		dog4.makeSound();
	}
	return (0);
}
