class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int maxsum=nums[0];
        for(int num:nums){
            if(currsum<0)currsum=0;
            currsum+=num;
            maxsum=max(maxsum,currsum);
            
        }
        return maxsum;

    }
};
