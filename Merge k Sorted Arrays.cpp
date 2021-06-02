//https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
//exc time-0.46
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int>res;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>
        ,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<K;i++){
            pq.push({arr[i][0],{i,1}});
        }
        for(int i=0;i<K*K;i++){
            pair<int,pair<int,int>> temp=pq.top();
            pq.pop();
            res.push_back(temp.first);
            if(temp.second.second<K){
                temp.first=arr[temp.second.first][temp.second.second];
                temp.second.second=temp.second.second+1;
                 pq.push(temp);
            }
           
        }
        return res;
    }
