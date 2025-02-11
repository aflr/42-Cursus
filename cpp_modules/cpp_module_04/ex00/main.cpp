/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:31:48 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/08 23:26:35 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	std::cout << "\n TEST FROM SUBJECT \n" << std::endl;
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();
		// ...
		delete meta;
		delete j;
		delete i;
	}

	std::cout << "\n BASIC CLASS & INHERITANCE TEST \n" << std::endl;
	{
		Animal animal = Animal();
		Animal duck = Animal("Duck");
		Animal otherDuck = Animal(duck);

		Dog dog = Dog();
		Dog otherDog = Dog(dog);

		Cat cat = Cat();
		Cat otherCat = Cat(cat);

		animal.makeSound();
		duck.makeSound();
		otherDuck.makeSound();

		dog.makeSound();
		otherDog.makeSound();

		cat.makeSound();
		otherCat.makeSound();
	}

	std::cout << "\n WRONG TEST: NO POLYMORPHISM \n" << std::endl;
	{
		WrongAnimal *wrongAnimal = new WrongAnimal("Freak");
		WrongAnimal *wrongCat = new WrongCat(); // polymorphism

		wrongAnimal->makeSound();
		wrongCat->makeSound(); // no polymorphism
		delete wrongAnimal;
		delete wrongCat; // no polymorphism
	}
	return (0);
}
