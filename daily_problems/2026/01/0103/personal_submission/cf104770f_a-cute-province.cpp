#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;

void solve()
{
    int n;
	cin >> n;
	vector<int> nums(n);
	for (auto &v: nums) cin >> v;
	sort(nums.begin(), nums.end());

	vector<int> cnt(n, 0);
	for (auto &x: nums)
		cnt[lower_bound(nums.begin(), nums.end(), x) - nums.begin()] ++;

	vector<vector<int>> vals(n);
	int c = 0;

	for (int i = 0; i < n; i ++) {
		if (cnt[i]) {
			vals[i].emplace_back(nums[i]);
			cnt[i] --;
			c ++;
		}
	}

	if (2 * c - 1 != n) cout << -1;
	else {
		int cur = (n + 1) / 2;
		while (cur > 1) {
			vector<int> p1, p2;
			for (int i = 0; i < n; i ++) {
				if (vals[i].size()) {
					if (cnt[i]) p1.emplace_back(i);
					else p2.emplace_back(i);
				}
			}

			if (p1.size() != p2.size()){
                cout << -1;
                return ;
            }

			for (int i = 0; i < p1.size(); i ++) {
				int x = p1[i], y = p2[i];
				if (x > y){
                    cout << -1;
                    return;
                }
				for (auto &v: vals[y]) vals[x].emplace_back(v);
				vals[y].clear();
				cnt[x] --;
			}

			cur = (cur) / 2;
		}

		for (auto &v: vals[0]) cout << v << ' ';
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
