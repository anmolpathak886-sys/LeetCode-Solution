class Solution {
public:
    int trap(vector<int>& height) {
        int  n=height.size(),water=0;
        int LeftMax=0,  RightMax=0,maxheight=height[0],index=0;
       
       for(int i=1;i<n;i++){
        if(height[i]>maxheight){
            maxheight=height[i];
            index=i;
        }
       } 
       for(int i=0;i<index;i++){
        if(LeftMax>height[i])
        water += LeftMax-height[i];
        else 
        LeftMax = height[i];
       }
       for(int i=n-1;i>index;i--){
        if(RightMax>height[i])
        water += RightMax - height[i];
        else
        RightMax = height[i];
       }
       return water;
    }
    
};