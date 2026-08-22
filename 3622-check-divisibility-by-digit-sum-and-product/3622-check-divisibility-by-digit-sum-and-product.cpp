class Solution {
public:
    bool checkDivisibility(int n) {
   int x=n;
    int sum=0;
    int p=1;

    while(x>0)
    {
        int d=x%10;
        sum+=d;
        p*=d;
        x=x/10;
    }
int s=p+sum;

if(n%s==0){
return true;}

return false;
        
    }
};