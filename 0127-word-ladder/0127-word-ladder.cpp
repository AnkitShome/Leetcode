class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        queue<pair<int,string>> q;
        unordered_map<string,int> vis;

        q.push({1,beginWord});
        vis[beginWord]=1;

        while(!q.empty()){
            auto [step,word]=q.front();q.pop();
            if(word==endWord)   return step;
            for(int i=0;i<word.size();i++){
                for(char x='a';x<='z';x++){
                    string newWord=word;
                    newWord[i]=x;
                    if(st.count(newWord)){
                        if(!vis[newWord]){
                            vis[newWord]=1;
                            q.push({step+1,newWord});
                        }
                    }
                }
            }
        }
        return 0;
    }
};