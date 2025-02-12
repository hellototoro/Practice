#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct sub_tree
{
    sub_tree() {}
    sub_tree(string id) : id{ id } {}

    string id;
    vector<sub_tree> children;
};

int _1004()
{
    int n, m;
    cin >> n >> m;
    if (n == 0) {
        return 0;
    }
    map<string, sub_tree*> my_map;
    sub_tree *root, *p = nullptr;
    for (int i = 0; i < m; ++m) {
        int k;
        string id;
        cin >> id >> k;
        sub_tree my_tree(id);
        for (int j = 0; j < k; ++j) {
            cin >> id;
            my_tree.children.push_back(sub_tree(id));
        }
        my_map[my_tree.id] = &my_tree;
    }

    for (auto& pair : my_map) {
        for (auto& tree : pair.second->children) {
            auto it = my_map.find(tree.id);
            if (it != my_map.end()) {

            }
        }
    }

    return 0;
}