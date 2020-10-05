// Approach 1 is to use sorting then return the element O(nlogn). this can be improved if we use quicksort and stop when pivot is Kth element in worst it ll be O(n2)  but O(n) on avg
// Other solution is to make heap max or min depending on problem and call extract K times O(n+Klogn)

/*
  Approach: The idea is to use the concept of Counting Sort. Below are the steps:
    Find the maximum element(say maxE) in the array and create an array(say freq[]) of length maxE + 1 and initialize it to zero.
    Loop through all the element in the given array and store the frequency of the element in freq[].
    Iterate over the array freq[] until we reach the Kth element.
    Print the Kth element reached in the above step.
    O(n) and O(largest element in array)
*/
// code
  int findKthSmallest(int arr[], int n, 
                    int k) 
{ 
  
    // Initialize the max Element as 0 
    int max = 0; 
  
    // Iterate arr[] and find the maximum 
    // element in it 
    for (int i = 0; i < n; i++) { 
  
        if (arr[i] > max) 
            max = arr[i]; 
    } 
  
    // Frequenncy array to store 
    // the frequencies 
    int counter[max + 1] = { 0 }; 
  
    // Counter variable 
    int smallest = 0; 
  
    // Counting the frequencies 
    for (int i = 0; i < n; i++) { 
        counter[arr[i]]++; 
    } 
  
    // Iterate through the freq[] 
    for (int num = 1; num <= max; num++) { 
  
        // Check if num is present 
        // in the array 
        if (counter[num] > 0) { 
  
            // Increment the counter 
            // with the frequency 
            // of num 
            smallest += counter[num]; 
        } 
  
        // Checking if we have reached 
        // the Kth smallest element 
        if (smallest >= k) { 
  
            // Return the Kth 
            // smallest element 
            return num; 
        } 
    } 
}
