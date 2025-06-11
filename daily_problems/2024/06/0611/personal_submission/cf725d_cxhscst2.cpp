#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define	x				first
#define	y				second

const int N = 3e5 + 10;

using pii = pair <long long, long long> ;

int ans = 0;
int now = 0;
int n;
pii me;
pii a[N];
priority_queue <long long, vector<long long>, greater<long long> > q;

int main() {

	scanf("%d", &n);
	scanf("%lld%lld", &me.x, &me.y);

	rep(i, 1, n - 1) {
		scanf("%lld%lld", &a[i].x, &a[i].y);
	}

	sort(a + 1, a + n, [](const pii& p, const pii& q) {
		return p.x > q.x;	
	});

	now = 1;
	ans = 2e9;


	while (true) {
		while (now < n && me.x < a[now].x) {
			q.push(a[now].y - a[now].x + 1);
			++now;
		}

		ans = min(ans, (int)q.size() + 1);

		if (q.empty() || me.x < q.top()) {
			break;
		}

		me.x -= q.top();
		q.pop();
	}

	printf("%d\n", ans);	
	return 0;
}
