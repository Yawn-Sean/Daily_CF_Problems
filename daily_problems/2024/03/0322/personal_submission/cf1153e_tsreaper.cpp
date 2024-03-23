#include <bits/stdc++.h>
using namespace std;

int n;

int query(int x1, int y1, int x2, int y2, bool swp) {
    if (swp) printf("? %d %d %d %d\n", y1, x1, y2, x2);
    else printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    int ret; scanf("%d", &ret);
    return ret;
}

void answer(int x1, int y1, int x2, int y2, bool swp) {
    if (swp) printf("! %d %d %d %d\n", y1, x1, y2, x2);
    else printf("! %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
}

bool tryy(bool swp) {
    vector<int> vec;
    for (int i = 1; i < n; i++) {
        int t = query(i, 1, i, n, swp);
        if (t & 1) vec.push_back(i);
    }
    if (vec.size() == 0) return false;
    if (vec.size() == 1) vec.push_back(n);

    auto gao = [&](int i) {
        int head = 1, tail = n;
        while (head < tail) {
            int mid = (head + tail) >> 1;
            if (query(i, 1, i, mid, swp) & 1) tail = mid;
            else head = mid + 1;
        }
        return head;
    };
    answer(vec[0], gao(vec[0]), vec[1], gao(vec[1]), swp);
    return true;
}

int main() {
    scanf("%d", &n);
    tryy(false) || tryy(true);
    return 0;
}
