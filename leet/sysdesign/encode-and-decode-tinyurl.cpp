class Solution {
public:
    string id_to_short(int n)
    {
        static const string conv = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ret;
        while(n)
        {
            ret += conv[n%62];
            n/=62;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string ret = id_to_short(n++);
        memo[ret] = longUrl;
        return "http://tinyurl.com/" + ret;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string id = shortUrl.substr(19);
        return memo[id];
    }
    unordered_map<string, string> memo;
    int n=0;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));