class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
    long long ans=0;
  int l=nums.size();
   sort(nums.begin(), nums.end(), [](int a, int b) {
    return abs(a) > abs(b);
});
    int i=0;
   if(l%2==0)
   {
      for(i=0;i<l/2;i++)
      {
        ans+=(nums[i]*nums[i]);
      }

   }

   else{
     
  for(i=0;i<=l/2;i++)
  {
    ans+=(nums[i]*nums[i]);
  }
   }
 for(int j=i;j<l;j++)
 {
    ans+=(-(nums[j]*nums[j]));
 }
 return ans;
   }
   
};