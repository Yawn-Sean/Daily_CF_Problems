#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
vector<pii> merge(vector<pii> &secs)
{
	vector<pii> res;
	sort(secs.begin(), secs.end());
	int st = -2e9, ed = -2e9;
	for(auto [l, r]: secs) {
		if(ed < l) {
			if(st != -2e9) res.push_back({st, ed});
			st = l;
			ed = r;
		} else ed = max(ed, r);
	}
	if(st != -2e9) 
		res.push_back({st, ed});
	return res;
}
inline void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    unordered_map<int, int> l, r, cnt;
    for(int i=1; i<=n; i++)
        cin >> a[i], cnt[a[i]] ++;
    for(int i=1; i<=n; i++) {
        if(!l.count(a[i]))
            l[a[i]] = i;
    }
    for(int i=n; i>=1; i--) {
        if(!r.count(a[i]))
            r[a[i]] = i;
    }
    vector<pii> secs;
    for(auto [val, pos]: l) {
        secs.push_back({pos, r[val]});
    }
    secs = merge(secs);
    int sz = secs.size();
    vector<int> v(sz+5);
    for(auto [val, pos]: l) {
        int L = 0, R = sz-1;
        while(L < R) {
            int mid = L+R+1 >> 1;
            if(secs[mid].first <= pos) L = mid;
            else R = mid - 1;
        }
        v[L] = max(v[L], cnt[val]);
    }
    int res = 0;
    for(int i=0; i<sz; i++) {
        res += (secs[i].second - secs[i].first + 1) - v[i];
        // cout << secs[i].first << " " << secs[i].second << " " << v[i] << endl;
    }
    cout << res << endl;
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
