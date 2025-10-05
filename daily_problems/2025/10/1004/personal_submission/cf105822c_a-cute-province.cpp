#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(auto &c : s)if(c == 'E')cnt++;
    if(cnt&1){
        cout <<"NO" << '\n';
        return ;
    }
    vector<int> even, odd;
    for(int i = 2*n; i >= 1; i --){
        if(i&1)odd.emplace_back(i);
        else even.emplace_back(i);
    }
    cout << "YES" << '\n';
    for(int i = 0 ; i < n; i ++){
        if(s[i] == 'O'){
            cout << odd.back() <<' ' << even.back() << '\n';
            odd.pop_back();
            even.pop_back();
        }
        else{
            if(odd.size() >= even.size()){
                cout << odd.back() <<' ';
                odd.pop_back();
                cout << odd.back() <<'\n';
                odd.pop_back();
            }
            else{
                cout << even.back() <<' ';
                even.pop_back();
                cout << even.back() <<'\n';
                even.pop_back();
            }
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
    cin >> t;
    //t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
