#include <bits/stdc++.h>
using namespace std;

vector<int> query(const string &s, int n) {
    cout << "QUERY " << s << endl;
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> res[i])) {
            exit(0);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    string all1(n, '1');
    vector<int> total_deg = query(all1, n);

    const int B = 15;
    vector<vector<int>> notes(B, vector<int>());
    for (int j = 0; j < B; ++j) {
        string s;
        s.reserve(n);
        for (int i = 0; i < n; ++i) {
            s.push_back(((i >> j) & 1) ? '1' : '0');
        }
        notes[j] = query(s, n);
    }

    vector<int> stk;
    for (int i = 0; i < n; ++i) {
        if (total_deg[i] == 1) stk.push_back(i);
    }

    vector<pair<int,int>> edges;
    edges.reserve(max(0, n - 1));

    for (int iter = 0; iter < n - 1; ++iter) {
        if (stk.empty()) break; 
        int u = stk.back();
        stk.pop_back();

        int v = 0;
        for (int j = 0; j < B; ++j) {
            if (notes[j][u]) v |= (1 << j);
        }
        for (int j = 0; j < B; ++j) {
            if ((u >> j) & 1) {
                if (v >= 0 && v < n) notes[j][v] -= 1;
            }
        }
        total_deg[v] -= 1;
        if (total_deg[v] == 1) stk.push_back(v);

        edges.emplace_back(u + 1, v + 1); 
    }

    cout << "ANSWER" << '\n';
    for (auto &e : edges) {
        cout << e.first << ' ' << e.second << '\n';
    }
    cout << flush;
    return 0;
}
