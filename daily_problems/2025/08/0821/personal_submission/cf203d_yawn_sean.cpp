#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long double a, b, m, vx, vy, vz;
    cin >> a >> b >> m >> vx >> vy >> vz;

    long double t = -m / vy;

    long double x = a / 2 + vx * t, z = vz * t;

    int val_x = x / (2 * a), val_z = z / (2 * b);
    x -= val_x * 2 * a, z -= val_z * 2 * b;

    while (x < 0) x += 2 * a;
    while (x >= 2 * a) x -= 2 * a;

    while (z < 0) z += 2 * b;
    while (z >= 2 * b) z -= 2 * b;

    cout << fixed << setprecision(15);
    cout << min(x, 2 * a - x) << ' ' << min(z, 2 * b - z);

    return 0;
}