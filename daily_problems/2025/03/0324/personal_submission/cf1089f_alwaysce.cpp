#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 2; i * i <= n; i++) {
        if (i == n) { break; }
        
        /*
            x1a1 + x2a2 + ... + xnan = n - 1
            -(x1b1 + x2b2 + ... + xbnb + n) = 1
            gcd(x1,x2,...,xb) = 1
            -> 方程有解则 因子需要互质

            找xvx + yvy = n - 1
            因为: x*vx 在vx=0,1,...,y-1的时候关于y的模两两不同

        */
        if (n % i == 0 && gcd(i, n / i) == 1) {
            // vx a + vy b + n = 1
            int a = i, b = n / i;
            // gcd(vx, vy) = 1
            for (int j = 1; j < a; j++) {
                int left = n - 1 - j * b;
                if (left % a == 0) {
                    int vx = left / a;
                    int vy = j;
                    cout << "YES\n2\n";
                    cout << vy << ' ' << a << '\n';
                    cout << vx << ' ' << b << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}
