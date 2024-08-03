#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
#define pb emplace_back
using namespace std;
using ll = long long;
constexpr int P = 1e9 + 7;

int N, L, M, v[1000005];

/*
f[i][j + k] = f[i - 1][j] * cnt[k] 
*/


struct Node {
	ll m[105];
	ll& operator [](int i) {
		return m[i];
	}
	friend Node operator * (Node A, Node B) {
		Node C; memset(C.m, 0, sizeof C.m);
		for(int i = 0; i < M; ++ i) {
			for(int j = 0; j < M; ++ j) {
				C[(i + j) % M] = (C[(i + j) % M] + A[i] * B[j]) % P; 
			}
		}
		return C;
	}
} a, b, c;

Node qpow(Node A, int b) {
	Node C; memset(C.m, 0, sizeof C.m);
	C[0] = 1;
	while(b) {
		if(b & 1) C = C * A;
		b >>= 1;
		A = A * A;
	}
	return C;
}


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> N >> L >> M;
	for(int i = 1, x; i <= N; ++ i) cin >> x, ++ a[x % M]; // 到第一层的路径数
	for(int i = 1; i <= N; ++ i) cin >> v[i], ++ b[v[i] % M];
	for(int i = 1, x; i <= N; ++ i) cin >> x, ++ c[(x + v[i]) % M]; 
	/*
	汇点的合并与起点有关
	往前回溯一层即可任意起点
	*/
	Node ans = a * qpow(b, L - 2) * c;
	cout << ans[0];
	return 0;
}
