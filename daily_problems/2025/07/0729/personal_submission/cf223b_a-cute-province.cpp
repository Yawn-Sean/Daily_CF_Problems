#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6 + 10;
const int mod = 998244353;
/*
    对于s的每个字符，在t中找到满足条件的相同字符就可以，对于是s[i], 在t中找到t[j], 满足s[i] == t[j]&&
    s[0, i-1]的子序列有t[0,j-1]&&s[i+1, n-1]的子序列有t[j+1,n-1]
*/
void solve()
{
    string s, t;
    cin >> s >> t;
    if(t.size() > s.size()){
        cout << "No" << '\n';
        return ;
    }
    int n = s.size();
    vector<int> l(n), r(n), w[26];
    for(int i = 0 ; i < t.size(); i ++)w[t[i]-'a'].emplace_back(i);
    for(int i = 0, j = 0; i < n;i ++){
        if(s[i] == t[j]){
            j++;     
        }
        l[i] = j;
    }
    for(int i = n-1, j = t.size()-1; i >= 0;i --){
        if(s[i] == t[j]){
            j--;
        }
        r[i] = j;
    }
    int ok = 1;
    for(int i = 0 ; i < n; i++){
        int c = s[i]-'a';
        int p = upper_bound(w[c].begin(), w[c].end(), l[i]) - w[c].begin();
        if(p == 0 || w[c][p-1] < r[i]){
            ok = 0;
        }
        //cout << ok <<' ' <<i << '\n';
    }
    if(ok)cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流
     int t;
     //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }
     return 0;
}
