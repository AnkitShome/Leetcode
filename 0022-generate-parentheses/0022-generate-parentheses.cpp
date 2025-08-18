class Solution {
public:
    unordered_set<string> ans;
    int n;

    void recur(int ind,int val,int now,string cur){
        if(ind==n){
            if(val==0){
                ans.insert(cur);
            }
            return;
        }
        if(now==0){
            cur+='(';
            val++;
            recur(ind+1,val,0,cur);
            cur.pop_back();
            cur+='(';
            recur(ind+1,val,1,cur);
            cur.pop_back();
        }
        else{
            if(val<=0)  return;
            cur+=')';
            val--;
            recur(ind+1,val,0,cur);
            cur.pop_back();
            cur+=')';
            recur(ind+1,val,1,cur);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int m) {
        n=2*m;
        cout<<n<<endl;
        string cur="";
        recur(0,0,0,cur);
        vector<string> res;
        for(auto i:ans) res.push_back(i);
        return res;
    }
};
