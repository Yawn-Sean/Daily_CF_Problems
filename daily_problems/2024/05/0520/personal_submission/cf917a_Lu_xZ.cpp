#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 5500;

int n, ans, cur, num;
char s[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; ++ i) {
		cur = num = 0;
		for(int j = i; j < n; ++ j) {
			if(s[j] == '(') ++ cur;
			else {
				-- cur;
				num += (s[j] == '?');
			}
			if(cur < 0 && num) {
				cur += 2;
				-- num;
			}
			if(cur < 0) break;
			ans += cur == 0;
		}
	}
	printf("%d", ans);
	return 0;
}
