class Solution {
public:
    int search(vector<int>& nums, int target) {
      //  sort(nums.begin(),nums.end());
        
        int s=0;
        int l=nums.size()-1;
        
        while(s<=l)
        {
            int mid=s + (l-s)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[s]<=nums[mid])
            {
                if(nums[mid]>target &&target>=nums[s])
                {
                    l=mid-1;
                }
                else
                {
                    s=mid+1;
                }
            }
            else
            {
                if(nums[mid]<target &&target<=nums[l])
                {
                    s=mid+1;
                }
                else
                {
                    l=mid-1;
                }
            }
        }
        return -1;
    }
};