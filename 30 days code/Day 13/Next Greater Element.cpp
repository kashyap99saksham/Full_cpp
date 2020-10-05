/*
  Description : Given an array, print the Next Greater Element (NGE) for every element.
                The Next greater Element for an element x is the first greater element on the right side of x in array. 
                Elements for which no greater element exist, consider next greater element as -1.
  Input :       [4, 5, 2, 25]
  Output:       Element       NGE
                 4      -->   5
                 5      -->   25
                 2      -->   25
                 25     -->   -1
*/

//simple approach is to have two loops O(n2) and below is using stack O(n)
// Code
  void printNGE(int arr[], int n) { 
  stack < int > s; 
  
  /* push the first element to stack */
  s.push(arr[0]); 
  
  // iterate for rest of the elements 
  for (int i = 1; i < n; i++) { 
  
    if (s.empty()) { 
      s.push(arr[i]); 
      continue; 
    } 
  
    /* if stack is not empty, then 
       pop an element from stack. 
       If the popped element is smaller 
       than next, then 
    a) print the pair 
    b) keep popping while elements are 
    smaller and stack is not empty */
    while (s.empty() == false && s.top() < arr[i]) 
    {          
        cout << s.top() << " --> " << arr[i] << endl; 
        s.pop(); 
    } 
  
    /* push next to stack so that we can find 
    next greater for it */
    s.push(arr[i]); 
  } 
  
  /* After iterating over the loop, the remaining 
  elements in stack do not have the next greater 
  element, so print -1 for them */
  while (s.empty() == false) { 
    cout << s.top() << " --> " << -1 << endl; 
    s.pop(); 
  } 
}
