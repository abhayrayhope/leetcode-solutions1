class Solution {
public:
    int missingInteger(vector<int>& nums) {

   int sum=nums[0];
   
   for(int i=1;i<nums.size();i++)
   {
      if(nums[i]==(nums[i-1]+1))
      {
        sum=sum+nums[i];
      
      }
     else 
     {
        break;
     }
  

      }

sort(nums.begin(),nums.end());
 bool i=1;
  while(i)
  { 
    i=binary_search(nums.begin(),nums.end(),sum);
    if(i==0)
    {
        return sum;
    }
    sum++;
  }




return -1;
   

        
    }
};