class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       vector<int> remainder_count(k,0);
       remainder_count[0]=1;
       int Prefix_sum=0;
       int  count=0;
       for(int num:nums){
        Prefix_sum += num;
        int rem = (Prefix_sum%k + k)% k;
        count += remainder_count[rem];
        remainder_count[rem]++;    
        } 
        return count;
    }
};