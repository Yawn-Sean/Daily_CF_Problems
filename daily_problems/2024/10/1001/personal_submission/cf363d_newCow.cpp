// https://codeforces.com/problemset/problem/363/D

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 100010;
typedef long long ll;

int n,m,a,b[N],cost[N];

bool check(int k) {
	ll sum = 0;
	
	int i = n - k,j = 0;  // i 是 b的下标，j 是 cost 的下标 
	
	while (k--) {
		sum += max(0,cost[j] - b[i]);
		
		++j;++i;
		
		if (i >= n || j >= m) break;
	}

	return sum <= a;
} 

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n >> m >> a;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	
	for (int i = 0; i < m; i++) {
		cin >> cost[i];
	}
	
	sort(b,b + n);
	sort(cost,cost + m);
	
	int l = 0,r = min(n,m),mid;
	while (l < r) {
		mid = (l + r + 1) >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	
	int ans = l,i = 0,j = n - l,sum = 0;
	
	while (l--) {
		sum += cost[i++];
	}
	
	cout << ans << " " << max(sum - a,0) << "\n"; 
	return 0;
}
