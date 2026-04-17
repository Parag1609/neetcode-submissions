class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1=0;
        int i=0;
        while(i<nums.size()){
            int count1=0;
            while(nums[i]==1 && i<nums.size()){
                count1++;
                i++;
            }
            max1=max(max1,count1);
            i++;
        }
        return max1;
    }
};