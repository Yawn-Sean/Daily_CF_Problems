#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	/*
		暴力枚举(0,0)放1-1,1-2,2-1,2-2,3-1,3-2
		左上
		下方放某一个
		
		最后剩下的检查一下
	*/
	
	for (int i = 0; i < 2; i++) {
		swap(x1, y1);
		for (int j = 0; j < 2; j++) {
			swap(x2, y2);
			for (int k = 0; k < 2; k++) {
				swap(x3, y3);
				
				if (y1 == y2 and y2 == y3 and x1 + x2 + x3 == y2) {
					cout << y1 << '\n';
					vector<string> grid(y1, string(y1, ' '));
					
					for (int i = 0; i < x1; i++) {
						for (int j = 0; j < y1; j++) {
							grid[i][j] = 'A';
						}
					}
					for (int i = x1; i < x1+x2; i++) {
						for (int j = 0; j < y1; j++) {
							grid[i][j] = 'B';
						}
					}
					for (int i = x1+x2; i < x1+x2+x3; i++) {
						for (int j = 0; j < y1; j++) {
							grid[i][j] = 'C';
						}
					}
					for (auto&s: grid) {cout<<s<<'\n';}
					return 0;
				}
				
				if (y1 == y2 + y3 and x2 == x3 and x1 + x2 == y1) {
					cout << y1 << '\n';
					vector<string> grid(y1, string(y1, ' '));
					
					for (int i = 0; i < x1; i++) {
						for (int j = 0; j < y1; j++) {
							grid[i][j] = 'A';
						}
					}
					for (int i = x1; i < x1+x2; i++) {
						for (int j = 0; j < y2; j++) {
							grid[i][j] = 'B';
						}
					}
					for (int i = x1; i < x1+x2; i++) {
						for (int j = y2; j < y2 + y3; j++) {
							grid[i][j] = 'C';
						}
					}
					for (auto&s: grid) {cout<<s<<'\n';}
					return 0;
				}
				
				if (y2 == y1 + y3 and x1 == x3 and x1 + x2 == y2) {
					cout << y2 << '\n';	
					vector<string> grid(y2, string(y2, ' '));
					
					for (int i = 0; i < x2; i++) {
						for (int j = 0; j < y2; j++) {
							grid[i][j] = 'B';
						}
					}
					for (int i = x2; i < x2+x1; i++) {
						for (int j = 0; j < y1; j++) {
							grid[i][j] = 'A';
						}
					}
					for (int i = x2; i < x2+x1; i++) {
						for (int j = y1; j < y1 + y3; j++) {
							grid[i][j] = 'C';
						}
					}
					for (auto&s: grid) {cout<<s<<'\n';}
					return 0;
				}
				
				if (y3 == y1 + y2 and x1 == x2 and x1 + x3 == y3) {
					cout << y3 << '\n';	
					vector<string> grid(y3, string(y3, ' '));
					
					for (int i = 0; i < x3; i++) {
						for (int j = 0; j < y3; j++) {
							grid[i][j] = 'C';
						}
					}
					for (int i = x3; i < x1+x3; i++) {
						for (int j = 0; j < y1; j++) {
							grid[i][j] = 'A';
						}
					}
					for (int i = x3; i < x1+x3; i++) {
						for (int j = y1; j < y1 + y2; j++) {
							grid[i][j] = 'B';
						}
					}
					for (auto&s: grid) {cout<<s<<'\n';}
					return 0;
				}
				
			}
		}
	}
	cout << -1;
	return 0;
}
