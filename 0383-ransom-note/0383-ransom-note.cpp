class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
    
map<char, int> mp;

for(char c : magazine)
{
    mp[c]++;
}


for(int i:ransomNote)
{
    if(mp.find(i)==mp.end())
    {
        return false;

    }

    if(mp[i]==0)
    {
        return false;
    }


mp[i]--;
}

return true;

    }
};