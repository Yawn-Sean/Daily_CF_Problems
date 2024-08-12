#include <iostream>
using namespace std;     

const int N = 1 << 19, mod = 1e9 + 7, inf = 0x3f3f3f3f;

char s[N] {};
int n, m, tre[N << 1] {};

void bld(int nod, int l, int r) {
    if (l == r) {
        tre[nod] = 0;
        return;
    }
    int mid = l + r >> 1;
    bld(nod << 1, l, mid); bld(nod << 1 | 1, mid + 1, r);
    tre[nod] = tre[nod << 1] + tre[nod << 1 | 1] + (s[mid] == '.' && s[mid + 1] == '.');
    return;
}

void upd(int nod, int l, int r, int pos) {
    if (l == r) {
        tre[nod] = 0;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) upd(nod << 1, l, mid, pos);
    else upd(nod << 1 | 1, mid + 1, r, pos);
    tre[nod] = tre[nod << 1] + tre[nod << 1 | 1] + (s[mid] == '.' && s[mid + 1] == '.');
    return;
}

void yrlpSolve() {
    cin >> n >> m;
    scanf("%s", s + 1);
    bld(1, 1, n);
    int pos;
    char c;
    while (m--) {
        cin >> pos >> c;
        s[pos] = c;
        upd(1, 1, n, pos);
        cout << tre[1] << endl;
    }
    return;
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
