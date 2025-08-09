class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count=0;
        if(n<0) return false;
        for(int i=0;i<32;i++){
            if((n&(1<<i))!=0)    count++;
        }
        if(count==1)    return true;
        return false;    
    }
};