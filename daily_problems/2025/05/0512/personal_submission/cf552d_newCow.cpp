#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;
const int N = 2010, M = 210;
typedef pair<int,int> pii;
typedef long long ll;
int n;
pii a[N];

int gcd(int x,int y) {
	if (y == 0) return x;
	
	return gcd(y,x % y);
}


// 羊蹄题解 
ll solve() {
	ll ans = (ll)n * (n - 1) / 2 * (n - 2) / 3;
	
	for (int i = 1;i <= n;i++) {
		map<pii, int> mp;
		
		for (int j = 1; j < i; j ++) {
			int dx = a[i].first - a[j].first, dy = a[i].second - a[j].second;
			
			int g = gcd(dx,dy);
			
			dx /= g;
            dy /= g;
			
			if (dx < 0 || (dx == 0 && dy < 0)) {
				dx = -dx;
				dy = -dy;
			}
			
			
			// 现在  mp[{dx,dy}] 表示 j 这个点 可以和 mp[{dx,dy}]个 点对 组成一个三点共线  
			ans -= mp[{dx,dy}];
			
			
			// 然后 j 和 i 组成的向量 是 (dx,dy), 所以  mp[{dx,dy}]++
			mp[{dx,dy}]++;
		}
		
	}
	
	
	return ans;
}

/*

9
0 0
0 1
0 2
1 0
1 1
1 2
2 0
2 1
2 2

9
0 0
0 1
0 2
1 0
1 1
1 2
3 0
3 1
3 2

*/ 

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n;
	
	int x,y;
	
	for (int i = 1;i <= n; i++) {
		cin >> x >> y;
		a[i].first = x;
		a[i].second = y;
	}
	
	ll ans = (ll)n * (n - 1) / 2 * (n - 2) / 3;
	
	for (int i = 1; i <= n; i++) {
		map<double,ll> mp;
		
		for (int j = 1; j < i; j++) {
			int dx = a[i].first - a[j].first;
			int dy = a[i].second - a[j].second;
			
			double k;
			if (dx != 0) {
				k = (double)dy / (double)dx;
			} else {
				k = 201;
			}
			
			ans -= mp[k];
			mp[k]++;
		}
		
	} 
	
	cout << ans << "\n";
	
	// cout << solve() << "\n";
	
	return 0;
}
