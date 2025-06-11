#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> parent(n);
    int father;
    parent[0] = -1;  // 根节点的父节点为-1
    for (int i = 1; i < n; i++) {
        cin >> father;
        parent[i] = father - 1;  // 建树
    }
    vector<long long> rank(n, 1);  // 叶子节点只需要一个颜色
    for (int i = 1; i < n; i++) {
        rank[parent[i]] = 0;  // 将非叶子节点全部归零
    }
    for (int i = n-1; i > 0; i--) {  // 从叶子节点开始向根节点更新颜色
        rank[parent[i]] += rank[i];  // 父节点需要的颜色数为子树需要的颜色之和
    }
    sort(rank.begin(), rank.end());
    for (long long num : rank) {
        cout << num << " ";
    }
    return 0;
}