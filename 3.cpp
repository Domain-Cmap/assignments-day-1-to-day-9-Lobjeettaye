class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;

        for(int i=0;i<nums1.size();i++)
        {
            int a=-1;
            int f=0;
            for(int j=0;j<nums2.size();j++)
            {
                if(nums2[j]==nums1[i])
                {
                    f=1;
                }
                if(f==1 && nums2[j]>nums1[i])
                {
                    a=nums2[j];
                    break;
                }
               
            }
            ans.push_back(a);
        }
         return ans;
    }
};