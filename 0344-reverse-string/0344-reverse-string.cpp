class Solution {
public:
    void reverseString(vector<char>& s) {

    int l=s.size()-1;

    int x=0;
    int e=l;

    while(x<e)
    {
       swap(s[x],s[e]);
       x++;
       e--;




    }


        
    }
};