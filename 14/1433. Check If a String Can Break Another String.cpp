class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int count1[26]{}, count2[26]{}, n = s1.size();
        for(int i = 0; i < n; ++i) {
            ++count1[s1[i] - 'a'];
            ++count2[s2[i] - 'a'];
        }
        bool bigger = false, smaller = false;
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < 26; ++i) {
            sum1 += count1[i];
            sum2 += count2[i];
            if(sum1 > sum2)
                bigger = true;
            else if(sum1 < sum2)
                smaller = true;
        }
        return !(bigger && smaller);
    }
};
