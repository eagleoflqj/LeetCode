class Solution {
    hash<string> h;
    unordered_map<size_t, string> m;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        size_t hashed = h(longUrl);
        m.emplace(hashed, longUrl);
        return to_string(hashed);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        size_t hashed;
        istringstream(shortUrl) >> hashed;
        return m[hashed];
    }
};
