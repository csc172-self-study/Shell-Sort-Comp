/*
 * ShellSort.h
 *
 *  Created on: Jul 22, 2019
 *      Author: alex
 */

#ifndef SHELLSORT_H_
#define SHELLSORT_H_

#include "ArrayOperations.h"

// Alternating isn't quite the right word either.
template <typename E>
void AlternatingInsertionSort(E array[], int size, int increment) {
	for (int i = increment; i < size; i += increment) {
		for (int j = i; j >= increment && array[j] < array[j - increment]; j -= increment) {
			swap(array, j, j - increment);
		}
	}
}

template <typename E>
void ShellSort(E array[], int size, int step) {
	for (int increment = size/step; increment > step; increment /= step) {
		for (int j = 0; j < increment; ++j) {
			AlternatingInsertionSort<E>(&array[j], size - j, increment);
		}
	}
	AlternatingInsertionSort<E>(array, size, 1);
}

#endif /* SHELLSORT_H_ */
