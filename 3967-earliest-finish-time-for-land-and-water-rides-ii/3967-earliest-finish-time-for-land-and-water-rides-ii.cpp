class Solution {
public:

    int g(vector<pair<int,int>> &a,vector<pair<int,int>> &b){
        int n=a.size();
        vector<int> start(n);
        for(int i=0;i<n;i++)    start[i]=a[i].first;

        vector<int> pre(n),suf(n);

        pre[0]=a[0].second;
        for(int i=1;i<n;i++){
            pre[i]=min(pre[i-1],a[i].second);
        }

        suf[n-1]=a[n-1].first+a[n-1].second;
        for(int i=n-2;i>=0;i--){
            suf[i]=min(suf[i+1],a[i].first+a[i].second);
        }


        int res=INT_MAX;
        for(auto [startB,durB]:b){
            int finish=startB+durB;

            int it=lower_bound(start.begin(),start.end(),finish)-start.begin();

            if(it<n){
                res=min(res,suf[it]);
            }
            if(it>0 and a[it-1].first<=finish){
                res=min(res,finish+pre[it-1]);
            }
        }
        return res;
    }
    
    int f(vector<int>& land, vector<int>& landy, vector<int>& water, vector<int>& watery){
        int n=land.size();
        int m=water.size();
        vector<pair<int,int>> landRides(n),waterRides(m);
        for(int i=0;i<n;i++){
            landRides[i]=make_pair(land[i],landy[i]);
        }
        for(int i=0;i<m;i++){
            waterRides[i]=make_pair(water[i],watery[i]);
        }
        sort(landRides.begin(),landRides.end());
        sort(waterRides.begin(),waterRides.end());

        return min(g(landRides,waterRides),g(waterRides,landRides));
    }


    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>&     waterStartTime, vector<int>& waterDuration) {
        return f(landStartTime,landDuration,waterStartTime,waterDuration);
        
    }
};