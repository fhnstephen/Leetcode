/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        insert(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        return pop();
    }
private:
    stack<TreeNode*> s;
    void insert(TreeNode *root) {
        if (!root) return;
        s.push(root);
        insert(root->left);
    }
    int pop() {
        if (s.empty()) return -1;
        auto top = s.top()->right;
        auto ret = s.top()->val;
        s.pop();
        insert(top);
        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
