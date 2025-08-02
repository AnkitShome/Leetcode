class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n=basket1.size();
        unordered_map<int,int> mp,sp,total;

        for(auto i:basket1){
            mp[i]++;
            total[i]++;
        }
        for(auto i:basket2){
            sp[i]++;
            total[i]++;
        }

        int mini=1e9;
        for(auto i:total)   {
            mini=min(mini,i.first);
            if(i.second&1)  return -1;  
        }

        vector<int> fir;

        for(auto i:total){
            int x=i.first;
            int a=0,b=0;

            if(mp.find(x)!=mp.end())    a=mp[x];
            if(sp.find(x)!=sp.end())    b=sp[x];

            if(a==b)    continue;

            int diff=abs(a-b);
            for(int j=0;j<diff/2;j++){
                fir.push_back(x);
            }
        }

        sort(fir.begin(),fir.end());
        int max_swap=fir.size()/2;

        long long res=0;
        for(int i=0;i<max_swap;i++){
            res+=min(fir[i],2*mini);
        }
        return res;
    }
};