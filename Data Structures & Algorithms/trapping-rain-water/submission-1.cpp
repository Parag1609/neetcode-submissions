class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int lmax=0, rmax=0;
        int sum=0;
        while(i<=j){
            if(height[i]<=height[j]){
                if(lmax<height[i])lmax=height[i];
                else sum+=lmax-height[i] ;
                i++;
            }
            else{
                if(rmax<height[j])rmax=height[j];
                else sum+=rmax-height[j];
                j--;
            }

        }
        return sum;
    }
};
