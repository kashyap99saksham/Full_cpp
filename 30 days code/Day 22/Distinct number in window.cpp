/*
  simple approach is to make window of K size and find distinct element in that
  For every index i from 0 to len_array(n) – k, i.e n – k, traverse the array from i to i + k. This is the window
  Traverse the window, from i to that index and check if the element is present or not.
  If the element is not present in the prefix of the array, i.e no duplicate element is present from i to index-1, then increase the count.
  Print the count.
  O(n*k2) O(1)
*/
// code
  int countWindowDistinct(int win[], int k) 
{ 
    int dist_count = 0; 
  
    // Traverse the window 
    for (int i = 0; i < k; i++) { 
        // Check if element arr[i] exists in arr[0..i-1] 
        int j; 
        for (j = 0; j < i; j++) 
            if (win[i] == win[j]) 
                break; 
        if (j == i) 
            dist_count++; 
    } 
    return dist_count; 
} 
  
// Counts distinct elements in all windows of size k 
void countDistinct(int arr[], int n, int k) 
{ 
    // Traverse through every window 
    for (int i = 0; i <= n - k; i++) 
        cout << countWindowDistinct(arr + i, k) << endl; 
} 

/*
  Here we can use hash to keep which number are present in current window and size of hash will give the distinct count. on sliding if new element is already present then dont 
  do anything just slide and disctinct count remain same if new element dont exist then push this and remove last element
  O(n) O(n)
*/
// code
  void countDistinct(int arr[], int k, int n) 
{ 
    // Creates an empty hashmap hm 
    map<int, int> hm; 
  
    // initialize distinct element count for current window 
    int dist_count = 0; 
  
    // Traverse the first window and store count 
    // of every element in hash map 
    for (int i = 0; i < k; i++) { 
        if (hm[arr[i]] == 0) { 
            dist_count++; 
        } 
        hm[arr[i]] += 1; 
    } 
  
    // Print count of first window 
    cout << dist_count << endl; 
  
    // Traverse through the remaining array 
    for (int i = k; i < n; i++) { 
        // Remove first element of previous window 
        // If there was only one occurrence, then reduce distinct count. 
        if (hm[arr[i - k]] == 1) { 
            dist_count--; 
        } 
        // reduce count of the removed element 
        hm[arr[i - k]] -= 1; 
  
        // Add new element of current window 
        // If this element appears first time, 
        // increment distinct element count 
  
        if (hm[arr[i]] == 0) { 
            dist_count++; 
        } 
        hm[arr[i]] += 1; 
  
        // Print count of current window 
        cout << dist_count << endl; 
    } 
} 

// code for Count of subarrays having exactly K distinct elements
int atMostK(int arr[], int n, int k) 
{ 
  
    // To store the result 
    int count = 0; 
  
    // Left boundary of window 
    int left = 0; 
  
    // Right boundary of window 
    int right = 0; 
  
    // Map to keep track of number of distinct 
    // elements in the current window 
    map<int,int> map; 
    // Loop to calculate the count 
    while (right < n) { 
  
        // Calculating the frequency of each 
        // element in the current window 
        if (map.find(arr[right])==map.end()) 
            map[arr[right]]=0; 
        map[arr[right]]++; 
  
        // Shrinking the window from left if the 
        // count of distinct elements exceeds K 
        while (map.size() > k) { 
            map[arr[left]]= map[arr[left]] - 1; 
            if (map[arr[left]] == 0) 
                map.erase(arr[left]); 
            left++; 
        } 
  
        // Adding the count of subarrays with at most 
        // K distinct elements in the current window 
        count += right - left + 1; 
        right++; 
    } 
    return count; 
} 
  
// Function to return the count of subarrays 
// with exactly K distinct elements 
int exactlyK(int arr[], int n, int k) 
{ 
  
    // Count of subarrays with exactly k distinct 
    // elements is equal to the difference of the 
    // count of subarrays with at most K distinct 
    // elements and the count of subararys with 
    // at most (K - 1) distinct elements 
    return (atMostK(arr, n, k) - atMostK(arr, n, k - 1)); 
} 
