\#include<bits / stdc++.h> using namespace std;
#define REP(i, j) for (int i = 0; i < j; ++i)
char mp[50][50];
int vt[4];
void put(int z, int dx, int dy) {
    REP(i, 25) REP(j, 25) {
        mp[i + dx][j + dy] = 'A' + z;
        if (i % 2 && j % 2) {
            REP(p, 4) {
                if (p != z && vt[p] > 1) {
                    mp[i + dx][j + dy] = 'A' + p;
                    vt[p]--;
                    break;
                }
            }
        }
    }
}
int main() {
    cin >> vt[0] >> vt[1] >> vt[2] >> vt[3];
    put(0, 0, 0);
    put(1, 25, 0);
    put(2, 0, 25);
    put(3, 25, 25);
    cout << "50 50\n";
    REP(i, 50) {
        REP(j, 50) { cout << mp[i][j]; }
        cout << '\n';
    }
}