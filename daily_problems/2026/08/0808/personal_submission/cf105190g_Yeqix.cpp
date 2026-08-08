#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int md = (int)998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

constexpr int SIZE = 3;
struct Matrix {
	vector<vector<Mint>> M;
	void clear() { M.assign(SIZE + 1, vector<Mint>(SIZE + 1, 0)); }
	void reset() {
		for (int i = 1; i <= SIZE; ++i) {
			M[i][i] = 1;
		}
	}
	Matrix() {
		M.resize(SIZE + 1, vector<Mint>(SIZE + 1));
	}
	Matrix friend operator*(const Matrix& A, const Matrix& B) {
		Matrix Ans;
		for (int i = 1; i <= SIZE; ++i) {
			for (int j = 1; j <= SIZE; ++j) {
				for (int k = 1; k <= SIZE; ++k) {
					Ans.M[i][j] += A.M[i][k] * B.M[k][j];
				}
			}
		}
		return Ans;
	}
	Matrix friend operator+(const Matrix& A, const Matrix& B) {
		Matrix Ans;
		for (int i = 1; i <= SIZE; ++i)
			for (int j = 1; j <= SIZE; ++j)
				Ans.M[i][j] = A.M[i][j] + B.M[i][j];
		return Ans;
	}
};

Matrix qpow(Matrix a, i64 b) {
	Matrix ans;
	ans.reset();

	while (b) {
		if (b & 1) {
			ans = ans * a;
		}
		a = a * a;
		b >>= 1;
	}
	return ans;
}

void solve() {
	i64 n;
	cin >> n;
	array<i64, 6> p;
	cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> p[5];

	Mint p0 = (Mint)p[0] / p[1], p1 = (Mint)p[2] / p[3], p2 = (Mint)p[4] / p[5];
	Matrix base, pw;
	base.M[1][1] = 1 - p0, base.M[1][2] = base.M[1][3] = p0;
	pw.M[1][1] = 1 - p2, pw.M[2][1] = 1 - p1, pw.M[1][2] = pw.M[1][3] = p2;
	pw.M[2][2] = pw.M[2][3] = p1, pw.M[3][3] = 1;

	cout << (base * qpow(pw, n - 1)).M[1][3] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}