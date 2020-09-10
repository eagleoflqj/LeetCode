class Solution {
public:
    string getHint(string secret, string guess) {
        int m[10]{}, bull = 0, cow = 0, n = guess.size();
        for(int i = 0, j = 0; i < n; ++i)
            if(guess[i] == secret[i])
                ++bull;
            else {
                ++m[secret[i] - '0'];
                guess[j++] = guess[i];
            }
        for(int i = 0; i < n - bull; ++i)
            if(--m[guess[i] - '0'] >= 0)
                ++cow;
        ostringstream oss;
        oss << bull << 'A' << cow << 'B';
        return oss.str();
    }
};
