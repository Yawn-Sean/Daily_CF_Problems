#include<bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	ifstream fin("dotak.in");
 
	int t;
	fin >> t;
 
	while (t --) {
		int n, k;
		fin >> n >> k;
 
		int v = 1ll * n * k % (k + 1);
		cout << ((v & 1) || (v == k) ? "Omda" : "Teemo") << '\n';
	}
 
	return 0;
}
