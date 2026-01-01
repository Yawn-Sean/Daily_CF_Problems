#include <bits/stdc++.h>
using namespace std;

template<typename T>
T lowbit(T x){ return x&-x; }
long long upbit(long long x){ return x ? 1LL << (63 - __builtin_clzll(x)) : 0; }

std::vector<int> primes, minp, maxp;
void sieve(int n = 2e5 + 5) {
    minp.resize(n + 1);
    maxp.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = maxp[i] = i;
            primes.emplace_back(i);
        }
        for (auto &j : primes) {
            if (j > minp[i] || j > n / i) break;
            minp[i * j] = j;
            maxp[i * j] = maxp[i];
        }
    }
}
std::vector<std::pair<int,int>> factorize(int n) {
	std::vector<std::pair<int,int>>ans;
    while (n > 1) {
        int now = minp[n], cnt = 0;
        while (n % now == 0) {
            n /= now;
            cnt++;
        }
        ans.push_back({now, cnt});
    }
    return ans;
}

void soviet() {
	long long x, k; std::cin >> x >> k;
	std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<std::pair<long long, long long>>> pq;
	for (auto [p, z]: factorize(x)) {
		pq.push({lowbit(z), z});
	}
	while (1) {
		auto [lb, t] = pq.top();
		if (k >= lb) {
			k -= lb;
			pq.pop();
			t += lb;
			pq.push({lowbit(t), t});
		}
		else break;
	}
	std::cout << __builtin_ctzll(pq.top().first) << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	sieve();
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
