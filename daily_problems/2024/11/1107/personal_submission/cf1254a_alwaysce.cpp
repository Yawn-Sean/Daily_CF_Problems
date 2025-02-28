#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;
string ans = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		考虑R 每个分量内部R的数量都是可以确定的
	*/
	int t;
	cin >> t;
	while (t--) {
		int r, c, k;
		cin >> r >> c >> k;
		
		int rcnt = 0;
		vector<vector<char>> mat(r, vector<char>(c));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> mat[i][j];
				if (mat[i][j] == 'R') {
					++rcnt;
				}
			}
		}
		
		int need = rcnt / k;
		int add = (rcnt % k);
		int rank = 0;
		
		bool f = true;
		int cur_r = 0, cur_c = 0, cnt = 0;
		while (true) {
			begin:
				if (rank >= k) { break; }
				int cur = (need + (rank < add ? 1 : 0));
			
			while (cur_r < r) {
				if (f) {
					if (cur_c < 0) { cur_c = 0; }
					while (cur_c < c) { 
						cnt += (mat[cur_r][cur_c] == 'R');
						mat[cur_r][cur_c] = ans[rank];
						++cur_c;

						if (cnt >= cur) {
							cnt = 0;
							++rank;
							goto begin;
						}
					}
				} else {
					if (cur_c >= c) { cur_c = c - 1; }
					while (cur_c >= 0) { 
						cnt += (mat[cur_r][cur_c] == 'R');
						mat[cur_r][cur_c] = ans[rank];
						--cur_c; 

						if (cnt >= cur) {
							cnt = 0;
							++rank;
							goto begin;
						}
					}
				}	
							
				// 按照一行的顺序来回翻转
				++cur_r;
				f = !f;
			}
		}
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (mat[i][j] == '.') { mat[i][j] = ans[rank - 1]; }
				cout << mat[i][j];
			}
			cout << '\n';
		}
	}
	
	
    return 0;
}
