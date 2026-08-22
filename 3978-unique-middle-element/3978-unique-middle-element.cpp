class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        
   int m=nums.size()/2;

   map<int,int>c;

   for(int i:nums)
   {
    c[i]++;
   }

if(c[nums[m]]==1){
   return true;}

   return false;
    }
};