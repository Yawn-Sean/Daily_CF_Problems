#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
// *** 1/2
// **. 1
// *.* 0
// .*. 0
void solve()
{   
    int n;
    cin >> n;
    int cnt = 0, sum = 0;
    for(int i = 1; i <= n; i ++){
        string s;
        cin >> s;
        if(s[0] != '=')s = s.substr(0, 3);
        else s = s.substr(3, 3);
        int p = 0;
        for(auto &c : s)if(c == 'x')p++;
        if(p == 3)cnt++;
        if(p == 2 && s[1] == 'x')sum++;
    }
    
    if(cnt == 0){
        if(sum & 1){
            cout << "Monocarp\n"; 
        }
        else{
            cout << "Polycarp\n";
        }
    }
    else{
        
        if(cnt %2 == 0 && sum % 2 == 0){
            cout << "Polycarp\n";
        }
        else {
            cout << "Monocarp\n";
        }
    }
}

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
