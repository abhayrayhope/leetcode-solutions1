class Solution {
public:
    bool checkPerfectNumber(int num) {

   int i=1;
   int sum=0;
   while(i<num)
   {
     if(num%i==0)
     {
        sum=sum+i;
     }
i++;
   }

   return num==sum;    
    }
};