class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        queue<pair<int,string>> q;
        q.push({1,beginWord});
        st.erase(beginWord);

        while(!q.empty()){
            auto [step,word]=q.front();q.pop();
            if(word==endWord)   return step;
            for(int i=0;i<word.size();i++){
                for(char x='a';x<='z';x++){
                    string newWord=word;
                    newWord[i]=x;
                    if(newWord==word)   continue;
                    if(st.count(newWord)){
                        st.erase(newWord);
                        q.push({step+1,newWord});
                    }
                }
            }
        }
        return 0;
    }
};