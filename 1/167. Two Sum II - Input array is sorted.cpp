class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), i = 0, j = n - 1;
        vector<int> ret(2);
        while(i < j) {
            int sum = numbers[i] + numbers[j];
            if(sum > target)
                --j;
            else if(sum < target)
                ++i;
            else {
                ret[0] = i + 1;
                ret[1] = j + 1;
                break;
            }
        }
        return ret;
    }
};
