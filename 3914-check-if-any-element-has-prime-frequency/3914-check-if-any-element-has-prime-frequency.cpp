class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        map<int,int> freq;
        for(auto i:nums)    freq[i]++;
        
        for(auto [m,n]:freq){
            bool pro=1;
            if(n==1)    pro=0;
            for(int i=2;i<n;i++){
                if(n%i==0)  pro=0;
            }
            cout<<m<<" "<<n<<endl;
            if(pro) return true;
        }
        return false;
    }
};