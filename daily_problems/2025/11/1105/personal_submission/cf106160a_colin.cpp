#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int main() {
	char c;
	double ans = 0, val = 0, pw = 1;
	for (c = getchar(); !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar()) {
		val += (c - '0') / pw;
		pw = pw * 10;
		ans += val;
	}
	printf("%.10lf\n", ans * 0.9 + val * 0.1);
	return 0;
}