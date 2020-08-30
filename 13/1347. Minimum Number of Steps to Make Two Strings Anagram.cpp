class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26]{};
        for(char c : s)
            ++freq[c - 'a'];
        for(char c : t)
            --freq[c - 'a'];
        int sum = 0;
        for(int i : freq)
            sum += abs(i);
        return sum >> 1;
    }
};
