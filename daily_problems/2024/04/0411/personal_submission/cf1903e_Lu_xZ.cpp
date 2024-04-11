#include<bits/stdc++.h>
using namespace std;

using ll = long long;


void solve() {
	int n, sx, sy; cin >> n >> sx >> sy;
	/*
	  x1^2 + x2^2 + y1^2 + y2^2
	  
	  x2^2 + x3^2 + y2^2 + y3^2
	  
	  .
	  .
	  .
	    
	  x_{n - 1}^2 + xn^2 + y_{n - 1}^2 + yn^2
	  
	  
	  ->  
	  x1^2 + y1^2 + xn^2 + yn^2
	 */
	set<int> a, b;
	
	for(int i = 1; i <= n; ++ i) {
		int x, y; cin >> x >> y;
		if((x + y & 1) == (sx + sy & 1)) {
			a.insert(i);
		}
		else {
			b.insert(i);
		}
	}
	/*
	  最后一个点必须是a集合中的
	  
	  先手：一直拿b
	  后手：一直拿a
	 */
	if(a.size() >= b.size()) {
		cout << "First" << endl;
		for(int i = 1; i <= n; ++ i) {
			if(i & 1) {
				if(!b.empty()) {
					cout << *b.begin() << endl;
					b.erase(b.begin());
				}
				else {
					cout << *a.begin() << endl;
					a.erase(a.begin());
				}
			}
			else {
				int j; cin >> j;
				if(a.count(j)) {
					a.erase(j);
				}
				else {
					b.erase(j);
				}
			}
		}
	}
	else {
		cout << "Second" << endl;
		for(int i = 1; i <= n; ++ i) {
			if(i & 1) {
				int j; cin >> j;
				if(a.count(j)) {
					a.erase(j);
				}
				else {
					b.erase(j);
				}
			}
			else {
				if(!a.empty()) {
					cout << *a.begin() << endl;
					a.erase(a.begin());
				}
				else {
					cout << *b.begin() << endl;
					b.erase(b.begin());
				}
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	cin >> T;
	
	while(T --) {
		solve();
	}
	return 0;
}
