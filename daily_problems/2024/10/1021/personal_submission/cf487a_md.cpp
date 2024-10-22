// 1021
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int hpx, atkx, defx;
    std::cin >> hpx >> atkx >> defx;
    int hpy, atky, defy;
    std::cin >> hpy >> atky >> defy;
    int h, a, d;
    std::cin >> h >> a >> d;

    int ans = std::numeric_limits<int>::max();
    
    for (int delta_a = max(0, defy - atkx + 1); delta_a <= std::max(hpy + defy - atkx, 0); ++delta_a) {
        for (int delta_d = 0; delta_d <= std::max(atky - defx, 0); ++delta_d) {
            if (atky <= defx + delta_d) {
                ans = std::min(ans, a * delta_a + d * delta_d);
                continue;
            }
            
            int num = hpy;
            int den = atkx - defy + delta_a;
            int monster_live = (num + den - 1) / den;
            int delta_hpx = std::max(0, monster_live * (atky - defx - delta_d) - hpx + 1);
            ans = std::min(ans, delta_a * a + delta_d * d + delta_hpx * h);
        }
    }

    std::cout << ans << '\n';

    return 0;
}