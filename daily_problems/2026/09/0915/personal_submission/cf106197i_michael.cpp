#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<vector<char>> grid(n,vector<char>(n));
	for(auto &row : grid) for(auto &col : row) cin >> col;
	vector<int> firstH(n,-1);
	bool flag = true;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(grid[i][j] == 'H'){
				firstH[i] = j;
				break;
			}
		}
		if(firstH[i] == -1){
			flag = false;
			break;
		}
	}
	if(flag){
		cout << n << '\n';
		for(int i = 0; i < n; ++i){
			cout << i + 1 << " " << firstH[i] + 1 << '\n';
		}
		return;
	}

	vector<int> firstV(n,-1);
	for(int j = 0; j < n; ++j){
		for(int i = 0; i < n; ++i){
			if(grid[i][j] == 'V'){
				firstV[j] = i;
				break;
			}
		}
	}

	cout << n << '\n';
	for(int j = 0; j < n; ++j){
		cout << firstV[j] + 1 << " " << j + 1 << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}