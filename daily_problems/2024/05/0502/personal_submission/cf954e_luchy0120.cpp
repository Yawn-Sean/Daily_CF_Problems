#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

int n,t;
using ll = long long;
vector<ll> a;
vector<array<ll,2>> z;
vector<array<ll,2>> f;

int main() {
	cin >> n >> t;
	long double r = 0;
	for (int i = 0;i < n;++i) {
		ll v;cin >> v;
		a.push_back(v);
		r += v;
	}
	long double s1 = 0;
	long double s2 = 0;
	
	for (int i = 0;i < n;++i) {
		int v;cin >> v; v -= t;
		if (v >= 0) {
			z.push_back({ v,a[i] });
			s1 += a[i] * v;
		}
		else {
			f.push_back({ -v,a[i] });
			s2 += a[i] * (-v);
		}
	}
	if (s2 > s1) {
		swap(z, f);
		swap(s1, s2);
	}

	sort(z.rbegin(), z.rend());

	for (int i = 0;i < z.size();++i) {
		if (s1 - z[i][0] * z[i][1] > s2) {
			s1 -= z[i][0] * z[i][1];
			r -= z[i][1];
		}
		else if (z[i][0] == 0) {
			break;
		}
		else {
			r -= ((s1 - s2) * 1.0) / z[i][0];
			break;
		}
	}
	cout << fixed << setprecision(6) << r << endl;


	return 0;
}