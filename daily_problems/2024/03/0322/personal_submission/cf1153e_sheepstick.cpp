#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int ask(int x1, int x2, int y1, int y2) {
	cout << "? "<< x1 << " " << y1 <<" "<< x2 << " "<< y2 << endl;
	int z; cin >> z;
	return z;
}

int askRow(int row, int y1, int y2){
	return ask(row, row, y1, y2);
}

int askCol(int col, int x1, int x2){
	return ask(x1, x2, col, col);
}


void solve() {
	int n; cin >> n;
	//ask everyrow
	vector<int> candidates;

	for (int i = 1; i <= n; i++){
		int res = askRow(i, 1, n);
		if (res % 2) candidates.push_back(i);
	}
	vector<int> ans;
	if ( (int) candidates.size() == 2){ //found on horizontal strip
		for (int j = 0; j < 2; j++){
			//binary search
			int l = 1, r = n;
			while(l < r){
				int mid = (l + r) / 2;
				int z = askRow(candidates[j], l, mid);
				if (z % 2){
					r = mid;
				}
				else l = mid + 1;
			}
			ans.push_back(candidates[j]);
			ans.push_back(l);
		}
	}
	else {
		//retry vertical strip
		for (int i = 1; i <= n; i++){
			int res = askCol(i, 1, n);
			if (res % 2) candidates.push_back(i);
		}
		//must have 2 candidates
		//binary search
		int l = 1, r = n;
		while(l < r){
			int mid = (l + r) / 2;
			int z = askCol(candidates[0], l, mid);
			if (z % 2){
				r = mid;
			}
			else l = mid + 1;
		}
		ans.push_back(l);
		ans.push_back(candidates[0]);
		ans.push_back(l);
		ans.push_back(candidates[1]);
		
	}
	cout << "! " << ans[0] <<" "<< ans[1] <<" "<< ans[2] << " "<< ans[3] << endl;


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}