#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	long long _mx = 2e18;
	_mx ++;
	a.push_back(_mx);
	
	map<long long, int> blanks;
	for(int i=1; i<=n; i++) if(a[i] - a[i-1] - 1 > 0) blanks[a[i]-a[i-1]-1] ++;
	
	vector<long long> mapping(1, 0);
	vector<long long> s(1, 0), s2(1, 0);
	for(auto &[k, v]: blanks) {
		//cout << k << ' ' << v << endl;
		mapping.push_back(k);
		s.push_back(s.back() + k * v);
		s2.push_back(s2.back() + v);
	}
	
	int q;
	cin >> q;
	while(q--) {
		long long l, r;
		cin >> l >> r;
		long long x = r - l;
		
		l = 0, r = s.size()-1;
		while(l < r) {
			int mid = (l + r) / 2;
			if(mapping[mid] <= x) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		
		long long total = _mx;
		long long spaces = s.back() - s[l-1];
		spaces -= x * (s2.back() - s2[l-1]);
		
		cout << total - spaces - a[0] << endl;
	}
	return 0;
}
