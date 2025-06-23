class Solution {
public:
    int divide(int dividend, int divisor) {
        long long D=dividend;
        long long d=divisor;
        bool neg=0;
        if(D<0) neg^=1;
        if(d<0) neg^=1;
        D=abs(D);
        d=abs(d);
        long long q=0;
        for(int i=30;i>=0;i--){
            long long t=(q+(1LL<<i))*1LL*d;
            if(t<=D){
                q+=(1LL<<i);
            }
        }
        if(neg) q=-q;
        if(neg) D=-D;
        if(D==INT_MIN){
            cout<<"YES"<<endl;
            if(d==-1)   return INT_MAX;
            if(d==1)    return INT_MIN;
        }
        else if(D==INT_MAX){
            if(d==-1)   return INT_MIN;
            if(d==1)    return INT_MAX;
        }
        return q;
    }
};