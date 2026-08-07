class Solution {
public:
    int minElement(vector<int>& nums) {

   for(int i=0;i<nums.size();i++)
   {
      int x=nums[i];
   int s=0;
      while(x>0)
      {
         int d=x%10;
         s+=d;
         x=x/10;

      }
    nums[i]=s;


   }
  auto it=min_element(nums.begin(),nums.end());
  return (*it);
        
    }
};