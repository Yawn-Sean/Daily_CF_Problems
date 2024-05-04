#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5;

int cnt[N];
map<int, int> ccnt;

void del(int x) {
	if(-- ccnt[x] == 0) {
		ccnt.erase(x);
	} 
}
void add(int x) {
	if(cnt[x]) del(cnt[x]);
	++ ccnt[++ cnt[x]];
}

int n, ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	
	for(int i = 1; i <= n; ++ i) {
		int x; cin >> x;
	
		add(x);
		if(ccnt.size() == 1 && (ccnt.begin() -> first == 1 || ccnt.begin() -> second == 1)) {
			ans = i;
		}
		if(ccnt.size() == 2) {
			int a[2], b[2];
			for(auto i = 0; auto [x, t] : ccnt) {
				a[i] = x;
				b[i ++] = t;
			}
			int ok = 0;
			if(a[1] - a[0] == 1 && b[1] == 1) ok = 1;
			if(a[0] * b[0] == 1) ok = 1;
			if(ok) ans = i;
		}
	}
	
	cout << ans;
	return 0;
}
