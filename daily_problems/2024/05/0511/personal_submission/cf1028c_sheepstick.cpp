#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<array<int,4>> coor(n);
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < 4; j++){
    		cin >> coor[i][j];
    	}
    }
    if (n == 2){
    	cout << coor[0][0] <<" "<< coor[0][1] << "\n";
    	return;
    }

    array<int,4> cur{INT_MIN, INT_MIN, INT_MAX, INT_MAX};
    array<int,4> left(cur);
    vector<array<int,4>> res(n + 1);
    res[n] = cur;
    for (int i = n - 1; i >= 0; i--){
    	cur[0] = max(cur[0], coor[i][0]);
    	cur[1] = max(cur[1], coor[i][1]);
    	cur[2] = min(cur[2], coor[i][2]);
    	cur[3] = min(cur[3], coor[i][3]);
    	res[i] = cur;
    }

    auto check = [&](array<int,4> &a, array<int,4> &b) -> array<int,2> {
    	if (a[2] >= b[0] && b[2] >= a[0] && a[3] >= b[1] && b[3] >= a[1]){
    		return {min(a[2], b[2]), min(a[3], b[3])};
    	}
    	else return {(int)-1E9 - 5, -1};
    };

    for (int i = 0; i < n; i++){
    	if (res[i + 1][0] <= res[i + 1][2] && res[i + 1][1] <= res[i + 1][3]){
    		auto x = check(left, res[i + 1]);
    		if (x[0] != -1E9 - 5) {
    			cout << x[0] <<" "<< x[1] << "\n";
    			return;
    		}
    	}
    	left[0] = max(left[0], coor[i][0]);
    	left[1] = max(left[1], coor[i][1]);
    	left[2] = min(left[2], coor[i][2]);
    	left[3] = min(left[3], coor[i][3]);
    }





}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}