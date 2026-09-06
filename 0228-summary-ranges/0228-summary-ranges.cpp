class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

   vector<string>s;
   if(nums.size()==0)
   {
    return s;
   }

   for(int i=0;i<nums.size();i++)
   {  
      if(i+1<nums.size()&&nums[i]+1==nums[i+1])
      {
         string s1="";
         s1+=to_string(nums[i]);
        
         int j=i;
         while(i+1<nums.size()&&nums[i]+1==nums[i+1])
         {
            i++;
           
         }
         if(j!=i)
         {
          s1+="->";
          
          s1+=to_string(nums[i]);
         }
       



         
 s.push_back(s1);
        
      }
      else { s.push_back(to_string(nums[i])); }

   }

    return s;    
    }
};