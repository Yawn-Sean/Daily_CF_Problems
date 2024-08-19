#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

const int N = 4;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<pair<double, double>> a(N), b(N);
	double x, y;
	for (int i = 0; i < N; i ++) {
		cin >> x >> y;
		a[i] = {x, y};
	}
	for (int i = 0; i < N; i ++) {
		cin >> x >> y;
		b[i] = {x, y};
	}
	auto dot = [&](pair<double, double> &a, pair<double, double> &b) {
		return a.first * b.first + a.second * b.second;
	};
	auto f = [&](pair<double, double> &a, pair<double, double> &b) {
		return make_pair(b.first - a.first, b.second - a.second);
	};
	auto inSquare = [&](pair<double, double> &p, vector<pair<double, double>> &s) {
		auto ab = f(s[0], s[1]);
		auto ap = f(s[0], p);
		auto bc = f(s[1], s[2]);
		auto bp = f(s[1], p);
		auto dotAbAp = dot(ab, ap);
		auto dotAbAb = dot(ab, ab);
		auto dotBcBp = dot(bc, bp);
		auto dotBcBc = dot(bc, bc);
		return 0 <= dotAbAp && dotAbAp <= dotAbAb && 0 <= dotBcBp && dotBcBp <= dotBcBc;
	};
	auto checkCenter = [&](vector<pair<double, double>> &s, vector<pair<double, double>> &s2){
		double cx = (s[0].first + s[2].first) / 2;
		double cy = (s[0].second + s[2].second) / 2;
		pair<double, double> t{cx, cy};
		return inSquare(t, s2);
	};
	for (int i = 0; i < N; i ++) {
		if (inSquare(a[i], b)) {
			cout << "YES" << endl;
			return 0;
		}
	}
	if (checkCenter(a, b) || checkCenter(b, a)) {
		cout << "YES" << endl;
		return 0;
	};
	for (int i = 0; i < N; i ++) {
		if (inSquare(b[i], a)) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
