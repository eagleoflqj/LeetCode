class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        list<int> l{deck.back()};
        for(auto b = ++deck.rbegin(); b != deck.rend(); ++b) {
            int i = l.back();
            l.pop_back();
            l.push_front(i);
            l.push_front(*b);
        }
        copy(l.begin(), l.end(), deck.begin());
        return deck;
    }
};
