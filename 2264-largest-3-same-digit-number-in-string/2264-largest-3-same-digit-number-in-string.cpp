class Solution {
public:
    string largestGoodInteger(string num) {

        int i=num.size()-1;
       string m = "";
        while(i>=2)
        {
          if(num[i]==num[i-1]&&num[i-1]==num[i-2])
          {
            string y= num.substr(i-2, 3);

            m=max(m,y) ;
          }

i--;
        }


     return m;   
    }
};