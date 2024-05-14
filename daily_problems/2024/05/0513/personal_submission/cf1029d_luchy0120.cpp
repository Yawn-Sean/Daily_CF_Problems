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



int main() {
	int n; cin >> n;
	long long k;cin >> k;
	vector<long long> a(n);
	for (int i = 0;i < n;++i) {
		cin >> a[i];
	}
	long long r = 0;
	vector<map<long, long>> mp(11);
	for (int i = 0;i < n;++i) {
		long long v = a[i];
		int w = 0;
		while (v) {
			v /= 10;
			w++;
		}
		v = a[i];
		for (int j = 1;j <= 10;++j) {
			v *= 10;
			v %= k;
			long ck = (k - v) % k;
			if(mp[j].count(ck)){
				r += mp[j][ck];
			}
		}
		mp[w][a[i] % k]++;
	}

	vector<map<long, long>> mp1(11);
	for (int i = n-1;i >= 0;--i) {
		long long v = a[i];
		int w = 0;
		while (v) {
			v /= 10;
			w++;
		}
		v = a[i];
		for (int j = 1;j <= 10;++j) {
			v *= 10;
			v %= k;
			long ck = (k - v)%k;
			if (mp1[j].count(ck)) {
				r += mp1[j][ck];
			}
		}
		mp1[w][a[i] % k]++;
	}
	cout << r << endl;




	




	return 0;
}