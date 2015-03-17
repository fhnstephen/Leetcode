/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        vector<int> a,b,c;
        toVector(l1, a);
        toVector(l2, b);
        cout << "what";
        add(a, b, c);
        return toList(c);
    }
private:
    void toVector(ListNode *cur, vector<int> &vec) {
        vec.push_back(cur->val);
        if (cur->next != NULL) toVector(cur->next, vec);
    }
    ListNode *toList(const vector<int> &vec) {
        ListNode *last = nullptr;
        for (auto i = vec.rbegin(); i != vec.rend(); ++i) {
          ListNode *cur = new ListNode(*i);
          cur->next = last;
          last = cur;
        }
        return last;
    }
    template<typename T>
    void add(T &a, T &b, T &c) {
      c.clear();
      int len = max(a.size(), b.size());
      a.resize(len); b.resize(len); c.resize(len);
      cout << len << " " << c.size() << endl;
      for (int i = 0; i < len; ++i)
        c[i] = a[i] + b[i];
      for (int i = 0; i < len - 1; ++i)
        if (c[i] >= 10) {
          c[i] -= 10;
          c[i+1]++;
        }
      if (c[len - 1] >= 10) {
        c[len - 1] -= 10;
        c.push_back(1);
      }
    }
};
