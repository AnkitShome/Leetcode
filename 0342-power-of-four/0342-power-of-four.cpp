class Solution {
public:
    bool isPowerOfFour(int n) {
        // if(n==1)    return true;
        // int count=0;
        // for(int i=0;i<32;i++){
        //     if(!(n&(1<<i)))  count++;
        //     else    break;
        // }   
        // if(count%2==0 and count>0)  return true;
        // return false;
        while(n){
            if(n%4==0)  n=n/4;
            else    break;
        }
        if(n==1)    return true;
        return false;
    }
};