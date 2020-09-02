class RecentCounter {
    queue<int> history;
public:
    RecentCounter() {}
    
    int ping(int t) {
        history.push(t);
        while(history.front() < t - 3000)
            history.pop();
        return history.size();
    }
};
