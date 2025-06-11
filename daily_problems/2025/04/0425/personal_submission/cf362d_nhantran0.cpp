/**
 * https://codeforces.com/contest/362/problem/D
 * D. Fools and Foolproof Roads
 * Solver: nhant
 * 2025-04-26 02:54:44
 * https://codeforces.com/contest/362/submission/317222194, 139 ms, 200 KB
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> d;
vector<int64_t> cl;

int get(int x) {
    return d[x] < 0 ? x : (d[x] = get(d[x]));
}

bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    if (-d[x] < -d[y]) {
        swap(x, y);
    }
    d[x] += d[y];
    d[y] = x;
    return true;
}

void solve() {
    int n, m, plan, q;
    cin >> n >> m >> plan >> q;
    d = vector<int>(n, -1);
    cl = vector<int64_t>(n, 0);
    vector<int> sameReg(2, -1);
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        u--; v--;
        int pu = get(u), pv = get(v);
        if (unite(u, v)) {
            int pa = get(u);
            cl[pa] = cl[pu] + cl[pv] + l;
            if (sameReg[0] == -1) {
                sameReg[0] = u;
                sameReg[1] = v;
            }
        } else {
            cl[get(u)] += l;
        }
    }
    auto comp = [&](int& a, int& b) { return cl[a] > cl[b]; };
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    for (int i = 0; i < n; i++) {
        if (d[i] < 0) {
            pq.push(i);
        }
    }
    vector<array<int,2>> ne;
    while ((int)pq.size() > q && plan > 0) {
        int u = pq.top(); pq.pop();
        int v = pq.top(); pq.pop();
        unite(u, v);
        int pa = get(u);
        cl[pa] = cl[u] + cl[v] + min(1000000000LL, cl[u] + cl[v] + 1);
        pq.push(pa);
        ne.push_back({u, v});
        plan--;
        if (sameReg[0] == -1) {
            sameReg[0] = u;
            sameReg[1] = v;
        }
    }
    if ((int)pq.size() == q && plan > 0 && sameReg[0] != -1) {
        for (; plan > 0; plan--) {
            ne.push_back({sameReg[0], sameReg[1]});
        }
    }
    if ((int)pq.size() == q && plan == 0) {
        cout << "YES\n";
        for (array<int,2>& e : ne) {
            cout << e[0] + 1 << " " << e[1] + 1 << '\n';
        }
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
