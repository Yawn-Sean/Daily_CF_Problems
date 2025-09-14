#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;
vector<int> Next(string s){
    int n = s.size();
    vector<int> res(n+1);
    res[0] = -1;
    res[1] = 0;
    int i = 2, cn = 0;
    while(i <= n){
        if(s[i-1] == s[cn]){
            res[i++] = ++ cn;
        }
        else if(cn > 0){
            cn = res[cn];
        }
        else{
            i ++;
        }
    }
    return res;
}
vector<int> kmp(string s1, string s2){
    vector<int> next = Next(s2), res;
    s2 += '#';
    int n = s1.size(), m = s2.size();
    int i = 0, j = 0;
    while(i < n && j < m){
        if(s1[i] == s2[j]){
            i ++;
            j ++;
            if(j == m-1 && i - m + 1 >= 0)res.push_back(i - m + 1);
        }
        else if(j > 0){
            j = next[j];
        }
        else{
            i ++;
        }
    }
    return res;
}
void solve()
{
    string A, B;
    getline(cin, A);
    getline(cin, B);
    int n;
    cin >> n;
    int l = 0, r = B.size();
    while(l < r){
        int mid = (l + r) / 2 + 1;
        string s = B.substr(0, mid);
        vector<int> p = kmp(A, s);
        if(p.size() >= n)l = mid;
        else r = mid - 1;
    }
    if(l)cout << B.substr(0, l) << '\n';
    else cout << "IMPOSSIBLE" << '\n';
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
