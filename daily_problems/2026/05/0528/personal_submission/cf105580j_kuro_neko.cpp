#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define frep(i, x, y) for (int i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
string dx[4] = {"UP", "LEFT", "RIGHT", "DOWN"};
string ask(string s) {
    cout << "MOVE " << s << '\n';
    cout.flush();
    string op;
    cin >> op;
    if (op == "EXIT") exit(0);
    return op;
}
string back() {
    cout << "BACK" << '\n';
    cout.flush();
    string op;
    cin >> op;
    if (op == "EXIT") exit(0);
    return op;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<set<array<int, 3>>>> vis(2 * n + 1, vector<set<array<int, 3>>>(2 * m + 1));
    int vx[4] = {-1, 0, 0, 1};
    int vy[4] = {0, -1, 1, 0};
    int opp[4] = {3, 2, 1, 0};
    vi cur = {-1, -1, -1};
    auto dfs = [&](this auto&& dfs, int x, int y) -> void {
        rep(i, 0, 3) {
            if (cur.back() == opp[i]) continue;
            int nx = x + vx[i];
            int ny = y + vy[i];
            if (nx < 0 || nx > 2 * n || ny < 0 || ny > 2 * m) continue;
            cur.emplace_back(i);
            array<int, 3> last = {cur[sz(cur) - 3], cur[sz(cur) - 2], cur[sz(cur) - 1]};
            if (!vis[nx][ny].count(last)) {
                string op = ask(dx[i]);
                if (op == "OK") {
                    vis[nx][ny].insert(last);
                    dfs(nx, ny);
                    back();
                }
            }
            cur.pop_back();
        }
    };
    vis[n][m].insert({-1, -1, -1});
    dfs(n, m);
    return;
}
// 写不出来呜呜，看了editorial才写出来的
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
