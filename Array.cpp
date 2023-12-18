#include <stdio.h>

void importArr(int* arr, int* length) {
	for(int i = 0; i < *length; i++) {
		printf("\nEnter arr[%d] = ", i);
		scanf("%d", arr + i);
	}
}

void exportArr(int* arr, int* length) {
	for(int i = 0; i < *length; i++) {
		printf("\narr[%d] = %d", i, *(arr + i));
	}
}

void positiveElement(int* arr, int* length) {
	int sum = 0;
	for(int i = 0; i < *length; i++) {
		if(*(arr + i) > 0) {
			sum += *(arr + i);
			printf("%d\t", *(arr + i));
		}
	}
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;	
}

int findTheSecondLargesElement(int* arr, int* length) {
	int temp1 = *(arr + 0);
	for(int i = 1; i < *length; i++) {
		if(temp1 < *(arr + i)) {
			temp1 = *(arr + i);
		}
	}
	swap(&temp1, (arr + 0));
	int temp2 = *(arr + 1);
	for(int j = 1; j < *length; j++) {
		if(*(arr + j) > temp2) {
			temp2 = *(arr + j);
		}
	}
	return temp2;
}
int main(){
	int size;
    printf("NHập đi");
	scanf("%d", &size);
	int nums[size];
	importArr(nums, &size);
	exportArr(nums, &size);
	printf("\n");
	positiveElement(nums, &size);
	printf("\n%d", findTheSecondLargesElement(nums, &size));
}