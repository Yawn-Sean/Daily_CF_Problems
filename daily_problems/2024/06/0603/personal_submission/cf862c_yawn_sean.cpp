#include <bits/stdc++.h>
using namespace std;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    if (n == 1) 
        cout << "YES\n" << x << '\n';
    else if (n == 2) {
        if (x == 0) cout << "NO\n";
        else cout << "YES\n0 " << x << '\n';
    }
    else {
        int target = x;
        cout << "YES\n";
        for (int i = 1; i <= n - 3; i ++)
            cout << i << ' ', target ^= i;
        if (target)
            cout << 0 << ' ' << (1 << 17) << ' ' << ((1 << 17) ^ target) << '\n';
        else
            cout << (1 << 17) << ' ' << (1 << 18) << ' ' << (3 << 17) << '\n';
    }

    return 0;
}