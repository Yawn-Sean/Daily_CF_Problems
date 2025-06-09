#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    
    int cur_speed;
    int ans = 0;
    int overtake = 0;
    vector<int> speed_limits;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;  
        if (t <= 2) {
            if (t == 1) {
                cin >> cur_speed;
                while (!speed_limits.empty() && cur_speed > speed_limits.back()) {
                    ans++;
                    speed_limits.pop_back();
                }
            } else {
                ans += overtake;
                overtake = 0;
            }
        } else {
            if (t == 3) {
                int speed;
                cin >> speed;
                if (speed < cur_speed) { ans++; }
                else {
                    speed_limits.push_back(speed);
                }
            } else if (t == 4) {
                overtake = 0;
            } else if (t == 5) {
                speed_limits.clear();
            } else {
                overtake++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
