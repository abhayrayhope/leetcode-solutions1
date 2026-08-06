class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {

long long m=0;
        long long x=0;
         for(int i=0;i<nums.size();i++)
         { for(int j=i+1;j<nums.size();j++){
            if(i!=j){
             x=((1LL*nums[i] * nums[j]) )/ ((1LL*gcd(nums[i], nums[j]))* (1LL*gcd(nums[i], nums[j])));}

             if(x>m)
             {
                 m=x;

             }




         }




         }


        
         return m;



    }
};