#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#define pi acos(-1)
using namespace std;
using i64 = long long;

struct Point
{
    i64 x = 0;
    i64 y = 0;

    bool operator< (const Point& other) const
    {
        if (y != other.y)
            return y < other.y;
        return x < other.x;
    }
};

int T, n;
double k;

void solve()
{
    cin >> n >> k;
    vector<Point> pts(n);
    for (auto& pt : pts)
        cin >> pt.x >> pt.y;
    double l = 0;
    for (int i = 0; i < n; i++)
    {
        auto [xa, ya] = pts[i];
        auto [xb, yb] = pts[(i + 1) % n];
        l += sqrt((double)((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)));
    }
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        auto [xa, ya] = pts[i];
        auto [xb, yb] = pts[(i + 1) % n];
        s += xa * yb - xb * ya;
    }
    s = abs(s) / 2.0;
    double left = 0;
    double right = 1e9;
    for (int i = 0; i < 100; i++)
    {
        double mid = (left + right) / 2;
        if (s + l * mid + pi * mid * mid - k >= 1e-9)
            right = mid;
        else
            left = mid;
    }
    cout << fixed << setprecision(12) << left << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
        solve();
    return 0;
}