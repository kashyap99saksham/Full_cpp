/*
  Given a collection of intervals, merge all overlapping intervals.
  Input: [[1,3],[2,6],[8,10],[15,18]]
  Output: [[1,6],[8,10],[15,18]]
  Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
  Input: [[1,4],[4,5]]
  Output: [[1,5]]
  Explanation: Intervals [1,4] and [4,5] are considered overlapping.
  
  */
  
  // CODE
      

      bool comp(vector<int> v1, vector<int> v2){
          return v1[0] < v2[0];
      }
  
      vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(!n)return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        int index = 0;
        for(int i = 1; i<n; i++)
            if(intervals[index][1] > intervals[i][0]-1){
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
                intervals[index][0] = min(intervals[index][0], intervals[i][0]);
            }
            else{
                intervals[++index] = intervals[i];
            }
        vector<vector<int> > result;
        for(int i = 0; i<index+1; i++){
            result.push_back(intervals[i]);
        }
        return result;
    }
