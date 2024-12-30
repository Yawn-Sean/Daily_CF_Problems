#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k, m;

	
int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> k;
	
	map<int, int, greater<int>> mp;
	for(int i = 1; i <= k + 1; ++ i) {
		
		cout << "? ";
		
		for(int j = 1; j <= k + 1; ++ j) {
			if(j != i) {
				cout << j << ' ';
			}
		}
		cout << endl;
		
		int p, v; cin >> p >> v;
		mp[v] ++;
	}
	
	cout << "! " << mp.begin() -> second << endl;
	return 0;
}
