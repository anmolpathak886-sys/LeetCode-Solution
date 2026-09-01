class Solution {
public:
   
        int shipWithinDays(vector<int>& weights, int days) {
      int maxWeight = 0;
        int totalWeight = 0;
       for (int weight : weights) {
            maxWeight = max(maxWeight, weight);
            totalWeight += weight;
        }
        int low = maxWeight; 
        int high = totalWeight; 
        int result = high;
        while(low<=high){
            int  mid=low+(high-low)/2;

            int daysNeeded=1;
            int currentWeight=0;
            for(int weight:weights){
                if(currentWeight+weight>mid){
                    daysNeeded++;
                    currentWeight=weight;
                }else{
                    currentWeight+=weight;
                }
            }
            if(daysNeeded<=days){
                result=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return result;

    }
};
