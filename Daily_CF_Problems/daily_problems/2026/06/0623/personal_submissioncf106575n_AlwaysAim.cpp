		#include<bits/stdc++.h>
		using namespace std;
		using ll = long long;
		#define pb push_back
		#define pii pair<int,int>
		#define int long long
		#define i128 __int128
    #define ull unsigned long long

        
		void solve()
		{		
			int n;
    		int ca, cb;
    		cin >> n >> ca >> cb;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    vector<int> minb(2 * n + 2, 1e9); 
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        minb[b[i]] = i;
    }

    for (int v = 2 * n; v >= 1; --v) {
        minb[v] = min(minb[v], minb[v + 1]);
    }
    int ans = 3e18;
    for (int i = 0; i < n; ++i) {
        int cost = 1LL * i * ca + 1LL * minb[a[i] + 1] * cb;
        ans = min(ans, cost);
    }

    cout << ans << "\n";
			
		}
		
		
		int32_t main() {
			cin.tie(0)->sync_with_stdio(0);
			int tc = 1;
			cin >> tc;
			while (tc--) solve();
			return 0;
			}
