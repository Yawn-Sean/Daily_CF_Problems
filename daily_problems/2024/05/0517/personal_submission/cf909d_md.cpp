// 0517
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int idx;
    Node* prev;
    Node* next;
    char color;
    bool removed {false};
    Node(int idx, char color) : idx(idx), color(color), prev(nullptr), next(nullptr) {}
};
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    string input;
    cin >> input;
 
    const auto n = size(input);
 
    vector<unique_ptr<Node>> nodes;
    nodes.reserve(n + 2);
    nodes.emplace_back(make_unique<Node>(-1, '$'));
    for (int i = 1; i <= n; ++i) {
        nodes.emplace_back(make_unique<Node>(i - 1, input[i - 1]));
        nodes[i]->prev = nodes[i-1].get();
        nodes[i-1]->next = nodes[i].get();
    }
    nodes.emplace_back(make_unique<Node>(n, '$'));
    nodes[n]->next = nodes[n + 1].get();
    nodes.back()->prev = nodes[n].get();

    vector<Node*> to_remove_nodes;
    for (int i = 0; i < n; ++i) {
        if (i && input[i] != input[i - 1] || i + 1 < size(input) && input[i] != input[i+1]) {
            to_remove_nodes.push_back(nodes[i + 1].get());
        }
    }

    int cnt = 0;
    deque<bool> added(n, false);
 
    auto isvalid = [n](Node* node) {
        return node->color != '$' && node->idx >= 0 && node->idx < n;
    };
 
    auto not_removed = [&added](Node* node) {
        return !node->removed && !added[node->idx];
    };
 
    while (!empty(to_remove_nodes)) {
        ++cnt;
        for (auto&& node : to_remove_nodes) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->removed = true;
        }
        
        vector<Node*> tmp_to_remove_nodes;
        for (auto&& node : to_remove_nodes) {
            if (isvalid(node->prev) && isvalid(node->prev->next) && not_removed(node->prev) && node->prev->color != node->prev->next->color) {
                tmp_to_remove_nodes.emplace_back(node->prev);
                added[node->prev->idx] = true;
            } 
 
            if (isvalid(node->next) && isvalid(node->next->prev) && not_removed(node->next) && node->next->color != node->next->prev->color) {
                tmp_to_remove_nodes.emplace_back(node->next);
                added[node->next->idx] = true;
            }
        }
        
        to_remove_nodes = move(tmp_to_remove_nodes);
    }
 
    cout << cnt << endl;
 
    return 0;
}