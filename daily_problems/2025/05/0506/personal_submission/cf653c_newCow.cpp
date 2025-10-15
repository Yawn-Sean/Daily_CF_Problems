#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

const int N = 150010;

int n,a[N];
vector<int> b;
// 检查某个下标是否满足条件 
bool checki(int i) {
	if (i == 0 || i == n) {
		return true;
	}
	if (i % 2 == 0) {
		return a[i] > a[i + 1];
	} else {
		return a[i] < a[i + 1];
	}
}

bool check(int i,int idx) {
	if (checki(i) && checki(i - 1) && checki(idx) && checki(idx - 1)) {
		return true;
	}
	
	return false;
}

void f(int i,int j,int &res) {
	swap(a[i],a[j]);
	res += (int)check(i,j);
	swap(a[i],a[j]); 
}

int solve() { 

	for (int i = 1;i < n; i++) {
		if (!checki(i)) {
			b.push_back(i);
		} 
	}
	
	if (b.size() > 4) {
		return 0;
	}
	
	if (b.size() == 4) {
		int res = 0;
		f(b[1],b[3],res);
		return res;
	}
	
	if (b.size() == 3) {
		if (b[1] - b[0] > 1 && b[2] - b[1] > 1) {
			return 0;
		} else if (b[1] - b[0] == 1) {
			int res = 0;
			
			f(b[1],b[2],res);
			f(b[1],b[2] + 1,res);
			f(b[0],b[2],res);
			
			return res;
		} else if (b[2] - b[1] == 1) {
			int res = 0;
			f(b[0],b[2],res);
			f(b[0] + 1,b[2],res);
			
			return res;
		}
	}
	
	if (b.size() == 2 && b[1] - b[0] > 1) {
		int res = 0;
		
		// 换哪两个 就检查哪两个 
		f(b[0],b[1],res);
		f(b[0] + 1,b[1],res);
		f(b[0],b[1] + 1,res);
		f(b[0] + 1,b[1] + 1,res);
		return res;
	}
	
	if (b.size() == 2) {
		int idx = b[1],ans = 0;
		
		// 枚举和哪个换
		for (int i = 1; i <= n; i++) {
			if (i == idx) continue;
		
			swap(a[i],a[idx]);
		
			if (checki(i) && checki(i - 1) && checki(idx) && checki(idx - 1)) {
				++ans;
			}
			swap(a[i],a[idx]);
		}
		
		f(b[0],b[1] + 1,ans);	
		return ans;
	}

	
	if (b.size() == 1) {
		int idx = b[0],ans = 0,p = 0;
	
		// 枚举和哪个换 
		map<pair<int,int>,int> mp;
		for (int j = 0; j <= 1; j++) {
			idx = idx + j;
			for (int i = 1; i <= n; i++) {
				if (i == idx) continue;
		
				swap(a[i],a[idx]);
		
				if (checki(i) && checki(i - 1) && checki(idx) && checki(idx - 1)) {
					int maxv = max(i,idx),minv = min(i,idx);
					
					mp[{minv,maxv}]++;
				}
			
				swap(a[i],a[idx]);
			}
		}
		
		return mp.size();
	}
	
}

// 奇数 小于后面那个    偶数大于后面那个 

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n;
	for (int i = 1;i <= n; i++) {
		cin >> a[i];
	}
	
	cout << solve() << "\n";

	return 0;
}
