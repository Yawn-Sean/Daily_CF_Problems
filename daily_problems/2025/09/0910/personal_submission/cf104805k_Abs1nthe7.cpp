#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void sol() 
{
    i64 n, L;
    cin >> n >> L;
    i64 max_p = L + 1;

    unordered_set<int> b;//去重
    for (int i = 0; i < n; ++i) 
    {
        int x;
        cin >> x;
        b.insert(x + 1);
    }

    vector<int> fa(b.begin(), b.end());
    sort(fa.begin(), fa.end());

    unordered_set<i64> vis;
    vis.insert(1);
    queue<pair<i64, int>> q;
    q.emplace(1, 0);

    while (!q.empty()) 
    {
        auto [now, start] = q.front();
        q.pop();

        for (int i = start; i < fa.size(); ++i) 
        {
            i64 f = fa[i];
            if (now > max_p / f) 
            {
                continue;
            }
            i64 nxt = now * f;
            if (nxt > max_p) 
            {
                continue;
            }
            if (!vis.count(nxt)) 
            {
                vis.insert(nxt);
                q.emplace(nxt, i);
            }
        }
    }

    cout << vis.size() - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sol();
    return 0;
}
