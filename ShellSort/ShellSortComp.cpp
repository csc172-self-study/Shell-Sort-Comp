/*
 * ShellSortComp.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: alex
 */

#include "ShellSort.h"
#include <ctime>
#include <random>
#include <iostream>
using std::cout;

int main() {
	const int SIZE = 100000;

	clock_t start;

	std::random_device rd;
	std::mt19937 eng(rd());

	std::uniform_int_distribution<> posDistr(0,SIZE);

	int array[SIZE]; int array1[SIZE]; int array2[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		array[i] = posDistr(eng);
		array1[i] = array[i];
		array2[i] = array[i];
	}

	start = clock();
	ShellSort<int>(array1, SIZE, 2);
	double incr_2_sort_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

	start = clock();
	ShellSort<int>(array2, SIZE, 3);
	double incr_3_sort_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

	for (int i = 1; i < SIZE; ++i) {
		if (array1[i] < array1[i-1]) {
			cout << "Array1 was sorted incorrectly.\n";
		}
		if (array2[i] < array2[i-1]) {
			cout << "Array2 was sorted incorrectly.\n";
		}
	}

	cout << "Increments of 2 took " << incr_2_sort_time << " s.\n";
	cout << "Increments of 3 took " << incr_3_sort_time << " s.\n";
}


