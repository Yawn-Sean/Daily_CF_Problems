#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

typedef long long ll;

typedef struct {
	ll x, y;
} Node;

char s[N];
ll t;
Node sum[N];
map<char, Node> mp;

int main() {
	t = read();
	Node u = {0, 1}, d = {0, -1}, l = {-1, 0}, r = {1, 0};
	mp['L'] = l;
	mp['R'] = r;
	mp['U'] = u;
	mp['D'] = d;
	while (t--) {
		scanf("%s", s + 1);
		for (int i = 1; s[i] != '\0'; i++) {
			sum[i].x = sum[i - 1].x + mp[s[i]].x;
			sum[i].y = sum[i - 1].y + mp[s[i]].y;
		}

		ll ansx = 0, ansy = 0;
		for (int i = 1; s[i] != '\0'; i++) {
			if (sum[i].x == 0 && sum[i].y == 0) {
				continue;
			}
			ll x = 0, y = 0;
			for (int j = 1; s[j] != '\0'; j++) {
				Node tmp = mp[s[j]];
				if ((x + tmp.x == sum[i].x) && (y + tmp.y == sum[i].y)) {
					continue;
				}
				x += tmp.x;
				y += tmp.y;
			}
			if (x == 0 && y == 0) {
				ansx = sum[i].x;
				ansy = sum[i].y;
			}
		}
		printf("%lld %lld\n", ansx, ansy);
	}
	return 0;
}
