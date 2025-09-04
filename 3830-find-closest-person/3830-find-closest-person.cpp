class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(z-x)==abs(y-z))  return 0;
        if(abs(x-z)>abs(y-z))   return 2;
        return 1;
    }
};