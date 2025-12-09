#include <bits/stdc++.h>
using namespace std;

const int mod = 2;//
namespace MAT{

	template<typename T>
	struct Mat{//0_idx n * n
		int n;
		std::vector<std::vector<T>>a;

		Mat(int _n,T val = 0) {
			n = _n;
			a = std::vector<std::vector<T>>(n,std::vector<T>(n,val));
		}

		Mat operator * (const Mat &m2){
			Mat ans(n,0);
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					for(int k = 0;k < n;k++){
						ans.a[i][j] = (ans.a[i][j] + a[i][k] * m2.a[k][j]) % mod;
					}
				}
			}
			return ans;
		}

		Mat operator + (const Mat &m2){
			auto ans = *this;
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					ans.a[i][j] = (ans.a[i][j] + m2.a[i][j]) % mod;
				}
			}
			return ans;
		}
		void operator *= (const Mat &m2) {*this = *this * m2;}
		void operator += (const Mat &m2) {*this = *this + m2;}

		void norm(){
			for(int i = 0;i < n;i++) a[i][i] = 1;
		}

		void add(int x,int y,int w){//Mat_tree:add_edge(x,y,w);
			if(x == y) return;
			a[y][y] = (a[y][y] + w) % mod;
			a[x][y] = (a[x][y] - w) % mod;
		}

		Mat qmi(long long b){
			auto base = *this;
			Mat ans(n);
			ans.norm();
			while(b) {
				if(b&1) ans = ans * base;
				b >>= 1;
				base = base * base;
			}
			return ans;
		}
	};

	long long qmi(long long a,long long b,long long p){
		long long ans = 1;
		while(b){
			if(b&1) ans = ans*a%p;
			b>>=1;
			a = a*a%p;
		}
		return ans;
	}

	template<typename T>
	Mat<T> inv(Mat<T> mt){
		int n = mt.n;
		std::vector<std::vector<long long>> aug(n, std::vector<long long>(2 * n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) { aug[i][j] = mt.a[i][j]; }
			aug[i][i + n] = 1;
		}

		for (int i = 0; i < n; i++) {
			int pivot = -1;
			for (int r = i; r < n; r++) {
				if (aug[r][i] != 0) {
					pivot = r;
					break;
				}
			}
			if (pivot == -1) { mt.a[0][0] = -1;return mt; }//no_inv
			if (i != pivot) { std::swap(aug[i], aug[pivot]); }
			long long inv_val = qmi(aug[i][i], mod - 2, mod);
			for (int j = 0; j < 2 * n; j++) {
				aug[i][j] = aug[i][j] * inv_val % mod;
			}
			for (int j = 0; j < n; j++) {
				if (j == i) continue;
				long long mul = aug[j][i];
				for (int k = 0; k < 2 * n; k++) {
					aug[j][k] = (aug[j][k] - mul * aug[i][k] % mod + mod) % mod;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mt.a[i][j] = aug[i][j + n];
			}
		}
		return mt;
	}

	template<typename T>
	T det(Mat<T> mt){
		int n = mt.n;
		long long ans = 1;
		for(int i = 0;i < n;i++){//if(mat_tree) i start from 1
			for(int j = i+1;j < n;j++){
				while(mt.a[j][i]){
					long long t = mt.a[i][i]/mt.a[j][i];
					for(int k = i;k < n;k++) {
						mt.a[i][k] = (mt.a[i][k] - mt.a[j][k] * t % mod + mod) % mod;
                        //mt.a[i][k] -= t * mt.a[j][k];
					}
					std::swap(mt.a[i],mt.a[j]);
					ans = -ans;
				}
			}
			if(!mt.a[i][i]) return 0;
			ans = (ans * mt.a[i][i] % mod + mod) % mod;
            //ans *= mt.a[i][i];
		}
		return std::abs(ans);
	}
}
using MAT::Mat;

void soviet() {
	int n, k; std::cin >> n >> k;
	std::vector<std::string> s(n);
	for (int i = 0; i < n; i++) std::cin >> s[i];

	auto f = [&](int i, int j) {return i * n + j;};

	Mat<long long> transition(n * n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == '#') continue;
			for (int di = -1; di <= 1; di++) {
				for (int dj = -1; dj <= 1; dj++) {
					int ni = i + di, nj = j + dj;
					if (ni < 0 || ni >= n || nj < 0 || nj >= n || s[ni][nj] == '#') continue;
					transition.a[f(i, j)][f(ni, nj)] = 1;
				}
			}
		}
	}

	auto kth = transition.qmi(k);
	std::vector<std::vector<int>> ans(n, std::vector<int> (n));
	for (int i1 = 0; i1 < n; i1++) {
		for (int j1 = 0; j1 < n; j1++) {
			for (int i2 = 0; i2 < n; i2++) {
				for (int j2 = 0; j2 < n; j2++) {
					if(kth.a[f(i1, j1)][f(i2, j2)]) {
						ans[i2][j2] ^= s[i1][j1] - '0';
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == '#') std::cout << '#';
			else std::cout << ans[i][j];
		}
		std::cout << '\n';
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
