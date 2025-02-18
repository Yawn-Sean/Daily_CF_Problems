#include <bits/stdc++.h>

using namespace std;

#define	rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define	dec(i, a, b)	for (int i(a); i >= (b); --i)
#define	x				first
#define	y				second
#define	MP				make_pair

using pii = pair <int, int> ;

const int N = 1e3 + 10;

map <pii, vector <int>> mp;
map <pii, int> f;
set <vector <int>> s;
pii a[N];
int n;
int v, sum;
long long ans = 0;

inline pii calc(const pii& a, const pii& b) {
	int dy = b.y - a.y;
	int dx = b.x - a.x;

	if (dx == 0) {
		return MP(0, 1);
	}

	if (dy == 0) {
		return MP(1, 0);
	}

	int sign = (dx * dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);

	int g = gcd(dx, dy);
	dx /= g;
	dy /= g;

	return MP(sign * dx, dy);
}

int main() {

	scanf("%d", &n);

	rep(i, 1, n) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}

	rep(i, 1, n) {
		mp.clear();
		rep(j, 1, n) {
			if (i == j) {
				continue;
			}

			auto pr = calc(a[j], a[i]);
			mp[pr].emplace_back(j);
		}

		for (const auto &[pr, vec] : mp) {
			if ((int)vec.size() < 2) {
				continue;
			}
			vector <int> cnt = vec;
			cnt.emplace_back(i);
			sort(cnt.begin(), cnt.end());
			
			if (!s.count(cnt)) {
				s.insert(cnt);
				
				int sz = (int)cnt.size();
				int d = sz * (sz - 1) / 2;
				--d;
				f[pr] -= d;

				// printf("(%d, %d) : ", pr.x, pr.y);
				// for (auto u : cnt) printf("%d ", u); putchar(10);
			}
		}
	}

	

	rep(i, 1, n - 1) {
		rep(j, i + 1, n) {
			auto pr = calc(a[j], a[i]);
			++f[pr];
		}
	}

	for (const auto & [pr, v] : f) {
	// 	printf("(%d, %d) %d\n", pr.x, pr.y, v);
		ans += 1ll * v * sum;
		sum += v;
	}

	printf("%lld\n", ans);
	return 0;

}

 
