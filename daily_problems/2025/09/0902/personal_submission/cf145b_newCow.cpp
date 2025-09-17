#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void f(int x,int a3,int y) {
	if (x < 0 || y < 0) {
		cout << -1 << "\n";
		return;
	}
		
	for (int i = 0; i < x; i++) {
		cout << 4;
	}
		
	for (int i = 0; i < a3; i++) {
		cout << 47;
	}
		
	for (int i = 0; i < y; i++) {
		cout << 7;
	}
}

void solve() {
	
	int a1,a2,a3,a4;	
	cin >> a1 >> a2 >> a3 >> a4;
	
	int n = a1 + a2, m = a4 - (a3 - 1);
	
	if (m > 2 || m < 0) {
		cout << -1 << "\n";
		return;
	}
 	
	if (m == 0) {
		int x = a1 - a3,y = a2 - a3; // 还要填 x 个 4，填 y 个 7
		if (x < 0 || y < 0) {
			cout << -1 << "\n";
			return;
		}
 
 		f(x,a3,y);
 		
	} else if (m == 1) {
		if (a1 == a3) {
			int y = a2 - a3 - 1;
			if (y < 0) {
				cout << -1 << "\n";
				return;
			}
			
			cout << 7;
			f(0,a3,y);
			return;
		}
		
		int x = a1 - a3 - 1,y = a2 - a3; // 还要填 x 个 4，填 y 个 7
		if (x < 0 || y < 0) {
			cout << -1 << "\n";
			return;
		}
		
		f(x,a3,y);
		
		cout << 4;
		
	} else {
		int x = a1 - a3 - 1,y = a2 - a3 - 1; // 还要填 x 个 4，填 y 个 7
		
		if (x < 0 || y < 0) {
			cout << -1 << "\n";
			return;
		}
		
		cout << 7;
		f(x,a3,y);
		
		cout << 4;
	}
	
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	solve();
	
	return 0;
} 
