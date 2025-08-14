class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        int thirdLastIndex=n-2;

        priority_queue<string> pq;

        for(int i=0;i<thirdLastIndex;i++){
            string temp=num.substr(i,3);

            char first=temp[0];
            char second=temp[1];
            char third=temp[2];

            bool fine=0;

            if(first==second and first==third and second==third){
                fine=1;
            }
            
            if(!fine)   continue;

            pq.push(temp);
        }

        if(!pq.size())  return "";

        string largest=pq.top();
        return largest;
    }
};