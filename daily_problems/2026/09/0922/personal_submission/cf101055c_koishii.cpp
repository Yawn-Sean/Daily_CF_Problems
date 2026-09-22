#include <bits/stdc++.h>
using namespace std;


const int N = 1000006;
int mu[N],primes[N],cnt;
bool vis[N];
vector<int> mu_list;
void get_mu(int n){
	mu[1] = 1;
	for(int i = 2;i <= n;i++){
		if(!vis[i]) {
			primes[++cnt] = i;
			mu[i] = -1;
		}
		for(int j = 1;i*primes[j] <= n;j++){
			vis[i*primes[j]] = 1;
			if(i%primes[j] == 0) {
				mu[i*primes[j]] = 0;
				break;
			}
			else mu[i*primes[j]] = -mu[i];
		}
	}
	for (int i = 1; i < N; i++) {
		if (mu[i] != 0) {
			mu_list.emplace_back(i);
		}
	}
}

void soviet() {
	long long n; std::cin >> n;

	auto check = [&](long long mid) -> bool {
		long long ans = 0;
		for (long long i : mu_list) {
			long long dd = i * i;
			if (dd > mid) break;
			ans += mu[i] * (mid / dd);
		}
		return ans >= n;
	};

	long long l = 1, r = 4e10;
	while (l < r) {
		long long mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	std::cout << l << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	get_mu(N - 1);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
