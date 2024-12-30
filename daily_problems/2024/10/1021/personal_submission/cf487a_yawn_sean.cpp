#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std; 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int hp1, atk1, def1, hp2, atk2, def2, h, a, d;
    cin >> hp1 >> atk1 >> def1;
    cin >> hp2 >> atk2 >> def2;
    cin >> h >> a >> d;

    int ans = 0, v = max(0, def2 + 1 - atk1);
    atk1 += v;
    ans += v * a;

    int cur_h1 = max(0, atk2 - def1), cur_h2 = atk1 - def2;
    int new_ans = cur_h1 * d;

    for (int delta_h1 = 0; delta_h1 < cur_h1; delta_h1 ++) {
        for (int delta_h2 = 0; delta_h2 <= 100; delta_h2 ++) {
            int h1 = cur_h1 - delta_h1, h2 = cur_h2 + delta_h2;
            int time = (hp2 + h2 - 1) / h2;
            int delta_hp1 = max(time * h1 + 1 - hp1, 0);
            new_ans = min(new_ans, delta_h1 * d + delta_h2 * a + delta_hp1 * h);
        }
    }
    
    cout << ans + new_ans;

    return 0;
}