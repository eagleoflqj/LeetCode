class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate[2]{0, 1}, count[2]{}, n = nums.size();
        for(int i : nums) {
            if(i == candidate[0]) // for each occurrence of major element, either increase its counter
                ++count[0];
            else if(i == candidate[1])
                ++count[1];
            else if(!count[0]) {
                candidate[0] = i;
                count[0] = 1;
            } else if(!count[1]) {
                candidate[1] = i;
                count[1] = 1;
            } else { // ... or discard 3 different elements, which keeps major elements major
                --count[0]; // and happens <= floor(n/3) times (because there are n elements),
                --count[1]; // so the former situation must happen, making counter > 0 in the end
            }
        }
        count[0] = count[1] = 0;
        for(int i : nums) // but candidates may not be major
            for(int j = 0; j < 2; ++j)
                if(i == candidate[j])
                    ++count[j];
        vector<int> ret;
        for(int j = 0; j < 2; ++j)
            if(count[j] > n / 3)
                ret.push_back(candidate[j]);
        return ret;
    }
};
