#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

struct node {
    string s;
    int idx;
    vector<int> cnt;

    node() {}
    node(string t, int id) {
        s = t, idx = id;
        cnt.resize(10);
        for (const auto& v : s) {
            cnt[v - '0']++;
        }
    }
};

void ch(string& a, string& b, vector<int>& c, vector<int>& d) {
    if (a.size() < b.size() || c.empty()) {
        swap(a, b);
        swap(c, d);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<node> f(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        f[i] = node(s, i + 1);
    }

    vector<int> idx;
    string ans;
    auto get = [&](vector<int> vis, int vis4) -> void {
        sort(f.begin(), f.end(), [&](const node& a, const node& b) {
            int l = 0, r = 0;
            for (int i = 0; i < 10; i++) {
                if (vis[i]) {
                    l += a.cnt[i], r += b.cnt[i];
                }
            }

            return l > r;
        });
        if (vis4) {
            sort(f.begin() + k - 1, f.end(), [&](const node& a, const node& b) {
                int l = 0, r = 0, d1 = 0, d2 = 0;
                for (int i = 0; i < 10; i++) {
                    if (vis[i]) {
                        l += a.cnt[i], r += b.cnt[i];
                    }
                    if (i % 4 == 0) {
                        d1 += a.cnt[i], d2 += b.cnt[i];
                    }
                }

                return l + (d1 > 0) > r + (d2 > 0);
            });
        }

        char c = '!';
        vector<int> id;
        string res;
        for (int i = 0; i < k; i++) {
            id.push_back(f[i].idx);
            for (const auto& v : f[i].s) {
                if (vis[v - '0']) {
                    res += v;
                }
                if ((v - '0') % 4 == 0 && vis4) {
                    c = v;
                    vis4 = 0;
                }
            }
        }

        if (c != '!' && !res.empty()) {
            res += c;
        }
        ch(ans, res, idx, id);
    };

    vector<int> vis(10);
    for (int i = 2; i < 10; i += 4) {
        if (i % 4 == 0) {
            continue;
        }
        vis[i] = 1;
        get(vis, 0);
    }
    vis.assign(10, 0);

    for (int i = 1; i < 10; i += 2) {
        vis[i] = 1;
    }
    get(vis, 0);
    get(vis, 1);

    for (const auto& v : idx) {
        cout << v << " ";
    }
    cout << "\n";
    if (ans.empty()) {
        cout << "empty";
    } else {
        cout << ans;
    }
    return 0;
}