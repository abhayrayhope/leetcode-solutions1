class Solution {
public:
    int gcdOfOddEvenSums(int n) {

    int sum1=0;
    int sum2=0;
    for(int i=1;i<=2*n;i++)
    {
       if(i%2==0)
       {
        sum1=sum1+1;
       }
else{

    sum2=sum2+i;
}


    }
    
return gcd(sum2,sum1);

        
    }
};