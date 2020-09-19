class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ret;
        int base = 0, inc = 0, num = 0;
        do {
            inc = inc * 10 + 1;
            base += inc;
            for(num = base; num % 10 && num <= high; num += inc)
                if(num >= low)
                    ret.push_back(num);
        } while(num <= high);
        return ret;
    }
};
