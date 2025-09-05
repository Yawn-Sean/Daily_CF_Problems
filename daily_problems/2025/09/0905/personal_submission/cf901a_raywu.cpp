#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second 
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, INF = 0x3f3f3f3f;

int h, a[N], cnt, cut;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h;
    h++;
    for (int i = 1; i <= h; i++) {
        cin >> a[i];
        if (a[i] > 1 && a[i - 1] > 1)
            cut = i;
    }

    if (!cut) {cout << "perfect" << endl; return 0;}
    cout << "ambiguous" << endl;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= a[i]; j++)
            cout << cnt << " ";
        cnt += a[i];
    }
    cout << endl;
    cnt = 0;
    for (int i = 1; i < cut; i++) {
        for (int j = 1; j <= a[i]; j++)
            cout << cnt << " ";
        cnt += a[i];
    }
    for (int i = 1; i < a[cut]; i++)
        cout << cnt << " ";
    cout << cnt - 1 << " ";
    cnt += a[cut];
    for (int i = cut + 1; i <= h; i++) {
        for (int j = 1; j <= a[i]; j++)
            cout << cnt << " ";
        cnt += a[i];
    }
    return 0;
}
