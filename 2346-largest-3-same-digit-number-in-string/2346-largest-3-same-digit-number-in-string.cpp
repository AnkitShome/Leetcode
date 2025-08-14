class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        int thirdLastIndex=n-2;

        int arr[10];

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

            int digit=first-'0';
            arr[digit]=1;
        }

        int digit=-1;

        for(int i=9;i>=0;i--){
            if(arr[i]){
                digit=i;break;
            }
        }

        if(digit==-1)   return "";

        string ans="";
        for(int i=0;i<3;i++){
            ans+=(digit+'0');
        }
        return ans;
    }
};