#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, q;
	cin >> n >> q;
	vector<long long> mi(64);
	mi[0] = 1;
	for(int i=1; i<64; i++) mi[i] = mi[i-1] * 2;
	
	int h = 0;
	while(h < 64 && mi[h] != n+1) h++;
	
	while(q--) {
		long long st;
		cin >> st;
		string path;
		cin >> path;
		
		long long x=0, y=1;
		long long cur = (n+1)/2;
		while(cur != st) {
			long long dif = mi[h-x-2];
			if(st < cur) {
				cur -= dif;
				y = y*2-1;
			} else {
				cur += dif;
				y *= 2;
			}
			x ++;
		}
		
		// cout << "info:" << x << ' ' << y << endl;
		
		for(char c: path) {
			if(c == 'U') {
				if(x > 0) {
					x --;
					y = (y+1) / 2;
				}
			} else if(c == 'L') {
				if(x+1 < h) {
					x ++;
					y = y*2-1;
				}
			} else if(c == 'R') {
				if(x+1 < h) {
					x ++;
					y*=2;
				}
			}
		}
		
		// cout << "info:" << x << ' ' << y << endl;
		
		cur = (n+1)/2;
		int ht = h;
		long long l = 1, r = mi[x];
		while(l < r) {
			long long mid = l + (r - l + 1) / 2;
			if(y < mid) {
				r = mid - 1;
				cur -= mi[ht-2];
			}
			else {
				l = mid;
				cur += mi[ht-2];
			}
			ht--;
		}
		
		cout << cur << endl;
	}
	return 0;
}
