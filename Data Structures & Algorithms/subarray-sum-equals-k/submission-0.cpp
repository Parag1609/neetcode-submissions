class Solution {
public:
       
    int subarraySum(vector<int>& nums, int k) {
        map <long long,int>presumMap;
        presumMap[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
           sum+=nums[i];
           int rem=sum-k;
           if(presumMap.find(rem)!=presumMap.end()){
            count+=presumMap[rem];
           }
           presumMap[sum]++;
        }
        return count;
    }
};