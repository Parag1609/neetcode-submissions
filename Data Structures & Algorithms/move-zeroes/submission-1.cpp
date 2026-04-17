class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j=0;
        for(;i<nums.size()&&j<nums.size();i++){
            while(nums[j]!=0&&j<nums.size())j++;
            if(nums[i]!=0 &&j<nums.size()&&j<i){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};