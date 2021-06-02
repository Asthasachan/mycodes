//https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1#  exe-0.09
#include<queue>
pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
      //code here
    int range = INT_MAX;
    int min = INT_MAX, max = INT_MIN;
    int start, end;
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>>pq;
    for (int i = 0; i < k; i++) {
        // Store the first element
        pq.push({arr[i][0],{i,1}});
        
        if (arr[i][0] > max)
            max = arr[i][0];
    }

    while (1) {
        // Get the minimum element and store it in output
        pair<int,pair<int,int>> root = pq.top();
        pq.pop();
        min = root.first;

        if (range > max - min + 1) {
            range = max - min + 1;
            start = min;
            end = max;
        }

        if (root.second.second < n) {
            root.first = arr[root.second.first][root.second.second];
            root.second.second+= 1;
 
            // update max element
            if (root.first > max)
                max = root.first;
        }
 
        // break if we have reached end of any list
        else
            break;
 
        // Replace root with next element of list
        pq.push(root);
    }
 
    return {start,end};
      
}
