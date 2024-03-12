#include <bits/stdc++.h>
using namespace std;
 
const int N = 110;

int n, m, g[N][N];
int flipx[N], flipy[N], totx[N], toty[N];

int minseq(int* a, int sz) {
    int mi = a[0];
    for (int i = 1; i < sz; i++)
        mi = min(mi, a[i]);
    return mi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            totx[i] += g[i][j];
            toty[j] += g[i][j];
        }

    while (minseq(totx, n) < 0 || minseq(toty, m) < 0) {
        for (int i = 0; i < n; i++) {
            if (totx[i] < 0) {
                totx[i] = -totx[i];
                flipx[i] ^= 1;
                for (int j = 0; j < m; j++) {
                    toty[j] -= g[i][j] * 2;
                    g[i][j] *= -1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (toty[i] < 0) {
                toty[i] = -toty[i];
                flipy[i] ^= 1;
                for (int j = 0; j < n; j++) {
                    totx[j] -= g[j][i] * 2;
                    g[j][i] *= -1;
                }
            }
        }
    }

    int sx = 0;
    for (int i = 0; i < n; i++)
        sx += flipx[i];
    cout << sx << " ";
    for (int i = 0; i < n; i++)
        if (flipx[i])
            cout << i + 1 << " ";
    cout << "\n";
    int sy = 0;
    for (int i = 0; i < m; i++)
        sy += flipy[i];
    cout << sy << " ";
    for (int i = 0; i < m; i++)
        if (flipy[i])
            cout << i + 1 << " ";
    return 0;
}
