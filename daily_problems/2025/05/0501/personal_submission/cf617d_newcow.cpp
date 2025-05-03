#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int solve() {
	int x1,y1,x2,y2,x3,y3;
	
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	if ((x1 == x2 && x1 == x3) || (y1 == y2 && y1 == y3)) {
		return 1;
	}
	
	if (x1 == x2 || x1 == x3 || x2 == x3) {
		if (y1 == y2 || y2 == y3 || y1 == y3) {
			return 2;
		} 
		
		if (x1 == x2) {
			if (y3 > max(y1,y2) || y3 < min(y1,y2)) {
				return 2;
			} else {
				return 3;
			}
		}
		
		if (x2 == x3) {
			if (y1 > max(y3,y2) || y1 < min(y3,y2)) {
				return 2;
			} else {
				return 3;
			}
		}
		
		if (x1 == x3) {
			if (y2 > max(y3,y1) || y2 < min(y3,y1)) {
				return 2;
			} else {
				return 3;
			}
		}
	}
	
	if (y1 == y2 || y1 == y3 || y2 == y3) {
		if (x1 == x2 || x2 == x3 || x1 == x3) {
			return 2;
		} 
		
		if (y1 == y2) {
			if (x3 > max(x1,x2) || x3 < min(x1,x2)) {
				return 2;
			} else {
				return 3;
			}
		}
		
		if (y2 == y3) {
			if (x1 > max(x2,x3) || x1 < min(x3,x2)) {
				return 2;
			} else {
				return 3;
			}
		}
		
		if (y1 == y3) {
			if (x2 > max(x1,x3) || x2 < min(x3,x1)) {
				return 2;
			} else {
				return 3;
			}
		}
	}
	
	return 3;
}

int main() {
	
	cout << solve();
	
	
	return 0;
} 
