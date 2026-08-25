class Solution {
public:
    int maxOperations(vector<int>& nums) {
int n=nums.size();
   if(n<=3)
   {
    return 1;
   }
int s=accumulate(nums.begin() , nums.begin() +2, 0);

nums.erase(nums.begin(), nums.begin() + 2);
int c=1;
while(nums.size()>=2)
{
    if(accumulate(nums.begin() , nums.begin() +2, 0)==s)
    {
        nums.erase(nums.begin(), nums.begin() + 2);
        c++;
    }
else {
    return c;
}

}


    return c;    
    }
};