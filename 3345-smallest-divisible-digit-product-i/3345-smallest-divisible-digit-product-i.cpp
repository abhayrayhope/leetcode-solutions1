class Solution {
public:
    int smallestNumber(int n, int t) {
        int x=n;
       
while(x>=n)
{   int y=x;
 int p=1;
    while(y>0)
    {
       int d=y%10;
     p=p*d;
      y=y/10;

    }
if(p%t==0)
{
    return x;
}
x++;

}
  
return -1;

        
    }
};