/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:35:37 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/26 21:41:51 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include "Point.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define WHITE_CHECK_EMOJI "\xE2\x9C\x85"

static void test_one(Point const p1, Point const p2, Point const p3, Point const p4, bool expected) {
	assert(bsp(p1, p2, p3, p4) == expected);
	std::cout << WHITE_CHECK_EMOJI;
}

static void test_comb(Point const p1, Point const p2, Point const p3, Point const p4, bool expected) {
	test_one(p1, p2, p3, p4, expected);
	test_one(p1, p3, p2, p4, expected);
	test_one(p2, p1, p3, p4, expected);
	test_one(p2, p3, p1, p4, expected);
	test_one(p3, p1, p2, p4, expected);
	test_one(p3, p2, p1, p4, expected);
	std::cout << std::endl;
}

int main(void)
{
	// Vertices
	// Triangle can be seen graphically here: https://www.desmos.com/calculator/lh5eavdkno
	Point a(0.0f, 0.0f);
	Point b(4.0f, 0.0f);
	Point c(0.0f, 4.0f);

	Point p1(1.0f, 1.0f); // Inside

	Point p2(2.0f, 0.0f); // On edge
	Point p3(0.0f, 2.0f); // On edge
	Point p4(2.0f, 2.0f); // On edge

	Point p5(4.5f, 0.0f); // Outside
	Point p6(0.0f, 4.5f); // Outside
	Point p7(2.5f, 2.5f); // Outside

	// Print vertices of triangle
	std::cout << "Triangle vertices:"
			<< "\na: " << a
			<< "\nb: " << b
			<< "\nc: " << c
			<< "\n---------------------------------"
			<< std::endl;

	// Inside
	std::cout << "\n    TESTING POINTS INSIDE TRIANGLE" << std::endl;

	std::cout << "p1: " << p1 << std::endl;
	test_comb(a, b, c, p1, true);

	// On edge
	std::cout << "\n    TESTING POINTS ON EDGE OF TRIANGLE" << std::endl;

	std::cout << "p2: " << p2 << std::endl;
	test_comb(a, b, c, p2, false);

	std::cout << "p3: " << p3 << std::endl;
	test_comb(a, b, c, p3, false);

	std::cout << "p4: " << p4 << std::endl;
	test_comb(a, b, c, p4, false);

	// Outside
	std::cout << "\n    TESTING POINTS OUTSIDE TRIANGLE" << std::endl;

	std::cout << "p5: " << p5 << std::endl;
	test_comb(a, b, c, p5, false);

	std::cout << "p6: " << p6 << std::endl;
	test_comb(a, b, c, p6, false);

	std::cout << "p7: " << p7 << std::endl;
	test_comb(a, b, c, p7, false);

	// Is vertex
	std::cout << "\n    TESTING POINTS THAT ARE VERTICES" << std::endl;

	std::cout << "a: " << a << std::endl;
	test_comb(a, b, c, a, false);

	std::cout << "b: " << b << std::endl;
	test_comb(a, b, c, b, false);

	std::cout << "c: " << c << std::endl;
	test_comb(a, b, c, c, false);

	std::cout << GREEN "\nAll tests passed!" RESET << std::endl;
	return 0;
}
