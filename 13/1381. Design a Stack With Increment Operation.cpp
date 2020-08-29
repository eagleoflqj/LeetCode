class CustomStack {
    int maxSize;
    list<int> l;
public:
    CustomStack(int maxSize) : maxSize(maxSize) {}
    
    void push(int x) {
        if(l.size() < maxSize)
            l.push_back(x);
    }
    
    int pop() {
        if(l.empty())
            return -1;
        int x = l.back();
        l.pop_back();
        return x;
    }
    
    void increment(int k, int val) {
        auto b = l.begin(), e = l.end();
        while(k-- && b != e)
            *b++ += val;
    }
};
