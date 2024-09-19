#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template<>
int MInt<0>::Mod = 998244353;

template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 998244353;
using Z = MInt<P>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// Z::setMod(998244353);
	
	int n;
	cin >> n;
	vector<int> k(n);
	vector<vector<int>> items(n);
	map<int,int> freq;
	
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j++) {
			int tmp;
			cin >> tmp;
			items[i].push_back(tmp);
			freq[tmp]++;
		}
	}
	
	Z ans = 0;
	for (int i = 0; i < n; i++) {
		Z base = 1;
		base /= n;
		base /= k[i];
		for (auto& j: items[i]) {
			// base的概率选到 j 物品
			// 选对物品j z的概率
			// 1/n * 1/k[i]
			ans += base * freq[j] / n;
		}
	}
	
	cout << ans << '\n';
    return 0;
}
