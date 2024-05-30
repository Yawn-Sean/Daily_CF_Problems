#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long LL;
typedef pair<int, int> PII;
 
const int N = 2e5 + 100;
 
int n, m, s, k;
int dollar[N], pound[N];
int types, val;
 
vector<PII> dplays, pplays;
 
int f1[N], f2[N];
 
void solve() 
{
    cin >> n >> m >> k >> s;
    // n天，m个玩具，需要k个，有s个钱
    for (int i = 1; i <= n; i ++ ) cin >> dollar[i];
    for (int i = 1; i <= n; i ++ ) cin >> pound[i];
    
    for (int i = 1; i <= m; i ++ )
    {
        cin >> types >> val;
        if (types == 1) dplays.push_back({val, i});
        else pplays.push_back({val, i});
    }
    
    sort(dplays.begin(), dplays.end());
    sort(pplays.begin(), pplays.end());
    
    for (int i = 1; i <= dplays.size(); i ++ )
        f1[i] = f1[i - 1] + dplays[i - 1].first;
    for (int i = 1; i <= pplays.size(); i ++ )
        f2[i] = f2[i - 1] + pplays[i - 1].first;
    
 
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        int m1 = 1e9, m2 = 1e9;
        for (int i = 1; i <= mid; i ++ ) m1 = min(m1, dollar[i]), m2 = min(m2, pound[i]);
        
        bool ok = false;
        
        
        for (int i = 0; i <= k; i ++ ) {
            // d的数量
            if (dplays.size() < i) break;
            
            int ps = k - i;
            if (pplays.size() < ps) continue;
            
            if (f1[i] * m1 + f2[ps] * m2 <= s) ok = true;
            
        }
        
        
        if (ok) r = mid;
        else l = mid + 1;
    }
    
    // 结论是r，看r是否ok
    int m1 = 1e9, m2 = 1e9;
    int d1 = -1, d2 = -1;
    for (int i = 1; i <= r; i ++ )
    {
        if (m1 > dollar[i]) m1 = dollar[i], d1 = i;
        if (m2 > pound[i]) m2 = pound[i], d2 = i;
    }
    
    bool ok = false;
    
    
    int idx1 = -1, idx2 = -1;
    
    for (int i = 0; i <= k; i ++ ) {
        // d的数量
        if (dplays.size() < i) break;
        
        int ps = k - i;
        if (pplays.size() < ps) continue;
        
        if (f1[i] * m1 + f2[ps] * m2 <= s)
        {
            idx1 = i;
            idx2 = ps;
            ok = true;
        }
    }
    
    if (!ok)
    {
        cout << "-1\n";
        return;
    }
    
    cout << r << '\n';
    for (int i = 0; i < idx1; i ++ )
        cout << dplays[i].second << ' ' << d1 << '\n';
    
    for (int i = 0; i < idx2; i ++ )
        cout << pplays[i].second << ' ' << d2 << '\n';
    
}
 
signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(false);
    
    solve();
}
