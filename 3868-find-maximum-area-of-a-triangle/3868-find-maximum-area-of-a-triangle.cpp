class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        int n=0;
        for(auto i:coords)  n=max({n,i[0],i[1]});
        
        map<int,set<int>> row,col;

        int minC=INT_MAX,maxC=0,minR=INT_MAX,maxR=0;

        for(auto x:coords){
            int r=x[0];
            int c=x[1];
            row[r].insert(c);
            col[c].insert(r);
            minC=min(minC,c);
            maxC=max(maxC,c);
            minR=min(minR,r);
            maxR=max(maxR,r);
        }

        long long area=0;

        for(auto rt:row){
            if(rt.second.size()<2) continue;
            int top=*rt.second.begin();
            int bot=*rt.second.rbegin();
            int w=abs(top-bot);
            int h=max(abs(rt.first-minR),abs(rt.first-maxR));
            area=max(area,1LL*w*h);
        }

        for(auto ct:col){
            if(ct.second.size()<2) continue;
            int top=*ct.second.begin();
            int bot=*ct.second.rbegin();
            int w=abs(top-bot);
            int h=max(abs(ct.first-minC),abs(ct.first-maxC));
            area=max(area,1LL*w*h);
        }
        if(!area)   return -1;
        return area;
    }
};