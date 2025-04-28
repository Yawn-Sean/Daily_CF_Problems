/**
 * https://codeforces.com/problemset/problem/255/D
 * D. Mr. Bender and Square
 * Solver: nhant
 * 2025-04-01 02:53:14
 */
#include <bits/stdc++.h>

using namespace std;

int64_t sideTriangle(int64_t h) {
    return (1 + h) * h - h; // sum of (2*k-1), k=1..h
}

int64_t cornerTriangle(int64_t h) {
    return (1 + h) * h / 2;
}

int64_t count(int64_t t, int x, int y, int n) {
    int64_t res = 1 + (1 + t) * t * 2;
    int dt = x - 1, dr = n - y, db = n - x, dl = y - 1;
    int64_t top = t > dt ? sideTriangle(t - dt) : 0;
    int64_t right = t > dr ? sideTriangle(t - dr) : 0;
    int64_t bottom = t > db ? sideTriangle(t - db) : 0;
    int64_t left = t > dl ? sideTriangle(t - dl) : 0;
    int64_t topLeft = t - 1 > dt + dl ? cornerTriangle(t - 1 - dt - dl) : 0;
    int64_t topRight = t - 1 > dt + dr ? cornerTriangle(t - 1 - dt - dr) : 0;
    int64_t bottomLeft = t - 1 > db + dl ? cornerTriangle(t - 1 - db - dl) : 0;
    int64_t bottomRight = t - 1 > db + dr ? cornerTriangle(t - 1 - db - dr) : 0;
    return res - top - right - bottom - left + topLeft + topRight + bottomLeft + bottomRight;
}

void solve() {
    int n, x, y, c;
    cin >> n >> x >> y >> c;
    int lo = 0, hi = 2 * n;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (c <= count(mi, x, y, n)) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    cout << hi << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
