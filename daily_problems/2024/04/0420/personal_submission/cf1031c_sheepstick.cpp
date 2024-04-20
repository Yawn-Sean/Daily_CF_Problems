#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	i64 a, b; cin >> a >> b;
	i64 tot = a + b;
	//max hours 
	i64 l = 0, r = tot;
	while(l < r){
		i64 mid = (l + r + 1) / 2;
		if (mid * (mid + 1) / 2 > tot){
			r = mid - 1;
		}
		else l = mid;
	}

	vector<int> fi, se;

	i64 cur = 0;
	int v = 1;
	while(cur < a && v <= l){
		cur += v++;
	}
	int rem = cur - a;
	for (int i = 1; i < v; i++){
		if (i != rem) fi.push_back(i);
	}
	if (rem > 0) se.push_back(rem);
	for (int i = v; i <= l; i++){
		se.push_back(i);
	}
	cout << (int) fi.size() << "\n";
	for (auto v : fi){
		cout << v << " ";
	}
	cout << "\n";
	cout << (int) se.size() << "\n";
	for (auto v : se){
		cout << v << " ";
	}
	cout << "\n";	

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}