class Solution {
public:
    vector<int> prime;
    vector<int> sieve(){
        prime[0]=prime[1]=0;
        for(int i=2;i*i<=100;i++){
            for(int j=i*2;j<=100;j+=i){
                prime[j]=0;
            }
        }
        return prime;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        map<int,int> freq;
        for(auto i:nums)    freq[i]++;
        prime.resize(101,1);
        sieve();
        for(auto [m,n]:freq){
            if(prime[n]==1) return true;
        }
        return false;
    }
};