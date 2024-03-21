// 考虑将数分为两部分，即"1689"和其他，要满足(x*10000 + y) % 7 == 0,根据题意可以猜想"1689"的全排列 % 7可以为0-6，
// 可以用个dfs验证，这样我们就可以前面随便拍，后面补上一个数使得余数为0即可。
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////

void solve() 
{
    string s;
    cin >> s;
    vector<int> cnt(10);
    for (char c: s) {
        cnt[c-'0'] ++;
    }
    cnt[1] --; cnt[6] --; cnt[8] --; cnt[9] --;
    int k = 0, mod = 7;
    string ans;
    for (int i = 9; i > 0; i -- ) {
        for (int j = 0; j < cnt[i]; j ++ ) {
            ans += '0' + i;
            k = (k * 10 + i) % mod;
        }
    }

    k = (k * 10000) % mod;
    if (k == 0) ans += "1869";
    else if (k == 1) ans += "1896";
    else if (k == 2) ans += "1986";
    else if (k == 3) ans += "1698";
    else if (k == 4) ans += "6198";
    else if (k == 5) ans += "1689";
    else if (k == 6) ans += "1968";

    for (int i = 0; i < cnt[0]; i ++ ) ans += '0';

    cout << ans << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    
}