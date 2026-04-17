class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int max1=0;
        int zeroc=0;

        for(;r<nums.size();r++){
            if(nums[r]==0)zeroc++;
            while(zeroc>k){
                if(nums[l]==0)zeroc--;
                l++;
            }
            max1=max(max1,r-l+1);
        }
        return max1;
    }
};