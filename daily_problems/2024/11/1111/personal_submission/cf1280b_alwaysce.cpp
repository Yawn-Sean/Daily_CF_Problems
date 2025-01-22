#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n, m;
		cin >> n >> m;
		
		vector<string> mat(n);
		bool allP = true, allA = true;
		vector<int> cnt1(n), cnt2(m);
		
		for (int i = 0; i < n; i++) {
			cin >> mat[i];
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 'P') { allA = false; }
				else {
					allP = false; 
					++cnt1[i];
					++cnt2[j];
				}
			}
		}
		
		if (allP) {
			cout << "MORTAL\n";
		} else if (allA) {
			cout << 0 << '\n';		
		} else {
			/*
				只需要1次的情况有哪些?
					横向
				  AAA L=3 所有的P都在它的上面 / 下面
				  	纵向
				  A
				  A
				  A
				  所有的P都在它的左边/右边=>有一条边都是A 且在边界
				2次的情况
				[AAA] 上面 下面都有 但是以外的地方都没有P
				[AAA]^T 左边右边都有
				全A边在中间行列 / 四个角包含A			
				3次
				角没有A 边上有A
			*/
			if (cnt1[0] == m or cnt1[n - 1] == m or cnt2[0] == n or cnt2[m - 1] == n) {
				cout << 1 << '\n';
			} else if (mat[0][0] == 'A' or mat[0][m - 1] == 'A' or mat[n - 1][0] == 'A' or mat[n - 1][m - 1] == 'A' or *max_element(cnt1.begin(), cnt1.end()) == m or *max_element(cnt2.begin(), cnt2.end()) == n) {
				cout << 2 << '\n';
			} else if (cnt1[0] > 0 or cnt1[n - 1] > 0 or cnt2[0] > 0 or cnt2[m - 1] > 0) {
				cout << 3 << '\n';
			} else {
				cout << 4 << '\n';
			}
		}
	}
    return 0;
}
