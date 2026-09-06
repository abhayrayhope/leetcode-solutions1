class Solution {
public:
    int titleToNumber(string columnTitle) {
   int a=0;

   for(char c:columnTitle)
   {
     a=a*26+(c-'A'+1);


   }


return a;
        
    }
};