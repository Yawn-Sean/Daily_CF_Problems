#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*	
		先找到所有的合法子矩阵
	*/
	int n, m, q;
	cin >> n >> m >> q;
	
	vector<vector<int>> grid(n + 1, vector<int>(m + 1));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			grid[i+1][j+1] = (s[j]-'0');
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			grid[i+1][j] += grid[i][j];
		}
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			grid[i][j + 1] += grid[i][j];
		}
	}
	
	auto f = [&](int i1, int i2, int j1, int j2) {
		return (((i1*n)+i2) * m + j1)*m + j2;
	};
	
	
	/*
		然后对于 (a,b,c,d) 处理合法的组合数量
		从a行到c行, 
		b->d
		sum (ok[x][y][l1][l2]), a<=x<=c, b<=y<=d

		可以用 4维前缀和
		但是要修改一下顺序

		freq[n-1-a, b, m-1-c, d]
		q + (n2m2)
	*/
	vector<int> freq(n*n*m*m, 0);
	
	for (int i1 = 0; i1 < n; i1 ++) {
        for (int i2 = i1; i2 < n; i2 ++) {
            for (int j1 = 0; j1 < m; j1 ++) {
                for (int j2 = j1; j2 < m; j2 ++) {
                    if (grid[i2 + 1][j2 + 1] - grid[i2 + 1][j1] - grid[i1][j2 + 1] + grid[i1][j1] == 0)
                        freq[f(n - 1 - i1, i2, m - 1 - j1, j2)] = 1;
                }
            }
        }
    }
	
	// 1
	for (int i1 = 0; i1 < n - 1; i1 ++) {
        for (int i2 = 0; i2 < n; i2 ++) {
            for (int j1 = 0; j1 < m; j1 ++) {
                for (int j2 = 0; j2 < m; j2 ++) {
                    freq[f(i1 + 1, i2, j1, j2)] += freq[f(i1, i2, j1, j2)];
                }
            }
        }
    }

    for (int i1 = 0; i1 < n; i1 ++) {
        for (int i2 = 0; i2 < n - 1; i2 ++) {
            for (int j1 = 0; j1 < m; j1 ++) {
                for (int j2 = 0; j2 < m; j2 ++) {
                    freq[f(i1, i2 + 1, j1, j2)] += freq[f(i1, i2, j1, j2)];
                }
            }
        }
    }

    for (int i1 = 0; i1 < n; i1 ++) {
        for (int i2 = 0; i2 < n; i2 ++) {
            for (int j1 = 0; j1 < m - 1; j1 ++) {
                for (int j2 = 0; j2 < m; j2 ++) {
                    freq[f(i1, i2, j1 + 1, j2)] += freq[f(i1, i2, j1, j2)];
                }
            }
        }
    }

    for (int i1 = 0; i1 < n; i1 ++) {
        for (int i2 = 0; i2 < n; i2 ++) {
            for (int j1 = 0; j1 < m; j1 ++) {
                for (int j2 = 0; j2 < m - 1; j2 ++) {
                    freq[f(i1, i2, j1, j2 + 1)] += freq[f(i1, i2, j1, j2)];
                }
            }
        }
    }
	
	while (q--) {
		int i1, i2, j1, j2;
		cin >> i1 >> j1 >> i2 >> j2;
		cout << freq[f(n-i1, i2-1, m-j1, j2-1)] << '\n';
	}
	
	return 0;
}

