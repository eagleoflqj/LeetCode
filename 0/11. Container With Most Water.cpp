class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ret = 0, i = 0, j = n - 1;
        while(i < j) {
            if(height[i] > height[j]) {
                ret = max(ret, height[j] * (j - i));
                --j; // for all i<x<j, f(x,j)=min(hx,hj)*(j-x)<hj*(j-i)=f(i,j), so discard j
            } else {
                ret = max(ret, height[i] * (j - i));
                ++i;
            }
        }
        return ret;
    }
};
