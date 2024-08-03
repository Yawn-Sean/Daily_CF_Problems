// problem link: https://codeforces.com/contest/1102/problem/F
// submission link: https://codeforces.com/contest/1102/submission/255951154
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int M = 16;
const int N = 1 << 16;
int memo[N][M][M];
int neighbor_dis[M][M];
int last_first_dis[M][M];
int dp(int mask, int bi, int ei, vector<vector<int>>& grid, int R, int C){
	/*
	 * bi: begin index
	 * ei: end index
	*/
	if (memo[mask][bi][ei] != -1) return memo[mask][bi][ei];
	if (__builtin_popcount(mask) == 1) return INF;
	int ret = 0;
	int prev_ei, prev_mask, this_ret;
	bool check_last_first = __builtin_popcount(mask) == R;
	prev_mask = mask ^ (1 << ei);
	for (int idx = 0; idx < R;++idx){
		if (idx == ei) continue;
		if (mask & (1 << idx)){
			prev_ei = idx;
			if (__builtin_popcount(prev_mask) >= 2){
				if (prev_ei == bi) continue;
			}
			this_ret = dp(prev_mask, bi, prev_ei, grid, R, C);
			this_ret = min(this_ret, neighbor_dis[prev_ei][ei]);
			if (check_last_first){
				this_ret = min(this_ret, last_first_dis[ei][bi]);
			}
			ret = max(ret, this_ret);
		}
	}
	return memo[mask][bi][ei] = ret;
}

int main(){
	int R, C;
	cin >> R >> C;
	vector<vector<int>> grid(R, vector<int>(C));
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> grid[i][j];
		}
	}
	memset(memo, -1, sizeof(memo));
	if (R == 1){
		int ret = INF;
		for (int i = 0; i < C-1; i++){
			ret = min(ret, abs(grid[0][i] - grid[0][i+1]));
		}
		cout << ret << endl;
		return 0;
	}
	int ret = 0;
	int full_mask = (1 << R) - 1;
	memset(neighbor_dis, 0x3f, sizeof(neighbor_dis));
	memset(last_first_dis, 0x3f, sizeof(last_first_dis));
	for (int i = 0; i < R - 1;  ++i){
		for (int j = i + 1; j < R; ++j){
			for (int k = 0; k < C; ++k){
				neighbor_dis[i][j] = min(neighbor_dis[i][j], abs(grid[i][k] - grid[j][k]));
				neighbor_dis[j][i] = neighbor_dis[i][j];
				if (k < C - 1){
					last_first_dis[i][j] = min(last_first_dis[i][j], abs(grid[i][k] - grid[j][k+1]));
					last_first_dis[j][i] = min(last_first_dis[j][i], abs(grid[j][k] - grid[i][k+1]));
				}
			}
		}
	}
	for (int bi = 0; bi < R; bi++){
		for (int ei = 0; ei < R; ei++){
			if (bi == ei) continue;
			ret = max(ret, dp(full_mask, bi, ei, grid, R, C));
		}
	}
	cout << ret << endl;
	return 0;
}

