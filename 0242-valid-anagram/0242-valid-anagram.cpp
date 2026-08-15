class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        return false;
         
         vector<char> S;
         

         for(char i:s)
         {
            S.push_back(i);
         }

       for(char i:t)
       {
          auto it=find(S.begin(),S.end(),i);
         if(it==S.end()){
         return false;}

         else{
            S.erase(it);
         }


       }


return true;
    }
};