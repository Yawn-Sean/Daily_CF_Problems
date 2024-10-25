// 1024
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 p, q;
    std::cin >> p >> q;
    i64 gcd = std::gcd(p, q);
    p /= gcd;
    q /= gcd;

    int n;
    std::cin >> n;
    std::vector<i64> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    i64 num = nums.back();
    i64 deno = 1;
    for (int i = n - 2; i >= 0; --i) {
        i64 gcd = std::gcd(num, deno);
        num /= gcd;
        deno /= gcd;
        
        // num/deno => 1 / num/deno = 1 * deno/num
        std::swap(num, deno);
        // nums[i] + deno / num => nums[i] * num + deno / num
        num += deno * nums[i];
    }

    if (p == num && q == deno) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}