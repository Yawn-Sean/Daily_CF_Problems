#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // If you have a minimum spanning tree of the graph, 
    // how can you add an edge to the graph without changing the MST?	

    int n, m;
    cin >> n >> m;
    vector<int> edges_weight(m);
    vector<int> is_in(m);
    for (int i = 0; i < m; i++) {
        cin >> edges_weight[i] >> is_in[i];
    }

    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        if (edges_weight[i] != edges_weight[j]) {
            return edges_weight[i] < edges_weight[j];
        }
        return is_in[i] > is_in[j];
    });

    vector<int> us(m), vs(m);
    int size = 2;
    int u = 2, v = 1;
    for (auto& eid: order) {
        if (is_in[eid]) {
            us[eid] = 1;
            vs[eid] = size++;
        } else {
            if (++v == u) {
                v = 2;
                u++;
            }
            if (u >= size) {
                cout << -1;
                return 0;
            }
            us[eid] = u;
            vs[eid] = v;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << us[i] << ' ' << vs[i] << '\n';
    }
    return 0;
}
