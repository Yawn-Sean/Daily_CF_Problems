#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> R(n + 1), C(n + 1);
	int x;
	for (int i = 1; i <= n; i ++) {
		cin >> x;
		R[i] = R[i - 1] + x % 2;
	}
	for (int i = 1; i <= n; i ++) {
		cin >> x;
		C[i] = C[i - 1] + x % 2;
	}
	int ra, ca, rb, cb;
	while (q -- ) {
		cin >> ra >> ca >> rb >> cb;
		ra --; ca --; rb --; cb --;
		if (ra > rb) swap(ra, rb);
		if (ca > cb) swap(ca, cb);
		int t1 = R[rb + 1] - R[ra], t2 = C[cb + 1] - C[ca];
		if ((t1 == 0 || t1 == rb - ra + 1) && (t2 == 0 || t2 == cb - ca + 1)){
			cout << "YES";
		}else{
			cout << "NO";
		}
		cout << endl;
	}
	return 0;
}
