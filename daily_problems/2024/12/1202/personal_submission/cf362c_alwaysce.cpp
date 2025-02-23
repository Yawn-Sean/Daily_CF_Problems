#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;

inline bool check(i64 x) {
	for (i64 i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
		1. 插入排序的swap执行次数 == 逆序对数量
		2. 考虑i j 元素的交换(i < j)
	
		[0, i-1] [i] [i+1,j-1] [j] [j+1,n-1]
		
		
		[0, i-1] [j] [i+1,j-1] [i] [j+1,n-1]
		
		首先原来别的部分内部不会变化
		
		
		[i+1,j-1] 区间内 大于/小于 nums[i]的元素个数
		大于/小于 nums[j]的元素个数

	*/	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<vector<int>> lt(n + 1, vector<int>(n));
	// lt[i][val]: [0,i]区间上 <val的元素个数
	for (int i = 1; i <= n; i++) {
		for (int val = 0; val <= n - 1; val++) {
			lt[i][val] = lt[i-1][val] + (a[i - 1] < val);
		}
	}
	
	i64 ans = 0;
	i64 dif = 1e9+7, cnt = 0;
	for (int l = 0; l < n; l++) {
		for (int r = l + 1; r < n; r++) {
			int x = a[l], y = a[r];
			i64 tmp = (x < y) ? 1 : -1;
			
			// [i+1,j-1]上面比y小的
			i64 cnty1 = lt[r][y] - lt[l+1][y];
			// >y
			i64 cnty2 = r-1-l - cnty1;
			tmp += cnty1 - cnty2;
			
			// [i+1,j-1]上面比x小的
			i64 cntx1 = lt[r][x] - lt[l+1][x];
			i64 cntx2 = r-1-l - cntx1;
			tmp += cntx2 - cntx1;
			
			if (tmp < dif) {
				dif = tmp;
				cnt = 1;
			} else if (tmp == dif) {
				cnt++;
			}
			ans += (a[l] > a[r]);
		}
	}
	
	cout << ans + dif << ' ' << cnt;
	return 0;
}
