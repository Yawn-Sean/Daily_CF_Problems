#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	i64 x, y; cin >> x >> y;
	vector<string> names{"Vanya", "Vova"};
	vector<i64> a(n);
	for (auto &ai : a){
		cin >> ai;
	}
	if (x < y) {
		swap(x, y);
		swap(names[0], names[1]);
	}

	for (auto v : a){
		i64 l = 0, r = v;
		while(l < r){
			i64 mid = (l + r) / 2;
			i64 tot = (y * mid) / x + mid;
			if (tot >= v){
				r = mid;
			}
			else l = mid + 1;
		}

		if ((y * l) % x == 0){
			cout << "Both\n";
		}
		else {
			i64 yCnt = (y * l) / x;
			if (yCnt + (x * yCnt) / y >= v){
				cout << names[1] << "\n";
			}
			else cout << names[0] << "\n";
		}
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}