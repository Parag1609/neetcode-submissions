class Solution {
public:
    int search(vector<int>& nums, int target) {
        int hi= nums.size()-1;
        int lo= 0;
        while(lo<=hi){
            int mid = hi+(lo-hi)/2;
            if(target==nums[mid])return mid;
            else if(target<nums[mid]) hi=mid-1;
            else lo=mid+1;
        }
        return -1;
    }
};
