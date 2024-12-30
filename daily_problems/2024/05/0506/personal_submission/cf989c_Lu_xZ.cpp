#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 50;

char g[N][N];


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	for(int i = 0; i < 50; ++ i) {
		for(int j = 0; j < 50; ++ j) {
			g[i][j] = "ABCD"[(i / 25) << 1 | (j / 25)];
		}
	}
	
	int a, b, c, d; cin >> a >> b >> c >> d;
	-- a, -- b, -- c, -- d;
	
	for(int i = 0; d && i < 25; i += 2) {
		for(int j = 0; d && j < 25; j += 2, -- d) {
			g[i][j] = 'D';
		}
	}
	
	for(int i = 0; c && i < 25; i += 2) {
		for(int j = 25; c && j < 50; j += 2, -- c) {
			g[i][j] = 'C';
		}
	}
	
	for(int i = 25; b && i < 50; i += 2) {
		for(int j = 0; b && j < 25; j += 2, -- b) {
			g[i][j] = 'B';
		}
	}
	
	for(int i = 25; a && i < 50; i += 2) {
		for(int j = 25; a && j < 50; j += 2, -- a) {
			g[i][j] = 'A';
		}
	}
	
	cout << 50 << ' ' << 50 << '\n';
	
	for(int i = 0; i < 50; ++ i) {
		for(int j = 0; j < 50; ++ j) {
			cout << g[i][j];
		}
		cout << '\n';
	}
	return 0;
}
