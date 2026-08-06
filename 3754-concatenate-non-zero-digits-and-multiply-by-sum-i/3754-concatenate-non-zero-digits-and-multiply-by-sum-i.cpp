class Solution {
public:
    long long sumAndMultiply(int n) {

    long long y=n;
    long long x=0;
    long long s=0;
    long long  p=1;
    while(y>0)
    {  int d=y%10;
     
       if(d!=0)
       {
          x=p*d+x;
          s=s+d;
          p=p*10;

       }
     y=y/10;
    }
return x*s;
        
    }
};