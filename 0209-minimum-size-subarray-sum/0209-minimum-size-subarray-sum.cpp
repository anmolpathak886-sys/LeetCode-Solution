class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n=nums.size();
       int min_length=INT_MAX;
       int left =0;
       long long currentSum=0;
       for(int right=0;right<n;right++ ){
        currentSum += nums[right];
        while(currentSum>=target){
            min_length=min(min_length,right-left+1);
            currentSum -= nums[left];
            left++;
        }
       }
       return(min_length==INT_MAX)?0:min_length;
    }
};