class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        queue<int> q;
        vector<int> ans;
        int j=-1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<0)
            q.push(arr[i]);
            
            if(i<k-1)
            continue;
            j++;
            if(q.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(q.front());
                
            }
            if(arr[j]<0)
            q.pop();
            
            
        }
        return ans;
    }
};