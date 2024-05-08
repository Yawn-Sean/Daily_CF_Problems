#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	i64 n, b; cin >> n >> b;

	vector<array<i64,2>> fac;
	for (i64 i = 2; i * i <= b; i++){
		if (b % i == 0){
			i64 cnt = 0;
			while(b % i == 0){
				cnt++;
				b /= i;
			}
			fac.push_back({i, cnt});
		}
	}
	if (b != 1) fac.push_back({b, 1});

	i64 res = LLONG_MAX;
	for (auto [x, y] : fac){
		i64 cnt = 0, multi = x, v = n;
		while(v >= multi){
			cnt += v / multi;

			if (1E18 / multi < x) break;
			multi *= x;
		}
		res = min(res, cnt / y);
	}

	cout << res << "\n";


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}