class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> temp;
        for(int i : arr) {
            int j = i, count = 0;
            while(j) {
                count += j & 1;
                j >>= 1;
            }
            temp.emplace_back(count, i);
        }
        sort(temp.begin(), temp.end());
        transform(temp.begin(), temp.end(), arr.begin(), [](const auto &p) { return p.second; });
        return arr;
    }
};
