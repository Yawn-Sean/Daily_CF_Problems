#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> b(n), seen(2*n);
		
		for (auto& x: b) { cin >> x; seen[x-1]=1; }
		vector<int> nb;
		for (int i = 0; i < 2*n; i++) {
			if (!seen[i]) { nb.push_back(i+1); }
		}
		
		/*
			假设已知取min的有x组
			n-x组取max
			
			b1, b2, ..., bn
			怎么绑定'另一个元素'
			
			暴力模拟是否可行? 并不直观
			
			剩余 = nb1,nb2,...,nbn
			
			取x个min n-x个max
			配对(b1....bx) 与nb中最大的
			(bx+1..bn) 与nb中最小的是最优的
			
			固定x是否有效 
			x->x+1
			bx+1 -> nb(n-x-1+i)是否有效即可
			
		*/
		// for (auto&x:b) {cout <<x << ' ';}
		// cout<<endl;
		// for (auto&x:nb){cout<<x<< ' ';}
		// cout<<endl;
		
		auto check = [&](vector<int>&b, vector<int>&nb, int x) {
			for (int i = 0; i < x; i++) {
				if (b[i] >= nb[n - x + i]) {
					return false;
				}
			}
			return true;
		};
		
		bool find = true;
		// xmax - xmin(n-x's max) +1
		vector<int> ans(2, -1);
		for (int r = 0; r < 2; r++) {
			int left = 0, right = n + 1;
			while (left < right) {
				int mid = (left + right) / 2;
				if (check(b, nb, mid)) {
					ans[r] = mid;
					left = mid + 1;
				} else {
					right = mid;
				}
			}
			// cout<<ans[r]<<endl;
			if (not check(nb, b, n - ans[r])) {
				cout << 0 << '\n';
				find = false;
				break;
			} else {
				swap(b, nb);			
			}
		}
		
		if (find) {
			cout << ans[0] - (n - ans[1]) + 1 << '\n';		
		}
	}	
	return 0;
}
