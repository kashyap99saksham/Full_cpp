/*
  Description : Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. 
                So the median is the mean of the two middle value.
  For example,
                [2,3,4], the median is 3
                [2,3], the median is (2 + 3) / 2 = 2.5
                Design a data structure that supports the following two operations:
                void addNum(int num) - Add a integer number from the data stream to the data structure.
                double findMedian() - Return the median of all elements so far.
  Example:
                addNum(1)
                addNum(2)
                findMedian() -> 1.5
                addNum(3) 
                findMedian() -> 2
  Follow up:
                If all integer numbers from the stream are between 0 and 100, how would you optimize it?
                If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
*/

// Approach 1 is simple just Store the numbers in a resize-able container. Every time you need to output the median, sort the container and output the median.
// O(nlogn) and O(n)
// Code 
  class MedianFinder {
    vector<int> store;

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        store.push_back(num);
    }

    // Returns the median of current data stream
    double findMedian()
    {
        sort(store.begin(), store.end());

        int n = store.size();
        return (n & 1 ? store[n / 2] : ((double) store[n / 2 - 1] + store[n / 2]) * 0.5);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 
 // Insertion Sort
 /*
  Keeping our input container always sorted (i.e. maintaining the sorted nature of the container as an invariant).
  We have to use insertion sort algorithm so that our container is always in sorted order. to search appropriate position binary search will be usefull.
  This method would work well when the amount of insertion queries is lesser or about the same as the amount of median finding queries.
  O(n) because of insertion and O(n)
*/
// Code
  class MedianFinder {
    vector<int> store; // resize-able container

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        if (store.empty())
            store.push_back(num);
        else
            store.insert(lower_bound(store.begin(), store.end(), num), num);     // binary search and insertion combined
    }

    // Returns the median of current data stream
    double findMedian()
    {
        int n = store.size();
        return n & 1 ? store[n / 2] : ((double) store[n / 2 - 1] + store[n / 2]) * 0.5;
    }
};

/*
    Heaps (or Priority Queues [1])
    If we could maintain two heaps in the following way:
      A max-heap to store the smaller half of the input numbers
      A min-heap to store the larger half of the input numbers
    This gives access to median values in the input: they comprise the top of the heaps!
    If the following conditions are met:
    Both the heaps are balanced (or nearly balanced)
    The max-heap contains all the smaller numbers while the min-heap contains all the larger numbers
    then we can say that:
      All the numbers in the max-heap are smaller or equal to the top element of the max-heap (let's call it xx)
      All the numbers in the min-heap are larger or equal to the top element of the min-heap (let's call it yy)
      Then xx and/or yy are smaller than (or equal to) almost half of the elements and larger than (or equal to) the other half. That is the definition of median elements.
    This leads us to a huge point of pain in this approach: balancing the two heaps!
    Algorithm
    Two priority queues:
      A max-heap lo to store the smaller half of the numbers
      A min-heap hi to store the larger half of the numbers
    The max-heap lo is allowed to store, at worst, one more element more than the min-heap hi. Hence if we have processed kk elements:

    If k = 2*n + 1 \quad (\forall \, n \in \mathbb{Z})k=2∗n+1(∀n∈Z), then lo is allowed to hold n+1n+1 elements, while hi can hold nn elements.
    If k = 2*n \quad (\forall \, n \in \mathbb{Z})k=2∗n(∀n∈Z), then both heaps are balanced and hold nn elements each.
    This gives us the nice property that when the heaps are perfectly balanced, the median can be derived from the tops of both heaps. Otherwise, the top of the max-heap lo holds the legitimate median.

    Adding a number num:

    Add num to max-heap lo. Since lo received a new element, we must do a balancing step for hi. So remove the largest element from lo and offer it to hi.
    The min-heap hi might end holding more elements than the max-heap lo, after the previous operation. We fix that by removing the smallest element from hi and offering it to lo.
    The above step ensures that we do not disturb the nice little size property we just mentioned.

    A little example will clear this up! Say we take input from the stream [41, 35, 62, 5, 97, 108]. The run-though of the algorithm looks like this:

    Adding number 41
    MaxHeap lo: [41]           // MaxHeap stores the largest value at the top (index 0)
    MinHeap hi: []             // MinHeap stores the smallest value at the top (index 0)
    Median is 41
    =======================
    Adding number 35
    MaxHeap lo: [35]
    MinHeap hi: [41]
    Median is 38
    
    O(logn) O(n)
*/

// code
  class MedianFinder {
    priority_queue<int> lo;                              // max heap
    priority_queue<int, vector<int>, greater<int>> hi;   // min heap

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        lo.push(num);                                    // Add to max heap

        hi.push(lo.top());                               // balancing step
        lo.pop();

        if (lo.size() < hi.size()) {                     // maintain size property
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        return lo.size() > hi.size() ? lo.top() : ((double) lo.top() + hi.top()) * 0.5;
    }
};

/*
  This is based on using self balancing BST like an AVL tree
  some very interesting properties. They maintain the tree's height to a logarithmic bound. Thus inserting a new element has reasonably good time performance. 
  The median always winds up in the root of the tree and/or one of its children
  The only problem remains keeping track of the median elements. That is easily solved with pointers! [2]
  We maintain two pointers: one for the lower median element and the other for the higher median element. When the total number of elements is odd, 
  both the pointers point to the same median element (since there is only one median in this case). When the number of elements is even, 
  the pointers point to two consecutive elements, whose mean is the representative median of the input.
  Algorithm
  Two iterators/pointers lo_median and hi_median, which iterate over the data multiset.
  While adding a number num, three cases arise:
    The container is currently empty. Hence we simply insert num and set both pointers to point to this element.
    The container currently holds an odd number of elements. This means that both the pointers currently point to the same element.
    If num is not equal to the current median element, then num goes on either side of it. Whichever side it goes, 
    the size of that part increases and hence the corresponding pointer is updated. 
    For example, if num is less than the median element, the size of the lesser half of input increases by 1 on inserting num. Thus it makes sense to decrement lo_median.
    If num is equal to the current median element, then the action taken is dependent on how num is inserted into data. 
    NOTE: In our given C++ code example, std::multiset::insert inserts an element after all elements of equal value. Hence we increment hi_median.
    The container currently holds an even number of elements. This means that the pointers currently point to consecutive elements.
      If num is a number between both median elements, then num becomes the new median. Both pointers must point to it.
      Otherwise, num increases the size of either the lesser or higher half of the input. 
      We update the pointers accordingly. It is important to remember that both the pointers must point to the same element now.
  finding the median is easy! It is simply the mean of the elements pointed to by the two pointers lo_median and hi_median.
  O(logn) O(n)
*/
// code
  class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator lo_median, hi_median;

public:
    MedianFinder()
        : lo_median(data.end())
        , hi_median(data.end())
    {
    }

    void addNum(int num)
    {
        const size_t n = data.size();   // store previous size

        data.insert(num);               // insert into multiset

        if (!n) {
            // no elements before, one element now
            lo_median = hi_median = data.begin();
        }
        else if (n & 1) {
            // odd size before (i.e. lo == hi), even size now (i.e. hi = lo + 1)

            if (num < *lo_median)       // num < lo
                lo_median--;
            else                        // num >= hi
                hi_median++;            // insertion at end of equal range
        }
        else {
            // even size before (i.e. hi = lo + 1), odd size now (i.e. lo == hi)

            if (num > *lo_median && num < *hi_median) {
                lo_median++;                    // num in between lo and hi
                hi_median--;
            }
            else if (num >= *hi_median)         // num inserted after hi
                lo_median++;
            else                                // num <= lo < hi
                lo_median = --hi_median;        // insertion at end of equal range spoils lo
        }
    }

    double findMedian()
    {
        return ((double) *lo_median + *hi_median) * 0.5;
    }
};

/*
  A much shorter (but harder to understand), one pointer version [3] of this solution is given below:
*/
// code
  class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator mid;

public:
    MedianFinder()
        : mid(data.end())
    {
    }

    void addNum(int num)
    {
        const int n = data.size();
        data.insert(num);

        if (!n)                                 // first element inserted
            mid = data.begin();
        else if (num < *mid)                    // median is decreased
            mid = (n & 1 ? mid : prev(mid));
        else                                    // median is increased
            mid = (n & 1 ? next(mid) : mid);
    }

    double findMedian()
    {
        const int n = data.size();
        return ((double) *mid + *next(mid, n % 2 - 1)) * 0.5;
    }
};

