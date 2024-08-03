#include <bits/stdc++.h>

using i64 = long long;

i64 inf = 100000007;
i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;
	std::cin >> t;
	while (t--) {
		i64 a, b;
		std::cin >> a >> b;
		
        i64 mul = a * b;
        i64 l = 1, r = 1e6+5;
        while (l < r) {
        	i64 m = (l + r) / 2;
        	if (m * m * m < mul) {
        		l = m + 1;
        	} else {
        		r = m;
        	}
        }
        
        bool fl = ((r * r * r == mul) and (a % r == 0) and (b % r == 0));
        std::cout << (fl ? "Yes\n" : "No\n");
	}
	return 0;
}
