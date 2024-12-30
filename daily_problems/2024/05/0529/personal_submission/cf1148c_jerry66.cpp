#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 300100;
 
int a[N], pos[N];
 
void Swap(int x, int y)
{
    swap(pos[a[x]], pos[a[y]]);
    swap(a[x], a[y]);
}
vector<PII> res;
 
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i], pos[a[i]] = i; 
    
    // swap左面那一半 1~n/2
    for (int i = 1; i <= n / 2; i ++ )
    {
        if (i == pos[i]) continue;
        // if at left
        //      move right -> move target
        
        if (pos[i] <= n/2)
        {
            res.push_back({pos[i], n}); 
            Swap(pos[i], n);
            res.push_back({pos[i], i}); 
            Swap(pos[i], i);
        }
        else
        {
            int op = pos[i];
            res.push_back({pos[i], 1});
            Swap(pos[i], 1);
            res.push_back({pos[i], n}); 
            Swap(pos[i], n);
            res.push_back({pos[i], i}); 
            Swap(pos[i], i);
            if (pos[1] == 1) continue;
            res.push_back({1, op}); 
            Swap(1, op);
        }
        // else
        //      move left -> move right -> move target
    }
    
    // 处理右侧
    for (int i = n/2 + 1; i <= n; i ++ )
    {
        if (i == pos[i]) continue;
        int a = i;
        int b = pos[i];
        res.push_back({1, a}); 
        Swap(1, a);
        res.push_back({1, b}); 
        Swap(1, b);
        res.push_back({1, a});
        Swap(1, a);
    }
    cout << res.size() << '\n';
    for (PII& p : res) cout << p.first << ' ' << p.second << '\n';
    
}
 
signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(false);
    solve();
}
