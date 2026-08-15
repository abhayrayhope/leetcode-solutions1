class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
 int n=nums.size();
 map<int, int> mp;
 vector<int>ans;

for(int x : nums)
{
    mp[x]++;
}

for(int i:nums)
{
   if(mp[i]>(n/3))
   {
    ans.push_back(i);
    mp[i]=-1;
   }

}

   return ans;     
    }
};