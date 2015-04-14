class Solution {
public:
    int findMin(vector<int> &num) {
      // return *(min_element(num.begin(), num.end()));  // even faster in the OJ although O(n)
      return search(num.begin(), num.end());
    }
private:
    template<typename T>
    int search(T l, T r) {
      if (l >= r) return numeric_limits<int>::max();
      if (*l <= *(r - 1)) return *l;
      T mid = l + (r - l) /2;
      return min(search(l, mid), search(mid, r));
    }
};
