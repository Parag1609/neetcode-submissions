class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size()-1;
         int res = nums.size();
        while(lo<=hi){
            int mid = hi+(lo-hi)/2;
            if(nums[mid]==target)return mid;
            else if (nums[mid]>target){
                
                hi=mid-1;
                res=mid;
                
            }
            else {
               lo=mid+1;
            }
        }
        return res;

    }
};