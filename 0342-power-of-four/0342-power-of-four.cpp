class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)    return true;
        int count=0;
        int route=0;
        for(int i=31;i>=0;i--){
            if(!(n&(1<<i)) and route)  count++;
            else if(n&(1<<i))    {route++;}
        }   
        if(count%2==0 and count>0 and route==1)  return true;
        return false;
        
    }
};