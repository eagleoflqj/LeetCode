class Solution {
    using VecPair = vector<array<vector<int>, 2>>;
public:
    int findMaximumXOR(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        VecPair candidate{{move(nums), {}}};
        for(int test = 1 << 30; test; test >>= 1) {
            VecPair different, same;
            for(auto &p : candidate) {
                vector<int> division[4];
                for(int i = 0; i < 2; ++i)
                    for(int x : p[i])
                        division[(i << 1) | (bool)(x & test)].push_back(x);
                if(p[1].empty()) {
                    if(!division[0].empty() && !division[1].empty()) {
                        different.push_back({move(division[0]), move(division[1])});
                    } else if(different.empty())
                        same.push_back(move(p));
                } else {
                    bool t1 = !division[0].empty() && !division[3].empty(), t2 = !division[1].empty() && !division[2].empty();
                    if(t1 || t2) {
                        if(t1)
                            different.push_back({move(division[0]), move(division[3])});
                        if(t2)
                            different.push_back({move(division[1]), move(division[2])});
                    } else if(different.empty())
                        same.push_back(move(p));
                }
            }
            candidate = move(different.empty() ? same : different);
        }
        return candidate[0][0][0] ^ (candidate[0][1].empty() ? candidate[0][0][1] : candidate[0][1][0]);
    }
};
