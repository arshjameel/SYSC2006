/* array_pointers.c - SYSC 2006 Lab 5 */

#include <stdlib.h>  
#include <stdio.h>   

#include "array_pointers.h"


// Exercise 1

/* Return the maximum value in the first n elements of array of integers, ar. 
   If n is less than or equal to 0, it returns 0.  
   This function uses array indices.  Do not change this function. */
int find_max_v0(const int ar[], int n) {
	int max;
	if (n <= 0) {
		return 0; // ensure we proceed only if n is reasonable
	}
	max = ar[0];
	for (int i = 1; i < n; i++) {
		if (ar[i] > max) {
			max = ar[i];
		}
	}
	return max;
}

/* Return the maximum value in the first n elements of an array of integers. 
   If n is less than or equal to 0, it returns 0.  
   This function uses a pointer to an array. */
int find_max_v1(const int *arp, int n) {
	int max;
	if (n <= 0) {
		return 0; // ensure we proceed only if n is reasonable
	}
	max = *arp;
	for (int i = 1; i < n; i++) {
		if (*(arp+i)>max) {
			max = *(arp+i);
		}
	}
	return max;
}

/* Return the maximum value in the first n elements of an array of integers. 
   If n is less than or equal to 0, it returns 0.  
   This function uses a walking pointer to the array. */
int find_max_v2(const int *arp, int n) {
	int max;
	if (n <= 0) {
		return 0; // ensure we proceed only if n is reasonable
	}
	max = *arp;
	const int *p = arp;
	for (int i = 1; i < n; i++) {
		if (*p > max) {
			max = *p;
		}
		p++;
	}
	return max;
}

// Exercise 2
/* Return the count of the number of times target occurs in the first 
 * n elements of array a.
 */
int count_in_array(int a[], int n, int target)
{
	//code implementation with for loop:

	//	int sum = 0;
	//	for (int i = 0; i < n; i++) {
	//		if (a[i] == target) {
	//			sum++;
	//		}
	//	}
	//	return sum;

	//code implementation without any loops:

    if (n == 0) {	//if no elements left in the array, return 0 to terminate program
        return 0;	
    }

	else {
		int sum = 0;	//define a variable
		if (a[0] == target) {
			sum++;	//increment value by 1 if a[0] == target
		}
		else {
			sum = 0; //dont change value of sum if a[0] != target
		}
		return sum + count_in_array(a + 1, n - 1, target);	//recursive call to replace the need for a loop
	}	
}

// Exercise 3
/* Return true if the first n elements in arr1 and arr2 are equal
and return false otherwise*/
_Bool array_compare(int arr1[], int arr2[], int n){
	if (n == 0) {	//if no elements in the array, return 0 to terminate program
		return 0;
    } else {
		if (arr1[0] == arr2[0]) {
			n = n - 1;
		} else {
			return 0;
		}

		if (n == 0) {	//if no elements left in the array, return 0 to terminate program
        	return 1;	
    	} 
		else {
			array_compare(arr1 + 1, arr2 + 1, n);	//recursive call to replace the need for a loop
		}
	}
}