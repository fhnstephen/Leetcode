/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        map_.clear();
        set_.clear();
        map_[node->label] = new UndirectedGraphNode(node->label);
        dfs(node);
        return map_[node->label];
    }
private:
    unordered_map<int, UndirectedGraphNode*> map_;
    unordered_set<int> set_;
    void dfs(UndirectedGraphNode* cur) {
        if (!cur || set_.count(cur->label)) return;
        auto cur_node = map_[cur->label];
        set_.insert(cur->label);
        for (auto x : cur->neighbors) {
            if (!map_[x->label]) {
                map_[x->label] = new UndirectedGraphNode(x->label);
            }
            cur_node->neighbors.push_back(map_[x->label]);
            dfs(x);
        }
    }
};
