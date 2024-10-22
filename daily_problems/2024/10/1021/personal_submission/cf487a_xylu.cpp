#include <bits/stdc++.h>
using namespace std;

void solveA() {
    int yhp, yatk, ydef, mhp, matk, mdef;
    int h, a, d;
    cin >> yhp >> yatk >> ydef >> mhp >> matk >> mdef;
    cin >> h >> a >> d;

    int ans = 1e9;
    for (int def = min(ydef, matk); def <= matk; def++) {
        if (def == matk) {
            // yatk >= mdef + 1
            ans = min(ans, a * max(0, mdef + 1 - yatk) + d * max(0, def - ydef));
            break;
        }
        // mdef + 1 <= yatk <= mhp + mdef
        for (int atk = max(yatk, mdef + 1); atk <= max(yatk, mhp + mdef); atk++) {
            int t1 = (mhp + atk - mdef - 1) / (atk - mdef);
            int hp = max(yhp, t1 * (matk - def) + 1);
            int cost = h * (hp - yhp) + a * (atk - yatk) + d * max(0, def - ydef);
            ans = min(ans, cost);
        }
    }
    cout << ans << '\n';
}

int main() {
    solveA();
    return 0;
}
