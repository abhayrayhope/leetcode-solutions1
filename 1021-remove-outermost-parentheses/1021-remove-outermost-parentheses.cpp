class Solution {
public:
    string removeOuterParentheses(string s) {
        string r="";
   int c=0;
        for(char &ch:s)
        {
            if(ch=='(')
            {
                if(c!=0){

                
                 r.push_back(ch) ; }
                c++;
               
            }
  else {
   c--;
   if(c!=0)
   {
    r.push_back(ch);
   }

  }

        }
return r;

    }
};