class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26);
        for(auto i:s){
            freq[i-'a']++;
        }   
        pair<int,int> odd={INT_MAX,INT_MIN};
        pair<int,int> even={INT_MAX,INT_MIN};
        for(auto i:freq){
            if(!i)  continue;
            if(i&1) {odd.first=min(odd.first,i);odd.second=max(odd.second,i);}
            else    {even.first=min(even.first,i);even.second=max(even.second,i);}
        }
        return odd.second-even.first;
    }
};