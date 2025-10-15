// https://codeforces.com/problemset/problem/958/F2
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 200010;

int n,m,a[N],b[N],cnt[N],k = 0,sum = 0; 


int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1;i <= n; i++) {
		cin >> a[i];		
	} 
	
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		if (b[i] > 0) ++k;
		sum += b[i];
	}
	
	int l = 1,cur = 0, ans = 1000000;
	
	for (int r = 1; r <= n; r++) {
		int x = a[r],temp = cnt[x];
		cnt[x]++;
		
		if (temp < b[x] && cnt[x] >= b[x]) {
			--k;
		}
		
		
		
		while (k == 0) {
			ans = min(ans,r - l + 1 - sum);
			
			cnt[a[l]]--;
			if (cnt[a[l]] < b[a[l]]) ++k;
			
			++l;
		}
	}
	
	if (ans < 1000000) {
		cout << ans << "\n";
	} else {
		cout << -1 << "\n";
	}
	
	return 0;
}
