#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll inf64 = 0x3f3f3f3f3f3f3f3f;
constexpr int inf32 = 0x3f3f3f3f;

void solve()
{	
	int n; cin >> n;

	vector<int> s(n + 1), g(n + 1), sum(n + 1);
	
	int flag = 1;
	for(int i = 1; i <= n; i++) {
		cin >> s[i] >> g[i];
		sum[i] = s[i] + g[i];
		if(i >= 2) {
			if(s[i] > sum[i - 1] + 1){
				flag = 0;
				break;

			}	
			sum[i] = min(sum[i - 1] + 1, sum[i]);
		}
	}

	if(flag) for(int i = n - 1; i >= 1; i--) {
		if(s[i] > sum[i + 1] + 1) {
			flag = 0;
			break;
		}
		sum[i] = min(sum[i + 1] + 1, sum[i]);
	}

	if(flag) {
		ll tol = 0;
		for(int i = 1 ; i <= n; i++) {
			tol += sum[i] - s[i] * 1ll;
		}
		cout << tol << char(10);
		for(int i = 1; i <= n; i++) {
			cout << sum[i] << ' ';
		}
	} else {
		cout << -1;
	}
	cout << char(10);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	// cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}
