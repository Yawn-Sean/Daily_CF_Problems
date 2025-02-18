#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

vector<long double> matMul(vector<long double> &m1, vector<long double> &m2) {
	vector<long double> ans(128);
	for (int i = 0; i < 128; i++) {
		for (int j = 0; j < 128; j++) {
			ans[i ^ j] += m1[i] * m2[j];
		}
	}
	return ans;
}

vector<long double> qpow(vector<long double>& mat, int exp) {
	if (exp == 1) {
		return mat;
	}	
	vector<long double> ans = qpow(mat, exp >> 1);
	ans = matMul(ans, ans);
	if (exp & 1) {
		ans = matMul(ans, mat);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, x;
	cin >> n >> x;
	
	vector<long double> p(128);
	for (int i = 0; i <= x; i++) {
		cin >> p[i];
	}
	
	cout << fixed << setprecision(20) << ((long double)(1.0) - qpow(p, n)[0]); 
	
    return 0;
}
