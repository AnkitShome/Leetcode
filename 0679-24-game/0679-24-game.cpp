class Solution {
public:

    double eps=1e-6;

    bool gotcha(double num){
        if(fabs(num-24)<eps)    return true;
        return false;
    }

    bool f(vector<double>& cards){
        int n=cards.size();
        if(n==1) return gotcha(cards[0]);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double a=cards[i];
                double b=cards[j];

                vector<double> rem;
                for(int k=0;k<n;k++){
                    if(k!=i and k!=j)   rem.push_back(cards[k]);
                }

                vector<double> result={
                    a+b,
                    a*b,
                    a-b,
                    b-a
                };

                if(fabs(a)>eps) result.push_back(b/a);
                if(fabs(b)>eps) result.push_back(a/b);

                for(auto x:result){
                    rem.push_back(x);
                    if(f(rem))  return true;
                    rem.pop_back();
                }
            }        
        } 
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
       vector<double> godlike(cards.begin(),cards.end());
       return f(godlike);
    }
};