class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> stk;
        stk.push(arr[0]);
        int n = arr.size(), sum = 0, t;
        for(int i = 1; i < n; ++i) {
            while((t = stk.top()) <= arr[i]) {
                stk.pop();
                if(stk.empty()) {
                    sum += t * arr[i];
                    break;
                }
                sum += t * min(arr[i], stk.top());
            }
            stk.push(arr[i]);
        }
        t = stk.top();
        stk.pop();
        while(!stk.empty()) {
            int t1 = stk.top();
            stk.pop();
            sum += t1 * t;
            t = t1;
        }
        return sum;
    }
};
