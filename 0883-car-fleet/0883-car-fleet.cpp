class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> cars(n);
        for(int i=0;i<n;i++){
            cars[i].first=position[i];
            cars[i].second=speed[i];
        }
        sort(cars.begin(),cars.end());

        stack<int> st;
        int col=0;

        for(int i=n-1;i>=0;i--){
            if(!st.empty()){
                int j=st.top();
                
                double this_car=double(target-cars[i].first)/double(cars[i].second);
                double next_car=double(target-cars[j].first)/double(cars[j].second);

                if(this_car<=next_car){

                }
                else    {
                    col++;
                    st.pop();
                    st.push(i);
                }
            }
            if(i==n-1)
                st.push(i);
        }
        return col+1;
    }
};