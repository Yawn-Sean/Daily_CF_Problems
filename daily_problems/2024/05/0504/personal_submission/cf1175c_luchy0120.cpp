#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int n, k;
long long lst;
vector <long long> a;
bool ck(long long f) {

	vector<long long> b;
	for (int j = 0;j < n;++j) {
		b.push_back(a[j]-f);
		b.push_back(a[j]+f);
	}
	sort(b.begin(), b.end());

	int q = unique(b.begin(), b.end()) - b.begin();

	int bn = b.size();
	vector<int> s(bn+1);

	for (int j = 0;j < n;++j) {
		int st = lower_bound(b.begin(), b.begin() + q, a[j] - f) - b.begin();
		int ed = lower_bound(b.begin(), b.begin() + q, a[j] + f) - b.begin();
		s[st]++;
		s[ed + 1]--;
	}

	for (int j = 0; j < bn;++j) {
		if (j >= 1) {
			s[j] += s[j - 1];
		}
		if (s[j] >= k + 1) {
			lst = b[j];
			
			return 1;
		}
	}

	return 0;

}



int main() {
	int t;cin >> t;
	for (int i = 0;i < t;++i) {
		cin >> n >> k;
		a.resize(n);
		for (int j = 0;j < n;++j) {
			long long v;cin >> v;
			a[j] = v;
		}
		if (n == 1) {
			cout << a[0] << endl;
			continue;
		}

		long long lo = 0;
		long long hi = a[n - 1] - a[0];
		while (lo < hi) {
			long long mi = (lo + hi) / 2;
			if (ck(mi)) {
				hi = mi;
			}
			else {
				lo = mi + 1;
			}
		}
		ck(lo);
		cout << lst << endl;

	}


	





	return 0;
}