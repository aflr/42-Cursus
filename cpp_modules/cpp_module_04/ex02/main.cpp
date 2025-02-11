/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:31:48 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/08 13:26:53 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>
#include <iomanip>

const std::string IDEAS[100] = {
    "1: Puma american bobtail but bobcat kitty and ocicat or mouser.",
    "2: Siberian tomcat siamese but leopard for savannah.",
    "3: Mouser panther yet abyssinian and thai and tomcat.",
    "4: Kitten turkish angora manx bombay yet leopard but ragdoll for birman.",
    "5: Mouser siamese kitten.",
    "6: Munchkin thai and lynx lynx for tomcat birman.",
    "7: Bobcat leopard and norwegian forest bombay.",
    "8: American shorthair bengal siberian.",
    "9: Turkish angora thai egyptian mau and malkin birman singapura siamese.",
    "10: Grimalkin leopard but jaguar siamese.",
    "11: Balinese malkin bobcat balinese.",
    "12: Cougar sphynx, and munchkin for panther, siberian yet lynx.",
    "13: Manx bengal so leopard abyssinian tom, for norwegian forest thai.",
    "14: Donskoy persian norwegian forest egyptian mau.",
    "15: Cheetah lion egyptian mau british shorthair, leopard.",
    "16: Thai munchkin ocicat, so siberian.",
    "17: Turkish angora egyptian mau and bombay malkin bombay yet balinese malkin.",
    "18: Scottish fold bengal tom ocelot.",
    "19: Savannah lion yet tabby malkin persian kitten.",
    "20: Tabby tiger for kitty and devonshire rex savannah birman.",
    "21: Norwegian forest puma yet british shorthair.",
    "22: Himalayan turkish angora cheetah singapura, manx bobcat.",
    "23: Tom tiger but jaguar and tom so himalayan bengal.",
    "24: Havana brown jaguar ocicat or american bobtail for leopard british shorthair sphynx.",
    "25: Cheetah devonshire rex, american bobtail siberian birman egyptian mau havana brown.",
    "26: Cougar malkin turkish angora siamese singapura, lion.",
    "27: Kitten lion and american bobtail sphynx or manx.",
    "28: Ocelot tabby kitten cornish rex.",
    "29: British shorthair sphynx tomcat for ragdoll for cornish rex birman.",
    "30: Burmese egyptian mau for thai for lynx so kitten.",
    "31: Persian norwegian forest for balinese , panther donskoy but siamese.",
    "32: American bobtail donskoy so norwegian forest kitty.",
    "33: Manx mouser turkish angora but ocelot, but havana brown.",
    "34: Donskoy devonshire rex.",
    "35: Birman british shorthair cornish rex lynx egyptian mau, lion.",
    "36: Kitten birman cheetah scottish fold cheetah or abyssinian .",
    "37: Singapura bobcat ocicat ocicat.",
    "38: Birman turkish angora and birman.",
    "39: Cougar panther or american shorthair.",
    "40: Lion russian blue, yet turkish angora, panther devonshire rex or birman persian.",
    "41: Kitten maine coon tomcat panther, savannah.",
    "42: American bobtail grimalkin american shorthair or persian.",
    "43: Burmese leopard jaguar leopard tomcat.",
    "44: Ocelot lion for cheetah or havana brown or british shorthair.",
    "45: Donskoy himalayan or british shorthair and lion.",
    "46: British shorthair tom but american bobtail maine coon malkin but himalayan.",
    "47: Cougar ocelot mouser yet british shorthair, and tomcat for persian norwegian forest.",
    "48: Ragdoll bobcat, persian yet donskoy maine coon for cougar and cornish rex.",
    "49: Devonshire rex cheetah, manx for jaguar persian, for leopard.",
    "50: Russian blue ocelot so donskoy and leopard so kitty so siamese, for balinese .",
    "51: British shorthair ocicat so havana brown.",
    "52: Scottish fold tiger, tabby so norwegian forest himalayan and bobcat.",
    "53: Malkin ocelot lion and manx.",
    "54: Maine coon tiger panther cheetah cornish rex yet leopard.",
    "55: American bobtail american shorthair savannah, and ocicat.",
    "56: Siberian manx yet sphynx so kitten and bobcat.",
    "57: Persian kitten and birman, siamese scottish fold.",
    "58: British shorthair cougar, siamese.",
    "59: British shorthair egyptian mau.",
    "60: Kitten british shorthair, cheetah kitty puma and british shorthair panther.",
    "61: Sphynx tiger manx lion malkin and bombay tiger.",
    "62: Manx tomcat tiger or american shorthair and bengal.",
    "63: Savannah american shorthair yet abyssinian balinese so ocelot russian blue yet siamese.",
    "64: Savannah jaguar, for birman.",
    "65: Grimalkin manx siamese sphynx.",
    "66: Puma bombay kitten yet cheetah sphynx.",
    "67: Bombay panther for norwegian forest tabby for manx yet lion.",
    "68: Siamese ocelot cougar manx yet malkin tiger.",
    "69: Turkish angora havana brown, for ocelot siamese tom for bengal.",
    "70: Siberian cougar but kitten norwegian forest so havana brown siberian havana brown.",
    "71: Puma british shorthair or grimalkin, norwegian forest cornish rex manx.",
    "72: Burmese ragdoll havana brown, for maine coon bombay so bombay but bengal.",
    "73: Puma persian and malkin panther birman cougar.",
    "74: Maine coon thai for scottish fold for jaguar siberian siamese yet maine coon.",
    "75: Puma sphynx, so tabby, so himalayan.",
    "76: Tiger egyptian mau turkish angora, tiger so puma.",
    "77: Ocicat bobcat so lynx but munchkin.",
    "78: Ocicat leopard and tomcat norwegian forest munchkin yet abyssinian russian blue.",
    "79: Abyssinian egyptian mau siberian so ocicat for balinese .",
    "80: Donskoy devonshire rex yet siamese yet scottish fold but manx so russian blue.",
    "81: Persian havana brown kitten tom.",
    "82: Ocicat cougar so persian and tiger, jaguar or panther.",
    "83: Leopard sphynx yet mouser, scottish fold but havana brown.",
    "84: Scottish fold siamese, american bobtail burmese but thai ocelot.",
    "85: Donskoy tom, so abyssinian and scottish fold grimalkin.",
    "86: American shorthair cornish rex.",
    "87: Tabby lion yet tabby so havana brown yet balinese .",
    "88: Cheetah russian blue bombay for tabby ocelot so scottish fold.",
    "89: Sphynx american bobtail so scottish fold abyssinian and egyptian mau and tomcat thai.",
    "90: Cheetah manx, yet norwegian forest and cornish rex persian.",
    "91: Grimalkin scottish fold mouser turkish angora grimalkin, and norwegian forest yet lion.",
    "92: Munchkin puma so ragdoll jaguar.",
    "93: Thai egyptian mau british shorthair and jaguar kitten, puma singapura.",
    "94: Balinese scottish fold or grimalkin, so sphynx, yet bobcat and puma kitten.",
    "95: Turkish angora american shorthair for russian blue bombay puma so cheetah kitten.",
    "96: Cornish rex grimalkin cornish rex so cheetah and manx.",
    "97: Ocelot munchkin, donskoy cornish rex donskoy.",
    "98: Ragdoll leopard leopard.",
    "99: Munchkin tomcat, abyssinian american shorthair sphynx.",
    "100: Tabby grimalkin kitten, bobcat."
};

int main()
{
	std::cout << "\n TEST FROM SUBJECT \n" << std::endl;
	{
		const AAnimal *j = new Dog();
		const AAnimal *i = new Cat();

		i->makeSound();
		j->makeSound();
		delete j;
		delete i;
	}

	// Uncomment to test abstract class being impossible to instantiate
	std::cout << "\n ABSTRACT CLASS INSTANCE TEST \n" << std::endl;
	/*
	{
		const AAnimal* a = new AAnimal();
		a->makeSound();
		delete a;
	}
	*/

	std::cout << "\n FULL BRAIN & DEEP COPY TEST \n" << std::endl;
	{
		Dog *clifford = new Dog();
		Cat *cheshire = new Cat();

		std::cout << std::endl;

		for (long unsigned int i = 0; i < Brain::MAX_IDEAS; i++)
		{
			clifford->getBrain().addIdea(IDEAS[i]);
			cheshire->getBrain().addIdea(IDEAS[i]);
		}

		// Try to add one more idea, should not be added
		clifford->getBrain().addIdea("101: Overthinking");
		cheshire->getBrain().addIdea("101: Overthinking");

		std::cout << std::endl;

		// Deep copy
		Dog *chucho = new Dog(*clifford);

		std::cout << std::endl;

		delete clifford;
		delete cheshire;

		std::cout << std::endl;

		// Print all ideas
		for (long unsigned int i = 0; i < Brain::MAX_IDEAS; i++)
		{
			const std::string idea = chucho->getBrain().getIdea(i);
			if (idea.empty())
				continue;
			std::cout << std::setw(3) << (i + 1) << ": " << idea << std::endl;
		}
		// Try to print invalid ideas, should not print anything
		std::cout << chucho->getBrain().getIdea(Brain::MAX_IDEAS);
		std::cout << chucho->getBrain().getIdea(-1);

		std::cout << std::endl;

		delete chucho;
	}
	return (0);
}
