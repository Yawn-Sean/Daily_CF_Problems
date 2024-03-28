#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

class union_find {
private:
    vector<int> parent;
    vector<int> rank;
    int total_components = 0;
public:
    union_find(int n) : parent(n), rank(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        total_components = n;
    }

    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
            total_components--;
        }
    }

    int total_connected_components() {
        return total_components;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int64 q;
    cin >> n >> m >> q;

    union_find dsu(n + m);
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        dsu.merge(r, c + n);
    }

    cout << dsu.total_connected_components() - 1 << "\n";

    return 0;
}

