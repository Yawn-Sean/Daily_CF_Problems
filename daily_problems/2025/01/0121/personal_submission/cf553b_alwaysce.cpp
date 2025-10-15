#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	i64 k;
	cin >> n >> k;
	
	/*
		包含n的环最多是一个二元环
		
		n被x换了 x<n
		
			x
		(x,y,n)
		他把所有长度为 n 且不发生变化的排列
		(n y x)所以就不可能了
		
		排列个数p[k]=p[k-1]+p[k-2]
			
	*/
	vector<i64> fib = {1,1};
	while (fib.size() < 53) {
		int m = fib.size();
		fib.push_back(fib[m-1] + fib[m-2]);
	}
	
	--k;
	vector<int> ans;
	while ((int)ans.size()<n) {
		int l = ans.size();
		if (k >= fib[n - 1 - l]) {
			// 二元环 排在一元环后面，而一元有fib[n-l-1]个 对应于k属于(0..fib[n-l-1]-1)
			ans.push_back(l + 2);
			ans.push_back(l + 1);
			k -= fib[n - 1 - l];
		} else {
			ans.push_back(l + 1);
		}
	}
	for (auto&x: ans) { cout << x << ' '; }
	return 0;
}
