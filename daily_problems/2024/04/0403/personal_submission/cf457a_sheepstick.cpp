#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	string a, b; cin >> a >> b;

	int l1 = a.length(), l2 = b.length();
	int l = max(l1, l2);
	if (l == 1){
		cout << (a == b ? "=\n" : (a > b ? ">\n" : "<\n"));
		return;
	}

	if (l1 < l) a = string(l - l1, '0') + a;
	if (l2 < l) b = string(l - l2, '0') + b;

	vector<int> diff(l, 0);
	for (int i = 0; i < l; i++){
		diff[i] += (a[i] == '1');
		diff[i] -= (b[i] == '1');
		if (diff[i] >= 2){
			cout << ">\n";
			return;
		}
		else if (diff[i] <= -2){
			cout << "<\n";
			return;
		}
		else if (i < l - 2){
			diff[i + 1] += diff[i];
			diff[i + 2] += diff[i];
		}
	}

	if (diff[l - 2] == 0 && diff[l - 1] == 0){
		cout << "=\n";
		return;
	}
	else {
		double v = diff[l - 2] * 1.0 * (sqrt(5) + 1) / 2 + diff[l - 1];
		if (v > 0){
			cout << ">\n";
		}
		else cout << "<\n";
	}

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}