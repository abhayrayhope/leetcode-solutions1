class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
 int c=0;
        
for(int i=0;i<nums.size();i++)
    {
        int x=0;
        int y=0;
        for(int j=i;j<nums.size();j++){
     if(nums[j]%2==0)
     {
         x++;
     }
else {
    y++;
}

        if(y>0 && (x*b)<=(a*y))
        {
          c++;
            
        }

        }
        
    }




  return c;      
        
    }
};