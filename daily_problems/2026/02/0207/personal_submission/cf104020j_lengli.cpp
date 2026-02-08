#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

bool query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    string res;
    if (!(cin >> res)) exit(0);
    return res[0] == 'b';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h;
    cin >> w >> h;
    vector<int> to_check(w);
    iota(to_check.begin(), to_check.end(), 1);
    
    mt19937 g(random_device{}());
    shuffle(to_check.begin(), to_check.end(), g);

    int idx = 1;
    int cur_h = 0;

    for (int i : to_check) {
        if (cur_h < h && query(i, cur_h + 1)) {
            int l = cur_h + 1, r = h;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (query(i, mid)) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            idx = i;
            cur_h = r;
        }
    }
    cout << "! " << idx << " " << cur_h << endl;

    return 0;
}
