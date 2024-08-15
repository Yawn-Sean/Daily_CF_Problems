#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, p; cin >> n >> p;
    string s; cin >> s;
    int i = n - 1;
    for (++s[i]; 0 <= i && i < n;) {
        if (s[i] >= p + 'a') {
            s[i] = 'a';
            s[--i]++;
        } else if ((i > 0 && s[i] == s[i - 1] || (i > 1 && s[i] == s[i - 2])))
            ++s[i];
        else
            ++i;
    }
    if (i < 0)
        cout << "NO";
    else
        cout << s;
}
