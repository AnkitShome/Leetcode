class Solution {
public:
    const long long mod=1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        map<int,long long> mp;
        long long total=0;
        for(auto p:points){
            mp[p[1]]++;
        }
        for(auto it:mp){
            total+=(it.second*(it.second-1))/2;
        }
        long long ans=0;
        for(auto [it,jt]:mp){
            long long self=(mp[it]*(mp[it]-1))/2;
            long long rem=total-self;
            long long con=((self%mod)*(rem%mod))%mod;
            ans=((ans%mod)+(con%mod))%mod;
        }
        long long inv2 = 500000004;
        return (int)((ans * inv2) % mod);
    }
};