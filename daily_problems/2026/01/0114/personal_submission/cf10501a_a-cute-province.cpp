#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 998244353;
const int N = 1e6 + 10;
vector<int> Next(string s)
{
	int n = s.size();
	vector<int> res(n + 1);
	res[0] = -1;
	res[1] = 0;
	int i = 2, cn = 0;
	while (i <= n)
	{
		if (s[i - 1] == s[cn])
		{
			res[i++] = ++cn;
		}
		else if (cn > 0)
		{
			cn = res[cn];
		}
		else
		{
			i++;
		}
	}
	return res;
}
void solve(){
    int n;
    cin >> n;
    string s, ss;
    cin >> s;
    for(auto &c : s){
        if(c == '1')ss += '0';
        else ss += '1';
    }
    s = s + "#" + ss;
    vector<int> next = Next(s);
    for(int i = n+2; i <= 2*n+1; i ++)cout << next[i] <<' ';
    cout << '\n';

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
