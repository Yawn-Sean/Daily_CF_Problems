#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 60;
void solve() {
	int q; cin >> q;
	vector<i64> shift(M, 0);
	while(q--){
		int op; cin >> op;
		if (op == 1){
			i64 x, k; cin >> x >> k;
			int layer = __lg(x);
			shift[layer] = (shift[layer] + k % (1LL << layer)) % (1LL << layer);
			if (shift[layer] < 0) shift[layer] += 1LL << layer;

		} else if (op == 2){
			i64 x, k; cin >> x >> k;
			int layer = __lg(x);
			k = (k % (1LL << layer) + (1LL << layer)) % (1LL << layer);
			//cerr << k << "---\n";
			for (int j = layer; j < M; j++, k *= 2){
				shift[j] = (shift[j] + k) % (1LL << j);
			}
		}
		else {
			i64 x; cin >> x;
			int layer = __lg(x);
			x = (1LL << layer) + (x - (1LL << layer) + shift[layer]) % (1LL << layer);
			do {
				layer = __lg(x);
				i64 v = (x - shift[layer]) % (1LL << layer) + (1LL << layer);
				cout << v << " ";
				if (v == 1) break;
				x /= 2;
			} while (true);
			cout << "\n";
		}
	}

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}