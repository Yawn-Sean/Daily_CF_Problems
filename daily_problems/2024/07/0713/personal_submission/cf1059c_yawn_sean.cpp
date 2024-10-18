#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    function<void(int, int)> answer = [&] (int n, int x) {
        if (n <= 3) {
            for (int i = 0; i < n - 1; i ++)
                cout << x << ' ';
            cout << n * x << ' ';
            return;
        }
        for (int i = 0; i < n - n / 2; i ++)
            cout << x << ' ';
        answer(n / 2, x * 2);
    };
    answer(n, 1);

    return 0;
}