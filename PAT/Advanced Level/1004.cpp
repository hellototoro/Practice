#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void dfs(map<string, vector<string>>& ch_tree, string id, int level, int& max_level, vector<int>& out);

int _1004()
{
    int n, m;
    int level = 0;
    int max_level = 0;
    vector<int> out;
    map<string, vector<string>> ch_tree;
    cin >> n >> m;

    if (n == 0)
        return 0;

    for (int i = 0; i < m; ++i) {
        int k;
        string id;
        cin >> id >> k;
        vector<string> children;
        for (int j = 0; j < k; ++j) {
            string ids;
            cin >> ids;
            children.push_back(ids);
        }
        ch_tree[id] = move(children);
    }

    out.resize(100);
    dfs(ch_tree, "01", level, max_level, out);
    for (int i = 0; i < max_level; ++i) {
        cout << out[i] << ' ';
    }
    cout << out[max_level] << endl;

    return 0;
}

void dfs(map<string, vector<string>>& ch_tree, string id, int level, int& max_level, vector<int>& out)
{
    if (ch_tree.find(id) != ch_tree.end()) { // c_id 有子节点
        max_level = max(max_level, ++level);
        for (const auto& c_id : ch_tree[id]) {
            dfs(ch_tree, c_id, level, max_level, out);
        }
    }
    else {
        ++out[level];
    }
}