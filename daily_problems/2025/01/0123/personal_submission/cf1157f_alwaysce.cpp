#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> a(n);
	int mx = 0;
	for (auto&x: a) { 
		cin >> x; 
		mx = max(mx, x);
	}
	vector<int> cnt(mx + 1);
	for (auto&x: a) {
		++cnt[x];
	}
	
	/*
		x x+1 ..., x+L
		要求: [x+1.. x+L-1]这些元素>=2 头尾无所谓
		那么这些元素总是可以排列成L-circle
		
	*/
	int K = 0;
	int ansL = 0, ansR = 0;
	for (int i = 1; i <= mx; ) {
		if (cnt[i] == 0) { 
			i++; continue; 
		}
		
		int tot = cnt[i];
		
		int j = i + 1;
		while (j <= mx and cnt[j] >= 2) {
			tot += cnt[j];
			j++;
		}
		
		// [i ... j-1]是 ok的
		if (j <= mx) {
			// cnt[j]=1
			if (cnt[j] > 0) {
				tot += cnt[j];	
			} else {
				j--;
			}
		} else {
			j -= 1;
		}
		
		if (tot > K) {
			K = tot;
			ansL = i;
			ansR = j;
		}
			
		// [i, i]
		if (i == j) {
			i = j + 1;		
		} else {
			// [i, j] (cnt[j]==1) 那么j可能是下一段的开头
			i = j;
		}
	}
	
	cout << K << '\n';
	// cout << ansL << ' ' << ansR << '\n';
	
	for (int i = ansL; i <= ansR; i++) {
		if (i == ansL or i == ansR) {
			for (int j = 0; j < cnt[i]; j++) {
				cout << i << ' ';
			}
		} else {
			for (int j = 0; j < cnt[i] - 1; j++) {
				cout << i << ' ';
			}
		}
	}
	
	for (int i = ansR - 1; i >= ansL + 1; i--) {
		cout << i << ' ';
	}
	cout << '\n';
	
	return 0;
}
