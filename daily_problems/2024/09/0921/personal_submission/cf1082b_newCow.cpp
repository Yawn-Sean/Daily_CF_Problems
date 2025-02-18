// https://codeforces.com/problemset/problem/1082/B
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 100010;

int n;
char s[N];
int main() {
	cin >> n;
	
	cin >> s + 1;
	int l = 1,cnt = 0,cnt_g = 0,ans = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'G') ++cnt_g;
	}
	for (int r = 1; r <= n; r++) {
		if (s[r] == 'S') {
			++cnt;
		}
		
		while (cnt >= 2) {
			cnt -= (s[l] == 'S' ? 1 : 0);
			l += 1;
		}
		
		
		if (cnt == 0) {
			ans = max(ans,r - l + 1);
		} 
			
		if (cnt == 1) {
			ans = r - l + 1 <= cnt_g ? max(ans,r - l + 1) : ans;
		}
		
	}
	
	cout << ans << endl;
	return 0;
} 
