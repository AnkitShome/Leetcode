class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        int n=code.size();
        using pii=pair<string,string>;

        auto cmp = [](const pii& a, const pii& b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first>b.first;
        };

        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

        for(int i=0;i<n;i++){
            if(isActive[i] and (businessLine[i]=="electronics" or businessLine[i]=="pharmacy" or businessLine[i]=="grocery" or businessLine[i]=="restaurant")){
                bool f=0;
                for(auto x:code[i]){
                    if((x>='a' and x<='z') or (x>='A' and x<='Z') or (x>='0' and x<='9') or x=='_')   continue;
                    else    {f=1;break;}
                }
                if(!f and code[i].size()>0)
                pq.push({businessLine[i],code[i]});
            }
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};