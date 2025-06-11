#include <bits/stdc++.h>
using namespace std;

int query(int x1, int y1, int x2, int y2) {
	if(x1 > x2 || y1 > y2) {
		return 0;
	}
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl << flush;
	int ans;
	cin >> ans;
	return ans;
}

int query2(int idx, int n, int x) {
	int para[4] = {1,1,n,n};
	para[idx] = x;
	return query(para[0], para[1], para[2], para[3]);
}

int bit_sec(int idx, int n, int cnt) {
	int l=1, r=n;
	if(idx > 1) {
		while(l < r) {
			int mid = (l+r)/2;
			int ans = query2(idx, n, mid);
			if(ans >= cnt) r = mid;
			else l = mid + 1;
		}
	} else {
		while(l < r) {
			int mid = (l+r+1)/2;
			int ans = query2(idx, n, mid);
			if(ans >= cnt) l = mid;
			else r = mid - 1;
		}
	}
	return l;
}

void solve() {
	int n;
	cin >> n;
	
	vector<int> l(2), d(2), r(2), u(2);

	l[0] = bit_sec(0, n, 1);
	l[1] = bit_sec(0, n, 2);
	d[0] = bit_sec(1, n, 1);
	d[1] = bit_sec(1, n, 2);
	r[0] = bit_sec(2, n, 1);
	r[1] = bit_sec(2, n, 2);
	u[0] = bit_sec(3, n, 1);
	u[1] = bit_sec(3, n, 2);
	
	for(int mask = 0; mask < (1<<4); mask ++) {
		int a = query(l[mask&1], d[(mask>>1)&1], r[(mask>>2)&1], u[(mask>>3)&1]);
		if(a != 1) {
			continue;
		}
		int b = query(l[1-(mask&1)], d[1-((mask>>1)&1)], r[1-((mask>>2)&1)], u[1-((mask>>3)&1)]);
		if(b == 1) {
			printf("! %d %d %d %d %d %d %d %d\n", 
					l[mask&1], d[(mask>>1)&1], r[(mask>>2)&1], u[(mask>>3)&1], 
					l[1-(mask&1)], d[1-((mask>>1)&1)], r[1-((mask>>2)&1)], u[1-((mask>>3)&1)]);
			fflush(stdout);
			return;
		}
	}
}
