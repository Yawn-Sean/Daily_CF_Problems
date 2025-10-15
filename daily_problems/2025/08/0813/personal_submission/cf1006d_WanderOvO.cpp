#include <bits/stdc++.h>

using namespace std;

/*
注意只能改 a
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int i = 0, j = n - 1;
    int res = 0;
    while (i < j) {
        if ((a[i] == b[i] and a[j] == b[j]) 
        or (a[i] == b[j] and a[j] == b[i])
        or (a[i] == a[j] and b[i] == b[j])) {
            res += 0;  
        } else if (a[i] != b[i] and a[i] != b[j] and a[j] != b[i] and a[j] != b[j] and b[i] != b[j]) {
            res += 2;
        } else {
            res += 1;
        }
        i++;
        j--;
    }
    if (i == j) {
        if (a[i] != b[i]) {
            res++;
        }
    }
    cout << res << "\n";
    
    return 0;
}
