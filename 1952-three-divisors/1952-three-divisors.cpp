class Solution {
public:
    bool isThree(int n) {
 
 int x=1;
int c=0;
 while(x<=n)
 {
    if(n%x==0)
    { 
       c++;
    }

if(c>3)
return false;
x++;

 }
 if(c==3){
 return true;}

return false;
        
    }
};