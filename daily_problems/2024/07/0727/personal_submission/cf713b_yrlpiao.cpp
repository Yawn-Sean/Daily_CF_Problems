#include <iostream>
#include <vector>
using namespace std;
#define PII pair<int, int>
#define f first
#define s second

auto get(int l, int r, int u, int d) {
    vector<int> ret;
    
    int head = l, tail = r;
    while (head < tail) {
        int mid = head + tail + 1 >> 1;
        cout << "? " << mid << " " << d << " " << r << " " << u << endl; fflush(stdout);
        int x; cin >> x;
        if (x < 1) tail = mid - 1;
        else head = mid;
    }
    ret.push_back(head);

    
    head = l, tail = r;
    while (head < tail) {
        int mid = head + tail >> 1;
        cout << "? " << l << " " << d << " " << mid << " " << u << endl; fflush(stdout);
        int x; cin >> x;
        if (x < 1) head = mid + 1;
        else tail = mid;
    }
    ret.push_back(head);

    
    head = d, tail = u;
    while (head < tail) {
        int mid = head + tail >> 1;
        cout << "? " << l << " " << d << " " << r << " " << mid << endl; fflush(stdout);
        int x; cin >> x;
        if (x < 1) head = mid + 1;
        else tail = mid;
    }
    ret.push_back(head);

    
    head = d, tail = u;
    while (head < tail) {
        int mid = head + tail + 1 >> 1;
        cout << "? " << l << " " << mid << " " << r << " " << u << endl; fflush(stdout);
        int x; cin >> x;
        if (x < 1) tail = mid - 1;
        else head = mid;
    }
    ret.push_back(head);
    return ret;
}

PII check(int n) {
    int l = 1, r = n, u = n, d = 1;
    int head = l, tail = r - 1;
    while (head <= tail) {
        int mid = head + tail >> 1;
        cout << "? " << l << " " << d << " " << mid << " " << u << endl; fflush(stdout);
        int x1; cin >> x1;
        cout << "? " << mid + 1 << " " << d << " " << r << " " << u << endl; fflush(stdout);
        int x2; cin >> x2;
        if (x1 == x2 && x1 == 1) return {1, mid};
        else if (x1 == x2) break;
        else {
            if (x1 > x2) {
                tail = mid - 1;
            } else {
                head = mid + 1;
            }
        }
    }
    head = d, tail = u - 1;
    while (head <= tail) {
        int mid = head + tail >> 1;
        cout << "? " << l << " " << d << " " << r << " " << mid << endl; fflush(stdout);
        int x1; cin >> x1;
        cout << "? " << l << " " << mid + 1 << " " << r << " " << u << endl; fflush(stdout);
        int x2; cin >> x2;
        if (x1 == x2 && x1 == 1) return {0, mid};
        else {
            if (x1 > x2) {
                tail = mid - 1;
            } else {
                head = mid + 1;
            }
        }
    }
    return {2, 0};
}

void yrlpSolve() {
    int n; cin >> n;
    vector<int> v1, v2;
    PII t = check(n);
    if (t.f == 1) {
        v1 = get(1, t.s, n, 1);
        v2 = get(t.s + 1, n, n, 1);
    } else if (t.f == 0) {
        v1 = get(1, n, n, t.s + 1);
        v2 = get(1, n, t.s, 1);
    } else {
        v1 = v2 = get(1, n, n, 1);
    }
    cout << "! " << v1[0] << " " << v1[3] << " " << v1[1] << " " << v1[2] << " " << v2[0] << " " << v2[3] << " " << v2[1] << " " << v2[2] << endl;
    fflush(stdout);
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
