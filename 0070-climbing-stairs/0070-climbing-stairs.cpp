class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
return n;
int f=1;
int s=2;
int c;
for(int i=3;i<=n;i++)
{
  c=f+s;
  f=s;
  s=c;
}

   return c; 
    }
};