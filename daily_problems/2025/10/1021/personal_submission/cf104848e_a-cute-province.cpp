#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e5 + 3;
const int N = 2e3 + 10;
void solve()
{  
    int t;
	cin >> t;

	map<long long, long long> mp;
	mp[12] = 48;
	mp[15] = 5055;
	mp[18] = 288;
	mp[21] = 7077;
	mp[24] = 8088;
	mp[27] = 3699;
	mp[36] = 48888;
	mp[45] = 5055555555ll;
	mp[54] = 222888888;
	mp[63] = 111888;
	mp[72] = 8088888888ll;
	mp[81] = 9099999999ll;

	while (t --) {
		long long n;
		cin >> n;

		auto pt = mp.find(n);
		if (pt != mp.end()) cout << pt->second << '\n';
		else {
			set<int> st;
			long long x = n;
			while (x) {
				st.insert(x % 10);
				x /= 10;
			}
			cout << (st.size() == 1 ? n : -1) << '\n';
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
    t = 1;
   
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
