class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int score=1;
        int cand=nums[0];
        for(int num:nums){
            if(score==0){
               cand=num;
               score++;
            }
            else{
                if(cand==num)score++;
                else score--;
            }
        }
        return cand;
    }
};