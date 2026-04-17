class Solution {
public:
    int mySqrt(int x) {
        int lo=0;
        int hi=x;
        int ans=0;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            long long a=mid*mid;
            if(a==x)return mid;
            else if(a<x){
                lo=mid+1;
                ans=mid;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
};