class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

   int m=k;
   auto  it=max_element(nums.begin(), nums.end());
   int i=1;
   while(m<=*it)
   {
      m=k*i;

     if(find(nums.begin(),nums.end(),m)==nums.end())
     {
       return m;
     } 
 i++;

   }

     return k;   
    }
};