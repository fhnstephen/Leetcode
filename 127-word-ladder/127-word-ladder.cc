class Solution {
public:
    struct node {
        int len;
        string cur;
        node(int x = 0, string y = "") : len(x), cur(y) {}
    };

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end || !dict.count(start) || !dict.count(end)) return 0;
        enqueue(1, start);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            string &str = cur.cur;
            int step = cur.len;
            int len = str.length();
            for (int i = 0; i < len; ++i) {
                string next = str;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    next[i] = ch;
                    if (dict.count(next)) {
                        if (next == end) return step + 1;
                        enqueue(step + 1, next);
                    }
                }
            }
        }
        return 0;
    }

private:
    queue<node> q;
    unordered_set<string> set;
    void enqueue(int len, string cur) {
        if (set.count(cur)) return;
        set.insert(cur);
        q.push(node(len, cur));
    }
};
