// C++ program to find the maximum for each 
// and every contiguous subarray of size K 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find the maximum for each 
// and every contiguous subarray of size k 
void printKMax(int a[], int n, int k) 
{ 
	// If k = 1, print all elements 
	if (k == 1) { 
		for (int i = 0; i < n; i += 1) 
			cout << a[i] << " "; 
		return; 
	} 

	// Using p and q as variable pointers 
	// where p iterates through the subarray 
	// and q marks end of the subarray. 
	int p = 0, 
		q = k - 1, 
		t = p, 
		max = a[k - 1]; 

	// Iterating through subarray. 
	while (q <= n - 1) { 

		// Finding max 
		// from the subarray. 
		if (a[p] > max) 
			max = a[p]; 

		p += 1; 

		// Printing max of subarray 
		// and shifting pointers 
		// to next index. 
		if (q == p && p != n) { 
			cout << max << " "; 
			q++; 
			p = ++t; 

			if (q < n) 
				max = a[q]; 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	int a[] = { 1, 2, 3, 4, 5, 
				6, 7, 8, 9, 10 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	int K = 3; 

	printKMax(a, n, K); 

	return 0; 
} 
