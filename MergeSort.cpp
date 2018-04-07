#include "stdafx.h"
#include "MergeSort.h"


void merge(vector<int>& v, int low, int middle, int high) {

	int sizeLeft = middle - low + 1;
	int sizeRight = high - middle;

	/* We copy the values from the left & right parts in temporary vectors */
	vector<int> leftPart;
	vector<int> rightPart;
	for (int i = 0; i < sizeLeft; i++) {
		leftPart.push_back(v[low + i]);
	}
	for (int j = 0; j < sizeRight; j++) {
		rightPart.push_back(v[middle + 1 + j]);
	}

	/* We put in the original vector the values in sorted order */

	int indexLeft = 0;
	int indexRight = 0;
	int indexMerged = low;

	/* While there are values in the left and right parts, we compare them and add the smaller ones first */
	while (indexLeft < sizeLeft & indexRight < sizeRight) {
		if (leftPart[indexLeft] <= rightPart[indexRight]) {
			v[indexMerged] = leftPart[indexLeft];
			indexLeft++;
		}
		else {
			v[indexMerged] = rightPart[indexRight];
			indexRight++;
		}
		indexMerged++;
	}

	/* When we've gone through all the values in at least one vector, we check if there are some left in the other vector to add them */
	while (indexLeft < sizeLeft) {
		v[indexMerged] = leftPart[indexLeft];
		indexLeft++;
		indexMerged++;
	}
	while (indexRight < sizeRight) {
		v[indexMerged] = rightPart[indexRight];
		indexRight++;
		indexMerged++;
	}

}


void mergeSortUtil(vector<int>& v, int low, int high) {

	if (low < high) {

		int middle = (low + high) / 2;

		/* Divide & Conquer: we apply mergeSort on the left part of the subvector and on the right part of the subvector */
		mergeSortUtil(v, low, middle);
		mergeSortUtil(v, middle + 1, high);

		/* We merge the sorted parts */
		merge(v, low, middle, high);

	}

}


double mergeSort(vector<int>& v)
{
	clock_t tStart = clock();
	mergeSortUtil(v, 0, v.size()-1);
	return (double)(clock() - tStart);
}