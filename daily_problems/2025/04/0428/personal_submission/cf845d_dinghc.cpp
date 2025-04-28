#include <bits/stdc++.h>
 
using namespace std;

enum event {
    change_speed = 1, overtake = 2, speed_limit = 3, overtake_allowed = 4,
    no_speed_limit = 5, no_overtake_allowed = 6
};

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    vector<int> speed_limits;
    int no_overtake_count = 0;
    for (int i = 0, no_overtake_count = 0, speed, type, limit; i < n; i++) {
        scanf("%d", &type);
        switch (type) {
            case overtake_allowed:
                no_overtake_count = 0;
                break;
            case no_overtake_allowed:
                no_overtake_count += 1;
                break;
            case overtake:
                ans += no_overtake_count;
                no_overtake_count = 0;
                break;
            case speed_limit:
                scanf("%d", &limit);
                if (speed > limit) {
                    ans += 1;
                } else {
                    speed_limits.push_back(limit);
                }
                break;
            case no_speed_limit:
                speed_limits.clear();
                break;
            case change_speed:
                scanf("%d", &speed);
                while (!speed_limits.empty() && speed_limits.back() < speed) {
                    speed_limits.pop_back();
                    ans += 1;
                }
                break;
        }
    }
    printf("%d\n", ans);
    return 0;
}

