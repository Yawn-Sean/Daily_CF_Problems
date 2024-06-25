#include<bits/stdc++.h>
#define endl "\n";
typedef  unsigned long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int>arr(n);
		for (int i = 0; i < n; i++)cin >>arr[i];
		sort(arr.begin(), arr.end());
		int minx = 1000000000;
		ll ans = 0;
		for(int i=0;i<n-k;i++){
			if (arr[i + k] - arr[i] < minx) {
				minx = arr[i + k] - arr[i];
				ans = (arr[i + k]+arr[i]) / 2;
			}
		}
		cout << ans << endl;
	}
}
