#include<bits/stdc++.h>
using namespace std;
const int N = 2010, M = 2 * N;
int h[N], e[M], ne[M], idx;
int c[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

vector<int> ans;
int cnt[N];
int dfs(int u, int fa)
{
    int sum = 0;
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(j == fa) continue;
        int t = dfs(j, u);
        if(t == -1) return -1;
        sum += t;
    }
    cnt[u] = sum + 1;
    if(c[u] >= cnt[u]) return -1;
    ans.insert(ans.begin() + c[u], u);
    return cnt[u];
}

int main()
{
    int n; cin >> n;
    memset(h, -1, sizeof h);
    int root;
    for(int i = 1; i <= n; i++)
    {
        int p;
        cin >> p >> c[i];
        add(i, p);
        add(p, i);
        if(p == 0) root = i;
    }

    if(dfs(root, 0) == -1) cout << "NO";
    else
    {
        cout << "YES\n";

        vector<int> res(n + 1);
        for(int i = 0; i < ans.size(); i++)
        {
            res[ans[i]] = i + 1;
        }
        for(int i = 1; i <= n; i++) cout << res[i] << " ";
    }
}
