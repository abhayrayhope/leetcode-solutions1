class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int N=nums.size();
        int i=0;
        vector<int>n=nums;
        sort(n.begin(),n.end());

        if(nums==n)
        {
            return 0;
        }

        while(i<=(i+1)%N)
        {
             rotate(nums.begin(),nums.end()-1,nums.end());
               i++;
             if(nums==n)
             {
                return i;
             }



        } 



return -1;
    }
};