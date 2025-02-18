#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		c1=A 已经输了
		考虑c中A第一次出现的位置 i1
		第二次出现位置 i2
		第三次出现位置 i3
		...
				
		1..i1-1之前的颜色都可能是答案
		i1+1..i2-1 也至少要出现一次
		i2+1..i3-1 也至少要出现一次
		
		给定一个颜色=x 怎么验证x可能是答案
	*/
	int n, A;
	cin >> n >> A;
	
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	map<int,int> cnt;
	int cntA = 0;
	set<int> ok;
	
	for (int i = 0; i < n; i++) {
		if (c[i] == A) {
			++cntA;
		} else {
			if (cnt[c[i]] >= cntA) {
				++cnt[c[i]];
				ok.insert(c[i]);	
			}
		}
	}
	
	for (auto&k : ok) {
		if (cnt[k] >= cntA) {
			cout << k;
			return 0;
		}
	}
	
	cout << -1;
    return 0;
}
