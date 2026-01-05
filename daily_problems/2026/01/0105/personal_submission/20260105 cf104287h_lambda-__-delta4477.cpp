#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <climits>
#include <array>
//#include <ranges>
#include <numeric>
#include <iomanip>
#include<set>
#include<functional>
#include<bit>
#include<random>
#include<unordered_set>
#include <cstring>
#include <chrono>
#include <cstdint>
#include<sstream>


using namespace std;
using ll = long long;
using ull = unsigned long long;

//const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

ll power(ll a, ll b, int p)
{
	int res = 1;
	for (; b; b /= 2, a = 1LL * a * a % p)
	{
		if (b % 2)
		{
			res = 1LL * res * a % p;
		}
	}
	return res;
}

void solve()
{
	int d; cin >> d;
	ll ans = 0;
	ll sum = (power(2, d, MOD) + MOD - 1) % MOD;
	for (int i = 1; i < d; i++)
	{
		ll tmp = (power(2, i, MOD) + MOD - 1)%MOD;

		ans += (sum - tmp + MOD) % MOD * tmp % MOD * power(2, d - i, MOD) % MOD;
		ans %= MOD;
	}

	ans = 2 * ans % MOD;
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		solve();
	}
}
