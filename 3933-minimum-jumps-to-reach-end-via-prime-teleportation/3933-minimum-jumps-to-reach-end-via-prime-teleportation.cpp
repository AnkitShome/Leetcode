class Solution {
public:

    bool isPrime(int val){
        if(val<2)   return 0;
        for(int i=2;i*i<=val;i++){
            if(val%i==0)    return 0;
        }
        return 1;
    }

    int minJumps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> primes(n);

        for(int i=0;i<n;i++){
            int num=nums[i];
            for(int p=2;p*p<=num;p++){
                if(num%p==0){
                    primes[p].push_back(i);
                    while(num%p==0) num/=p;
                }
            }
            if(num>1)   primes[num].push_back(i);
        }

        vector<int> dist(n,-1);
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0]=0;

        while(!q.empty()){
            auto [idx,d]=q.front();
            q.pop();

            if(idx==n-1)  return d;

            //adj
            int num=nums[idx];
            int l=idx-1,r=idx+1;
            if(l>=0 and dist[l]==-1){
                q.push({l,d+1});
                dist[l]=d+1;
            }
            if(r<n and dist[r]==-1){
                q.push({r,d+1});
                dist[r]=d+1;
            }


            //prime
            if(!isPrime(num))   continue;

            auto it=primes.find(num);
            if(it==primes.end())    continue;

            for(auto x:it->second){
                if(dist[x]!=-1) continue;
                q.push({x,d+1});
                dist[x]=d+1;
            }
            primes.erase(num);

        }
        return n-1;
    }
};