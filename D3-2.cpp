class Solution {
public:
    void solve(vector<int>& candidates, int target,int i,
    vector<vector<int>> &ans,vector<int> &v)
    {
        if(target==0)
            {
            ans.push_back(v);
           // v.pop_back();
            return;
            }
        if(i==candidates.size())
        {
            return;
        }
        if(candidates[i]<=target )
        {
            v.push_back(candidates[i]);
            
            
            solve( candidates, target-candidates[i],i,ans,v);
            v.pop_back();
        }
        
             solve( candidates, target,i+1,ans,v);
        


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> v;
        solve( candidates, target,0,ans,v);
        return ans;
    }
};