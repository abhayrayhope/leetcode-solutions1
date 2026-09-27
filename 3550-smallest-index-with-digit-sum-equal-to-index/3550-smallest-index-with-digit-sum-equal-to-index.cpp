class Solution {
public:
    int smallestIndex(vector<int>& nums) {
      int l=nums.size()-1;

      for(int i=0;i<=l;i++)
      {
       
         int y=nums[i];
         int s=0;
         while(y>0)
         {
           s=s+y%10;
           y=y/10;
         }

    if(i==s)
    return i;
      }


return -1;
    }
};