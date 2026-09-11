class Solution {
public:
    int totalNumbers(vector<int>& digits) {
   
   vector<int>a(10,0);
int ans=0;
   for(int i:digits)
   {
      a[i]++;

   }

for(int i=0;i<=9;i++)
{
  if(i%2!=0||a[i]<=0)
  continue;

a[i]--;

for(int k=0;k<=9;k++)
{
    if(a[k]<=0) continue;

    a[k]--;

  for(int j=1;j<=9;j++)
  {
    if(a[j]<=0) continue;

    ans++;
  }

a[k]++;
}
a[i]++;
}
      

   return ans;     
    }
};