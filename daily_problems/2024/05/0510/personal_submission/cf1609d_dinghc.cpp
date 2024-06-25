#include <bits/stdc++.h>

using namespace std;

class union_find {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> sizes;
    map<int, int> freq;
public:
    union_find(int n) : parent(n), rank(n), sizes(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
            sizes[i] = 1;
        }
        freq.insert({1, n});
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
            {
                if (--freq[sizes[a]] == 0) freq.erase(sizes[a]);
                if (--freq[sizes[b]] == 0) freq.erase(sizes[b]);
                sizes[a] += sizes[b];
                freq[sizes[a]]++;
            }
        }
    }

    int mx_component_size(int k) {
        int res = 0;
        for (auto it = freq.rbegin(); it != freq.rend(); it++) {
            auto&[sz, cnt] = *it;
            res += sz * min(cnt, k);
            k -= min(cnt, k);
            if (k == 0) break;
        }
        return res - 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    union_find dsu(n);
    for (int i = 0, k = 0, x, y; i < d; i++) {
        cin >> x >> y;
        x--, y--;
        if (dsu.find(x) != dsu.find(y)) {
            dsu.merge(x, y);
        } else {
            k++;
        }
        cout << dsu.mx_component_size(k + 1) << "\n";
    }
    return 0;
}

