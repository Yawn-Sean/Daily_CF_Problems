#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, k; cin >> n >> k;
	map<int,int> freq;
	auto askWithout = [&](int ban) -> void {
		cout << "?";
		for (int i = 1; i <= k + 1; i++) if (i != ban){
			cout << " " << i;
		}
		cout << endl;
		int pos, val; cin >> pos >> val;
		freq[val]++;
	};
	//if the missing val <= [m]-th order, [m + 1]-th value returned
	//if the missing val > [m]-th order [m]-th value returned
	for (int i = 1; i <= k + 1; i++){
		askWithout(i);
	}

	cout << "! " << (freq.rbegin() -> second) << endl;

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}