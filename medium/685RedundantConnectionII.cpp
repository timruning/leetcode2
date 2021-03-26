//
// Created by 宋峰 on 2021/3/18.
//
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int>
    find_root(unordered_map<int, vector<int>> &f2c, unordered_map<int, vector<int>> &c2f, vector<int> &edge) {
        vector<int> result;
        for (auto pair:f2c) {
            if (pair.first == edge[0] && pair.second.size() == 1 && pair.second[0] == edge[1]) {
                continue;
            }
            if (c2f.find(pair.first) == c2f.end()) {
                result.push_back(pair.first);
            } else if (c2f[pair.first].size() == 1 && c2f[pair.first][0] == edge[0] && pair.first == edge[1]) {
                result.push_back(pair.first);
            } else {
                continue;
            }
        }
        return result;
    }

    bool check(unordered_map<int, vector<int>> &f2c, unordered_map<int, vector<int>> &c2f, vector<int> &edge, int n) {
        // check 2 f
        for (auto pair:c2f) {
            if (pair.first == edge[1] && pair.second.size() - 1 > 1) {
                return false;
            }
            if (pair.first != edge[1] && pair.second.size() > 1) {
                return false;
            }
        }
        // check circle
        vector<int> roots = find_root(f2c, c2f, edge);
        if (roots.size() != 1) {
            return false;
        }
        int root = roots[0];
        unordered_set<int> watchlist;
        watchlist.insert(root);
        vector<int> queue({root});
        int edge_num = 0;
        while (queue.size() > 0) {
            int pre = queue[0];
            queue.erase(queue.begin());
            if (f2c.find(pre) == f2c.end()) {
                continue;
            }
            vector<int> childs = f2c[pre];
            for (auto v:childs) {
                if (pre == edge[0] && v == edge[1]) {
                    continue;
                }
                edge_num += 1;
                if (watchlist.find(v) != watchlist.end()) {
                    return false;
                }
                watchlist.insert(v);
                queue.push_back(v);
            }
        }
        if (edge_num == n - 1) {
            return true;
        } else {
            return false;
        }
    }

    vector<int> findRedundantDirectedConnection1(vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> f2c;
        unordered_map<int, vector<int>> c2f;
        for (int i = 0; i < edges.size(); i++) {
            int f = edges[i][0];
            int c = edges[i][1];
            if (f2c.find(f) != f2c.end()) {
                f2c[f].push_back(c);
            } else {
                f2c[f] = vector<int>({c});
            }
            if (c2f.find(c) != c2f.end()) {
                c2f[c].push_back(f);
            } else {
                c2f[c] = vector<int>({f});
            }
        }

        for (int i = edges.size() - 1; i >= 0; i--) {
            bool flag = check(f2c, c2f, edges[i], edges.size());
            if (flag) {
                return edges[i];
            }
        }
        return edges[0];
    }

    vector<int> p;
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        p.resize(n + 1);
        for (int i = 1; i <= n; i ++) p[i] = i;
        vector<int> indegree(n + 1);
        for (auto edge : edges) {
            indegree[edge[1]] ++;
        }
        vector<vector<int>> conflicts;
        for (auto edge : edges) {
            if (indegree[edge[1]] > 1) {
                conflicts.push_back(edge);
            }
        }

        if (conflicts.size() > 0) {
            if (isTreeByRemoveEdge(edges, conflicts[1])) {
                return conflicts[1];
            }
            else return conflicts[0];
        }
        return getTreeByCircle(edges);
    }
    bool isTreeByRemoveEdge(vector<vector<int>>& edges, vector<int>& x) {
        for (auto edge : edges) {
            if (edge == x) continue;
            int a = find(edge[0]), b = find(edge[1]);
            if (a == b) return false;
            p[b] = a;
        }
        return true;
    }
    vector<int> getTreeByCircle(vector<vector<int>>& edges) {
        for (auto edge : edges) {
            int a = find(edge[0]), b = find(edge[1]);
            if (a == b) return edge;
            p[b] = a;
        }
        return {};
    }
    int find(int a) {
        if (p[a] != a) p[a] = find(p[a]);
        return p[a];
    }

};