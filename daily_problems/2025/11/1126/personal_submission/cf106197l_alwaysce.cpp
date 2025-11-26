#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        // 让行和列的和的奇偶性不同就好了
        vector<vector<int>> a(n, vector<int>(n));
        // 1 1 1 1
        // 2 2 2 2
        // 2 2 2 2
        // 。。。
        // 这样 所有行是偶数 所有列是奇数
        // 接下来就是让行/列的和不同
        // 那么给上三角区域全部加上一个offset
        // 因为每行/每列被加到的不一样 而且原先每行/每列的起始一样 
        // 所以最终不一样
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = 2;
                if (j == 0) a[i][j] = 1;
                if (j >= i) a[i][j] += 2;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
	return 0;
}
