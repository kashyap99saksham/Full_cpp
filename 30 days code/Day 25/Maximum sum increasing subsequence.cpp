/*
  Description : Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.
      Input:    The first line of input contains an integer T denoting the number of test cases. 
                The first line of each test case is N(the size of array). The second line of each test case contains array elements.
      Output:   For each test case print the required answer in new line.
  Constraints:
      1 ≤ T ≤ 100
      1 ≤ N ≤ 106
      1 ≤ Ai ≤ 106
  Example:
      Input:
                2
                7
                1 101 2 3 100 4 5
                4
                10 5 4 3
      Output:
                106
                10
      Explanation:
                Testcase 1: All the increasing subsequences are : (1,101); (1,2,3,100); (1,2,3,4,5). Out of these (1, 2, 3, 100) has maximum sum,i.e., 106.
*/
// we slightly need to change our dp approach
int maxSumIS(int arr[], int n)  
{  
    int i, j, max = 0;  
    int msis[n];  
  
    /* Initialize msis values  
    for all indexes */
    for ( i = 0; i < n; i++ )  
        msis[i] = arr[i];  
  
    /* Compute maximum sum values  
    in bottom up manner */
    for ( i = 1; i < n; i++ )  
        for ( j = 0; j < i; j++ )  
            if (arr[i] > arr[j] &&  
                msis[i] < msis[j] + arr[i])  
                msis[i] = msis[j] + arr[i];  
  
    /* Pick maximum of  
    all msis values */
    for ( i = 0; i < n; i++ )  
        if ( max < msis[i] )  
            max = msis[i];  
  
    return max;  
}  
