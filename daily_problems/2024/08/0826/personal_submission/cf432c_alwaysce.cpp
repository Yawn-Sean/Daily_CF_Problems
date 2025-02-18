#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int mx = 1e5 + 10;
vector<int> isPrime(mx, 1);
// 9592个
vector<int> primes;

void init() {
	isPrime[1] = 0;
	for (int i = 2; i < mx; i++) {
		if (isPrime[i]) {
			for (int j = i + i; j < mx; j += i) {
				isPrime[j] = 0;
			}
			primes.push_back(i);
		}
	}
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(false);
	init();

    int n;
    cin >> n;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<int> pos(n);
	
	// 初始每个元素在a[i]的什么位置
	for (int i = 0; i < n; i++) {
		pos[a[i] - 1] = i;
	}
	
	vector<pair<int,int>> ans;
	for (int i = 0; i < n; i++) {
		// 当前是i的位置 应该放元素值=i+1的元素
		int R = pos[i + 1 - 1];
		
		while (R > i) {
			int L = R - i + 1;
			auto it = lower_bound(primes.begin(), primes.end(), L);
			if (it != primes.begin() and *it > L) {
				--it;
			}
			
			int step = *it;
			// cout << R << '-' << step << '\n';

			// 修改元素所在位置
			if (R - step + 1 < 0 or R >= n) {
				cout << "ERROR\n";
			}
			
			pos[(a[R - step + 1] - 1)] = R;
			pos[(a[R] - 1)] = (R - step + 1);
						
			swap(a[R - step + 1], a[R]);
			
			ans.push_back({R - step + 1, R});
			R -= (step - 1);
		}
		
		// for (auto& v: a) { cout << v << ' ';} 
		// cout << '\n';
	}

	cout << ans.size() << '\n';
	for (auto& [x, y]: ans) {
		cout << x + 1 << ' ' << y + 1 << '\n';
	}
    return 0;   
}
