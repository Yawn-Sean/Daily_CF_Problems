#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 4e5 + 10;

int n, k;
int a[N];
int p[N], nxt[N];
int ans = 0;
set <long long> s;

inline long long calc(int x, int pos) {
	long long ret = 1ll * pos;
	ret <<= 32;
	ret |= x;
	return ret;
}

inline pair <int, int> solve(long long x) {
	int pos = (int)(x >> 32);
	int all = (1 << 20) - 1;
	int id = x & all;
	return make_pair(id, pos);
}

int main() {
	
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", a + i);

	dec(i, n, 1) {
		if (p[a[i]] == 0) {
			nxt[i] = n + 1;
		} else {
			nxt[i] = p[a[i]];
		}
		p[a[i]] = i;
	}
	
	rep(i, 1, n) {
		long long val = calc(a[i], i);
		long long new_val = calc(a[i], nxt[i]);
		if (s.count(val)) {
			s.erase(s.find(val));
			s.insert(new_val);
			continue;
		}

		++ans;

		if ((int)s.size() < k) {
			s.insert(new_val);
			continue;
		}

		long long tp = *s.rbegin();
		s.erase(s.find(tp));
		s.insert(new_val);
	}

	printf("%d\n", ans);
	return 0;
}

