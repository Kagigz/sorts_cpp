#include "stdafx.h"
#include "quicksort.h"

/* Swaps 2 values */
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

/* Chooses a pivot, places all values inferior to the pivot to its left and all values superior to the pivot to its right */
int partition(vector<int>& v, int low, int high) {

	/* Arbitrary: we choose the last value as the pivot */
	int pivot = v[high];

	/* We create an imaginary wall: all values inferior to the pivot will go left of that wall, and all values superior to the right*/
	int wall = low - 1;

	/* We look at all the values in the vector and when one is inferior to the pivot, we shift the pivot to place the inferior value to its left */
	for (int i = low; i < high; i++) {
		if (v[i] <= pivot) {
			wall++;
			swap(&v[i], &v[wall]);
		}
	}

	/* We swap the pivot with the value right of the wall */
	swap(&v[wall + 1], &v[high]);

	/* We return the index of the pivot */
	return wall + 1;

}

void quickSortUtil(vector<int>& v, int low, int high) {

	if (low < high) {

		/* We get the index of a pivot with all inferior values to its left and superior values to its right */
		int p = partition(v, low, high);

		/* Divide & Conquer: we apply quickSort on the part left of the pivot and on the part right of the pivot */
		quickSortUtil(v, low, p - 1);
		quickSortUtil(v, p + 1, high);

	}

}


double quickSort(vector<int>& v)
{
	clock_t tStart = clock();
	quickSortUtil(v, 0, v.size()-1);
	return (double)(clock() - tStart);
}