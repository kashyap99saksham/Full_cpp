/*
  This is also a pattern matching algorithm 
  Here we prepare a LPS(longst prefix suffix) array of pattern and then use this array for matching on string 
  here when we get mismatch then we dont start from begining we dont move i(text index) we move j(pattern index) to last matches items and we get this by LPS
  Eg- Examples of lps[] construction:
      For the pattern “AAAA”, 
      lps[] is [0, 1, 2, 3]

      For the pattern “ABCDE”, 
      lps[] is [0, 0, 0, 0, 0]

      For the pattern “AABAACAABAA”, 
      lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]

      For the pattern “AAACAAAAAC”, 
      lps[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4] 

      For the pattern “AAABAAA”, 
      lps[] is [0, 1, 2, 0, 1, 2, 3]
      
      We start comparison of pat[j] with j = 0 with characters of current window of text.
      We keep matching characters txt[i] and pat[j] and keep incrementing i and j while pat[j] and txt[i] keep matching.
      When we see a mismatch
          We know that characters pat[0..j-1] match with txt[i-j…i-1] (Note that j starts with 0 and increment it only when there is a match).
          We also know (from above definition) that lps[j-1] is count of characters of pat[0…j-1] that are both proper prefix and suffix.
          From above two points, we can conclude that we do not need to match these lps[j-1] characters with txt[i-j…i-1] because we know that these characters will anyway match. 
          Let us consider above example to understand this.
          
*/

// Code
  // C++ program for implementation of KMP pattern searching 
// algorithm 
#include <bits/stdc++.h> 

void computeLPSArray(char* pat, int M, int* lps); 

// Prints occurrences of txt[] in pat[] 
void KMPSearch(char* pat, char* txt) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 

	// create lps[] that will hold the longest prefix suffix 
	// values for pattern 
	int lps[M]; 

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(pat, M, lps); 

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
			printf("Found pattern at index %d ", i - j); 
			j = lps[j - 1]; 
		} 

		// mismatch after j matches 
		else if (i < N && pat[j] != txt[i]) { 
			// Do not match lps[0..lps[j-1]] characters, 
			// they will match anyway 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
} 

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
	// length of the previous longest prefix suffix 
	int len = 0; 

	lps[0] = 0; // lps[0] is always 0 

	// the loop calculates lps[i] for i = 1 to M-1 
	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else // (pat[i] != pat[len]) 
		{ 
			// This is tricky. Consider the example. 
			// AAACAAAA and i = 7. The idea is similar 
			// to search step. 
			if (len != 0) { 
				len = lps[len - 1]; 

				// Also, note that we do not increment 
				// i here 
			} 
			else // if (len == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

// Driver program to test above function 
int main() 
{ 
	char txt[] = "ABABDABACDABABCABAB"; 
	char pat[] = "ABABCABAB"; 
	KMPSearch(pat, txt); 
	return 0; 
} 
