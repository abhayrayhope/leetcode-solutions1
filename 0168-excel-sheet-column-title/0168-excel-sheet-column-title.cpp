class Solution {
public:
    string convertToTitle(int columnNumber) {
  string s="";

  while(columnNumber>0)
  { columnNumber--;

  int r=columnNumber%26;
  s+=('A'+r);
   columnNumber=columnNumber/26;

  }

reverse(s.begin(),s.end());

    return s;    
    }
};