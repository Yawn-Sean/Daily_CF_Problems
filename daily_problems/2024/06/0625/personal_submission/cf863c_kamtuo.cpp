#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL k, a, b;

int st[10][10];
int s1[10][10], s2[10][10];
LL ansa, ansb;
LL nowa[10], nowb[10];

int main() {
    cin >> k >> a >> b;
    for (int i = 1; i <= 3; i ++) {
        for (int j = 1; j <= 3; j ++) {
            cin >> s1[i][j];
        }
    }
    for (int i = 1; i <= 3; i ++) {
        for (int j = 1; j <= 3; j ++) {
            cin >> s2[i][j];
        }
    }
    int cnt = 0; 
    for (int i = 1; i <= min(9ll, k); i ++) {
        int pa = a, pb = b;
        st[pa][pb] = i;
        if (pa != pb) {
            if (pa > pb) {
                if (pb == 2) ansa ++;
                if (pb == 1 && pa == 2) ansa ++;
                if (pb == 1 && pa == 3) ansb ++; 
            } else {
                if (pa == 2) ansb ++;
                if (pa == 1 && pb == 2) ansb ++;
                if (pa == 1 && pb == 3) ansa ++; 
            }
        }
        a = s1[pa][pb];
        b = s2[pa][pb];
        nowa[i] = ansa;
        nowb[i] = ansb;
        
        // cout << ansa << ' ' << ansb << endl;
        if (st[a][b]) {
            int j = st[a][b];
            ansa = nowa[j - 1] + (nowa[i] - nowa[j - 1]) * ((k - j + 1) / (i - j + 1));
            ansb = nowb[j - 1] + (nowb[i] - nowb[j - 1]) * ((k - j + 1) / (i - j + 1));
            cnt = ((k - j + 1) % (i - j + 1));
            break;
        }
    }
    for (int i = 1; i <= cnt; i ++) {
        int pa = a, pb = b;
        if (pa != pb) {
            if (pa > pb) {
                if (pb == 2) ansa ++;
                if (pb == 1 && pa == 2) ansa ++;
                if (pb == 1 && pa == 3) ansb ++; 
            } else {
                if (pa == 2) ansb ++;
                if (pa == 1 && pb == 2) ansb ++;
                if (pa == 1 && pb == 3) ansa ++; 
            }
        }
        a = s1[pa][pb];
        b = s2[pa][pb];
    }
    cout << ansa << ' ' << ansb << endl;
    return 0;
}
