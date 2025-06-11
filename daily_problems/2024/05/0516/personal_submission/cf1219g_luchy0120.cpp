#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <array>
#include <unordered_set>
#include <queue>
using namespace std;


long long r = 0;
void sol(vector<vector<long long>>& mp, int n, int m) {
	vector<long long> h(n);
	
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			h[i] += mp[i][j];
		}
	}
	auto ch = h;
	int cf = min(n, 4);
	nth_element(ch.begin(),ch.end() - cf, ch.end());

	long long s = 0;
	for (int i = ch.size() - 1;i >= (int)(ch.size() - cf);--i) {
		s += ch[i];
	}
	r = max(r, s);

	for (int j = 0;j < m;++j) {
		long long c = 0;
		for (int i = 0;i < n;++i) {
			c += mp[i][j];
		}
		vector<long long> hh;
		for (int i = 0;i < n;++i) {
			hh.push_back(h[i] - mp[i][j]);
		}
		int cf = min(n, 3);
		nth_element(hh.begin(), hh.end() - cf, hh.end());
		long long s = c;
		for (int i = hh.size() - 1;i >= (int)(hh.size() - cf);--i) {
			s += hh[i];
		}
		r = max(s, r);
	}

}


int main() {
	int n, m;cin >> n >> m;

	vector<vector<long long>> mp(n);
	vector<vector<long long>> mp1(m);


	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			long long a;cin >> a;
			mp[i].push_back(a);
			mp1[j].push_back(a);
		}
	}
	sol(mp,n,m);
	sol(mp1,m,n);
	if (m >= 2 && n >= 2) {
		if (n > m) {
			swap(n,m);
			swap(mp,mp1);
		}

		vector<long long> c(m);
		vector<long long> h(n);

		for (int i = 0;i < n;++i) {
			for (int j = 0;j < m;++j) {
				c[j] += mp[i][j];
				h[i] += mp[i][j];
			}
		}

		for (int i = 0;i < n;++i) {
			for (int j = i+1;j < n;++j) {
				long long mx = 0;
				long long mx1 = 0;
				for (int k = 0;k < m;++k) {
					long v =  c[k] - mp[i][k] - mp[j][k];
					if (v > mx) {
						mx1 = mx;
						mx = v;
					}
					else if(v> mx1){
						mx1 = v;
					}
				}
				
				r = max(r, mx  + mx1 + h[i] + h[j]);
			}
		}
	}

	cout << r << endl;






	return 0;
}