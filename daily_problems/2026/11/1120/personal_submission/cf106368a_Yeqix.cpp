#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

vector<string> sgn = {"+", "-", "*", "%"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 a, m, b, n;
    cin >> a >> m >> b >> n;
    int g = b % n;

    auto get = [&](i64 st, string res) -> string {
        string ans;
        st = (st % n + n) % n;
        vector<int> dist(n, n + 1);
        vector<array<int, 2>> fa(n + 1);
        queue<int> que;
        que.push(st);
        dist[st] = res.size();
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            if (dist[g] != n + 1) {
                break;
            }
            int v = (u + m) % n;
            if (dist[v] == n + 1) {
                dist[v] = dist[u] + 1, fa[v] = {u, 0};
                que.push(v);
            }
            v = ((u - m) % n + n) % n;
            if (dist[v] == n + 1) {
                dist[v] = dist[u] + 1, fa[v] = {u, 1};
                que.push(v);
            }
            v = 1LL * u * m % n;
            if (dist[v] == n + 1) {
                dist[v] = dist[u] + 1, fa[v] = {u, 2};
                que.push(v);
            }
        }

        if (dist[g] > n) {
            return "-1";
        }

        int now = g;
        while (now != st) {
            ans += sgn[fa[now][1]];
            now = fa[now][0];
        }
        ans += res;
        rgs::reverse(ans);
        return ans;
    };

    vector<string> ans = {get(a, ""), get((a % m + m) % m, "%"), get(0, "%*")};
    string res = "-1";
    for (const auto& x : ans) {
        if (x == "-1") {
            continue;
        }
        if (x.size() < res.size() || res == "-1") {
            res = x;
        }
    }

    if (res == "-1") {
        cout << res;
        return 0;
    }
    cout << res.size() << "\n";
    cout << res;
    return 0;
}
