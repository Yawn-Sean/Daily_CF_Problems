#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
using i128 = __int128;
std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
struct FHQ {
	struct Node {
		int lsn, rsn;
		int key, pri, siz;
		char val;
		int flag;
	};
	const int maxn;
	std::vector<Node> treap;
	int tSize, root;
	FHQ(int n): maxn(n), treap(n), tSize(0), root(0) {}
	void makeNewNode(int x, char v) {
		++tSize;
		treap[tSize].siz = 1;
		treap[tSize].lsn = treap[tSize].rsn = 0;
		treap[tSize].key = x;
		treap[tSize].val = v;
		treap[tSize].flag = 0;
		treap[tSize].pri = std::rand();
		return ;
	}
	void updateRoot(int u) {
		treap[u].siz = treap[treap[u].lsn].siz + treap[treap[u].rsn].siz + 1;
		return ;
	}
	void push(int u) {
		if (treap[u].flag) {
			std::swap(treap[u].lsn, treap[u].rsn);
			treap[treap[u].lsn].flag ^= 1;
			treap[treap[u].rsn].flag ^= 1;
			treap[u].flag = 0;
		}
		return ;
	}
	void split(int u, int x, int &L, int &R) {
		if (u == 0) {
			L = R = 0;
			return ;
		}
		push(u);
		if (treap[treap[u].lsn].siz + 1 <= x) {
			L = u;
			split(treap[u].rsn, x - treap[treap[u].lsn].siz - 1, treap[u].rsn, R);
		}
		else {
			R = u;
			split(treap[u].lsn, x, L, treap[u].lsn);
		}
		updateRoot(u);
		return ;
	}
	int merge(int L, int R) {
		if (L == 0 || R == 0) {
			return L + R;
		}
		if (treap[L].pri > treap[R].pri) {
			push(L);
			treap[L].rsn = merge(treap[L].rsn, R);
			updateRoot(L);
			return L;
		}
		else {
			push(R);
			treap[R].lsn = merge(L, treap[R].lsn);
			updateRoot(R);
			return R;
		}
	}
	void fenge(int l, int r) {
		int L, R, mid;
		split(root, r, L, R);
		split(L, l - 1, L, mid);
		treap[mid].flag ^= 1;
		root = merge(merge(L, mid), R);
	}
	char  chaxun(int k) {
		int u = root;
		while (u) {
			push(u);
			if (treap[treap[u].lsn].siz + 1 == k) {
				return treap[u].val;
			}
			else if (treap[treap[u].lsn].siz + 1 < k) {
				k -= treap[treap[u].lsn].siz + 1;
				u = treap[u].rsn;
			}
			else {
				u = treap[u].lsn;
			}
		}
		return treap[u].val;
	}
};
void solve() {
	int n, l, r;
	std::cin >> n >> l >> r;
	FHQ fhq(2 * n);
	for (int i = 1; i <= n; i++) {
		char x;
		std::cin >> x;
		fhq.makeNewNode(i, x);
		fhq.root = fhq.merge(fhq.root, fhq.tSize);
	} int m;
	std::cin >> m;
	while (m--) {
		char x, y, z;
		std::cin >> x;
		if (x == 'S') {
			std::cin >> y >> z;
			if (y == 'L') {
				if (z == 'L') {
					l--;
				}
				else {
					l++;
				}
			}
			else if (y == 'R') {
				if (z == 'R') {
					r++;
				}
				else {
					r--;
				}
			}
		}
		else if (x == 'R') {
			fhq.fenge(l, r);
		}
		else {
			std::cin >> y;
			if (y == 'L') {
				std::cout << fhq.chaxun(l);
			}
			else {
				std::cout << fhq.chaxun(r);
			}
		}
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
