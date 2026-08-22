class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        
   int m=nums.size()/2;

  if(count(nums.begin(),nums.end(),nums[m])==1)
  return true;

  return false;
    }
};