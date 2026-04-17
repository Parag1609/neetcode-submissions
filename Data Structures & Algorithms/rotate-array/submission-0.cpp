class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        int j=0;
        int d=k%size;
        vector <int>temp(d);
        for(int i=size-d;i<size;i++){
            temp[j]=nums[i];
            j++;
        }
        for(int i=size-1;i>=d;i--){
            nums[i]=nums[i-d];
        }
        for(int i=0;i<d;i++){
            nums[i]=temp[i];
        }


    }
};