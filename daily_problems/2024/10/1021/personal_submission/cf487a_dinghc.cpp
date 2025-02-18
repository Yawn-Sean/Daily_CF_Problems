#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int hy, ay, dy;
    cin >> hy >> ay >> dy;
    int hm, am, dm;
    cin >> hm >> am >> dm;
    int h, a, d;
    cin >> h >> a >> d;
    int ans = INT_MAX;
    for (int ab = max(dm - ay + 1, 0); ab <= 200 - ay; ab++) {
        for (int db = 0; db <= 100 - dy; db++) {
            int t = ab * a + db * d;
            int s = (hm + ay + ab - dm - 1) / (ay + ab - dm);
            if (am > dy + db) {
                t += max(0, s * (am - dy - db) + 1 - hy) * h;
            }
            ans = min(ans, t);
        }
    }
    cout << ans << "\n";
    return 0;
}

