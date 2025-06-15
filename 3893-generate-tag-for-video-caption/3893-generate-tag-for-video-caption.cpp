class Solution {
public:
    string generateTag(string caption) {
        string s="#";
        bool f=0;
        bool cap=0;
        for(int i=0;i<caption.size();i++){
            if(caption[i]==' ')   {cap=1;continue;}
            if(!isalpha(caption[i]))   continue;
            if(!f and i==0){
                f=1;
                s+=tolower(caption[i]);
                continue;
            }
            if(!cap) {s+=tolower(caption[i]);}
            if(cap) {s+=toupper(caption[i]);cap=0;}
        }
        s=s.substr(0,100);
        s[1]=tolower(s[1]);
        return s;
    }
};