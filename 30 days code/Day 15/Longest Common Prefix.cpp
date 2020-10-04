// This approach is using binary search
/*
  Find the string having the minimum length. Let this length be L.
  Perform a binary search on any one string (from the input array of strings). 
  Let us take the first string and do a binary search on the characters from the index – 0 to L-1.
  Initially, take low = 0 and high = L-1 and divide the string into two halves – left (low to mid) and right (mid+1 to high).
  Check whether all the characters in the left half is present at the corresponding indices (low to mid) of all the strings or not. 
  If it is present then we append this half to our prefix string and we look in the right half in a hope to find a longer prefix.
  (It is guaranteed that a common prefix string is there.)
  Otherwise, if all the characters in the left half is not present at the corresponding indices (low to mid) in all the strings, 
  then we need not look at the right half as there is some character(s) in the left half itself which is not a part of the longest prefix string. 
  So we indeed look at the left half in a hope to find a common prefix string. (It may be possible that we don’t find any common prefix string)
*/
// Code
 
 // A C++ Program to find the longest common prefix 
#include<bits/stdc++.h> 
using namespace std; 

// A Function to find the string having the minimum 
// length and returns that length 
int findMinLength(string arr[], int n) 
{ 
	int min = INT_MAX; 

	for (int i=0; i<=n-1; i++) 
		if (arr[i].length() < min) 
			min = arr[i].length(); 
	return(min); 
} 

bool allContainsPrefix(string arr[], int n, string str, 
					int start, int end) 
{ 
	for (int i=0; i<=n-1; i++) 
		for (int j=start; j<=end; j++) 
			if (arr[i][j] != str[j]) 
				return (false); 
	return (true); 
} 

// A Function that returns the longest common prefix 
// from the array of strings 
string commonPrefix(string arr[], int n) 
{ 
	int index = findMinLength(arr, n); 
	string prefix; // Our resultant string 

	// We will do an in-place binary search on the 
	// first string of the array in the range 0 to 
	// index 
	int low = 0, high = index; 

	while (low <= high) 
	{ 
		// Same as (low + high)/2, but avoids overflow 
		// for large low and high 
		int mid = low + (high - low) / 2; 

		if (allContainsPrefix (arr, n, arr[0], low, mid)) 
		{ 
			// If all the strings in the input array contains 
			// this prefix then append this substring to 
			// our answer 
			prefix = prefix + arr[0].substr(low, mid-low+1); 

			// And then go for the right part 
			low = mid + 1; 
		} 

		else // Go for the left part 
			high = mid - 1; 
	} 

	return (prefix); 
} 

// Driver program to test above function 
int main() 
{ 
	string arr[] = {"geeksforgeeks", "geeks", 
					"geek", "geezer"}; 
	int n = sizeof (arr) / sizeof (arr[0]); 

	string ans = commonPrefix(arr, n); 

	if (ans.length()) 
		cout << "The longest common prefix is "
			<< ans; 
	else
		cout << "There is no common prefix"; 
	return (0); 
} 

// Another Approach is by word to word matching
/*
  LCP(string1, string2, string3) 
         = LCP (LCP (string1, string2), string3)

Like here

LCP (“geeksforgeeks”, “geeks”, “geek”)
     =  LCP (LCP (“geeksforgeeks”, “geeks”), “geek”)
     =  LCP (“geeks”, “geek”) = “geek”
*/

//  Code
  // A C++ Program to find the longest common prefix 
#include<bits/stdc++.h> 
using namespace std; 

// A Utility Function to find the common prefix between 
// strings- str1 and str2 
string commonPrefixUtil(string str1, string str2) 
{ 
	string result; 
	int n1 = str1.length(), n2 = str2.length(); 

	// Compare str1 and str2 
	for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++) 
	{ 
		if (str1[i] != str2[j]) 
			break; 
		result.push_back(str1[i]); 
	} 

	return (result); 
} 

// A Function that returns the longest common prefix 
// from the array of strings 
string commonPrefix (string arr[], int n) 
{ 
	string prefix = arr[0]; 

	for (int i=1; i<=n-1; i++) 
		prefix = commonPrefixUtil(prefix, arr[i]); 

	return (prefix); 
} 

// Driver program to test above function 
int main() 
{ 
	string arr[] = {"geeksforgeeks", "geeks", 
					"geek", "geezer"}; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	string ans = commonPrefix(arr, n); 

	if (ans.length()) 
		printf ("The longest common prefix is - %s", 
				ans.c_str()); 
	else
		printf("There is no common prefix"); 

	return (0); 
} 
// Another is matching particular char at given index in every string

// code
// A C++ Program to find the longest common prefix 
#include<bits/stdc++.h> 
using namespace std; 

// A Function to find the string having the minimum 
// length and returns that length 
int findMinLength(string arr[], int n) 
{ 
	int min = arr[0].length(); 

	for (int i=1; i<n; i++) 
		if (arr[i].length() < min) 
			min = arr[i].length(); 

	return(min); 
} 

// A Function that returns the longest common prefix 
// from the array of strings 
string commonPrefix(string arr[], int n) 
{ 
	int minlen = findMinLength(arr, n); 

	string result; // Our resultant string 
	char current; // The current character 

	for (int i=0; i<minlen; i++) 
	{ 
		// Current character (must be same 
		// in all strings to be a part of 
		// result) 
		current = arr[0][i]; 

		for (int j=1 ; j<n; j++) 
			if (arr[j][i] != current) 
				return result; 

		// Append to result 
		result.push_back(current); 
	} 

	return (result); 
} 

// Driver program to test above function 
int main() 
{ 
	string arr[] = {"geeksforgeeks", "geeks", 
					"geek", "geezer"}; 
	int n = sizeof (arr) / sizeof (arr[0]); 

	string ans = commonPrefix (arr, n); 

	if (ans.length()) 
		cout << "The longest common prefix is "
			<< ans; 
	else
		cout << "There is no common prefix"; 
	return (0); 
} 

// Using Divide conquere

// Code
  // A C++ Program to find the longest common prefix 
#include<bits/stdc++.h> 
using namespace std; 

// A Utility Function to find the common prefix between 
// strings- str1 and str2 
string commonPrefixUtil(string str1, string str2) 
{ 
	string result; 
	int n1 = str1.length(), n2 = str2.length(); 

	for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++) 
	{ 
		if (str1[i] != str2[j]) 
			break; 
		result.push_back(str1[i]); 
	} 
	return (result); 
} 

// A Divide and Conquer based function to find the 
// longest common prefix. This is similar to the 
// merge sort technique 
string commonPrefix(string arr[], int low, int high) 
{ 
	if (low == high) 
		return (arr[low]); 

	if (high > low) 
	{ 
		// Same as (low + high)/2, but avoids overflow for 
		// large low and high 
		int mid = low + (high - low) / 2; 

		string str1 = commonPrefix(arr, low, mid); 
		string str2 = commonPrefix(arr, mid+1, high); 

		return (commonPrefixUtil(str1, str2)); 
	} 
} 

// Driver program to test above function 
int main() 
{ 
	string arr[] = {"geeksforgeeks", "geeks", 
					"geek", "geezer"}; 
	int n = sizeof (arr) / sizeof (arr[0]); 

	string ans = commonPrefix(arr, 0, n-1); 

	if (ans.length()) 
		cout << "The longest common prefix is "
			<< ans; 
	else
		cout << "There is no common prefix"; 
	return (0); 
} 

// Using Trie 
/*
	Insert all the words one by one in the trie. After inserting we perform a walk on the trie.
	In this walk, go deeper until we find a node having more than 1 children(branching occurs) or 0 children (one of the string gets exhausted).
	This is because the characters (nodes in trie) which are present in the longest common prefix must be the single child of its parent, 
	i.e- there should not be branching in any of these nodes.
*/

// Code
	// A Program to find the longest common 
// prefix of the given words 

#include<bits/stdc++.h> 
using namespace std; 

// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (26) 

// Converts key current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

// Trie node 
struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 

	// isLeaf is true if the node represents 
	// end of a word 
	bool isLeaf; 
}; 

// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 

	if (pNode) 
	{ 
		int i; 

		pNode->isLeaf = false; 

		for (i = 0; i < ALPHABET_SIZE; i++) 
			pNode->children[i] = NULL; 
	} 

	return pNode; 
} 

// If not present, inserts the key into the trie 
// If the key is a prefix of trie node, just marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
	int length = key.length(); 
	int index; 

	struct TrieNode *pCrawl = root; 

	for (int level = 0; level < length; level++) 
	{ 
		index = CHAR_TO_INDEX(key[level]); 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	// mark last node as leaf 
	pCrawl->isLeaf = true; 
} 

// Counts and returns the number of children of the 
// current node 
int countChildren(struct TrieNode *node, int *index) 
{ 
	int count = 0; 
	for (int i=0; i<ALPHABET_SIZE; i++) 
	{ 
		if (node->children[i] != NULL) 
		{ 
			count++; 
			*index = i; 
		} 
	} 
	return (count); 
} 

// Perform a walk on the trie and return the 
// longest common prefix string 
string walkTrie(struct TrieNode *root) 
{ 
	struct TrieNode *pCrawl = root; 
	int index; 
	string prefix; 

	while (countChildren(pCrawl, &index) == 1 && 
			pCrawl->isLeaf == false) 
	{ 
		pCrawl = pCrawl->children[index]; 
		prefix.push_back('a'+index); 
	} 
	return (prefix); 
} 

// A Function to construct trie 
void constructTrie(string arr[], int n, struct TrieNode *root) 
{ 
	for (int i = 0; i < n; i++) 
		insert (root, arr[i]); 
	return; 
} 

// A Function that returns the longest common prefix 
// from the array of strings 
string commonPrefix(string arr[], int n) 
{ 
	struct TrieNode *root = getNode(); 
	constructTrie(arr, n, root); 

	// Perform a walk on the trie 
	return walkTrie(root); 
} 

// Driver program to test above function 
int main() 
{ 
	string arr[] = {"geeksforgeeks", "geeks", 
					"geek", "geezer"}; 
	int n = sizeof (arr) / sizeof (arr[0]); 

	string ans = commonPrefix(arr, n); 

	if (ans.length()) 
		cout << "The longest common prefix is "
			<< ans; 
	else
		cout << "There is no common prefix"; 
	return (0); 
} 
