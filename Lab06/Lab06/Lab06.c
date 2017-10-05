#include <stdio.h>
#include <stdlib.h>

//break into stats.h
int Min(int*, int);
int Max(int*, int);
double avg(int*, int);

//keep main function here
int main() {
	int* nums;
	int i, length;

	printf("Enter size of array:");
	scanf_s("%d", &length, sizeof(int));

	nums = malloc(length * sizeof(int));
	for (i = 0; i < length; i++) {
		printf("Enter a number : ");
		scanf_s("%d", nums + i, sizeof(nums + i));
	}

	printf("The min is : %d\n", Min(nums, length));
	printf("The max is : %d\n", Max(nums, length));
	printf("The average is : %.2lf\n", avg(nums, length));

	scanf_s(" ");
	return 0;
}

//break into stats.c
int Min(int *vals, int size) {
	int min = vals[0];
	int i;
	for (i = 1; i < size; i++) {
		if (vals[i] < min) {
			min = vals[i];
		}
	}

	return min;
}

int Max(int *vals, int size) {
	int max = vals[0];
	int i;
	for (i = 1; i < size; i++) {
		if (vals[i] > max) {
			max = vals[i];
		}
	}

	return max;

}

double avg(int *vals, int size) {
	int sum = 0;
	int i;
	for (i = 0; i < size; i++) {
		sum += vals[i];
	}

	return sum / (double)size;
}