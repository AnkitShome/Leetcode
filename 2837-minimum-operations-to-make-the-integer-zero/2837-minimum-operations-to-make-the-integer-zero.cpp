class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num1==0) return 0;

        long long ans=LLONG_MAX;
        for(int i=0;i<=60;i++){
            long long num=1LL*num1-(1LL*num2*1LL*i);
            if(num<=0)  continue;
            
            int bits=0;
            long long max_bits=0;
            for(int j=0;j<=60;j++){
                if(num & (1LL<<j))    {bits++;max_bits+=(1LL<<j);}
            }
            if(i>=bits and i<=max_bits) return i;
        }
        return -1;
    }
};

// num1=3 num2=-2
// 00101   

// x times num1-(num2+1<<i) i from 0 to 60

// so num1-x*num2 - E i<<1 where i is from 0 to 60 and total x times

// num1-x*num2-sum x times=0
// sum_x=num1-x*num2

// x=5


// 3-(-2)*5=13

// 1 1 0 1     3 to 13
// 8 4 0 1

// 2 2 0 1

// 0100
// 0100
// 0010
// 0010
// 0001



// 1001010

// 0 1 2 3 4 5 6
// 1 0 0 1 0 1 0
// 64      8    2