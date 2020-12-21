/*
 * sorting.cpp
 *
 *  Created on: Dec. 20, 2020
 *      Author: duke
 *      Purpose: discover binarySearch, selectionSort, insertionSort, and so so so much more
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>

void printArray(int array[], int arraySize) { //displays the array to the console
	for (int i=0;i<arraySize;i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}


void populate(int array[], int arraySize, int randSize) {
	srand (time(NULL));

	for (int i=0;i<arraySize;i++) {
		array[i] = rand() % randSize;
	}
}


int binarySearch(int array[], int arraySize, int target) { //hehe binary search needs a sorted array
	int min{array[0]}, minIndex {0}, mid{0}, midIndex{0}, max{array[arraySize-1]}, maxIndex{arraySize-1};

	for (int i=0;i<arraySize;i++) {
		midIndex = (minIndex+(maxIndex-minIndex)/2);
		mid = array[midIndex];

		if (mid < target) {
			minIndex = midIndex;
//			std::cout << mid << " < " << target << std::endl;
		}
		if (mid > target) {
			maxIndex = midIndex;
//			std::cout << mid << " > " << target << std::endl;
		}
		if (mid == target) {
			std::cout << "Number (" << target << ") found at index " << midIndex+1 << std::endl;
			return midIndex;
		}
	}
	if (mid != target) {
		std::cout << "Number (" << target << ") not found in this array.";
	}
	return 0;
}


void selectionSort(int array[], int arraySize) {
	int unsortedMin {array[0]}, unsortedMinIndex{0}, sorted{0}, valueHolder{0};

	for (int i=0;i<arraySize;i++) {
		for (int j=(0+sorted);j<arraySize;j++) {
			if (array[j]<=unsortedMin) {
				unsortedMin = array[j];
				unsortedMinIndex = j;

			}
		}
		valueHolder = array[sorted];
		array[sorted] = unsortedMin;
		array[unsortedMinIndex] = valueHolder;

		sorted++;
		unsortedMin = array[sorted];

//		std::cout << unsortedMin << std::endl;
//		printArray(array,arraySize);
	}
}

void indexSwap() {

}

int main () {
	std::cout << "Hello there! :) \n";
	int binSize {25};
	int numSize {100};
	int targetValue {60};

	int numArray[binSize] = {0};

	printArray(numArray,binSize);
	populate(numArray,binSize,numSize);
	printArray(numArray,binSize);
	selectionSort(numArray,binSize);
	printArray(numArray,binSize);

	binarySearch(numArray,binSize,targetValue);


	return 0;
}




