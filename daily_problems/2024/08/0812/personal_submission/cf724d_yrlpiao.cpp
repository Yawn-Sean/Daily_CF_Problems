#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int m; cin >> m;
    string s; cin >> s;

    int n = s.size();

    deque<int> q;
    char c = 'a' - 1;
    int num = 0;
    for (int i = 0, j = -1; i < n; i++) {
        while (q.size() && s[q.back()] >= s[i]) q.pop_back();
        if (q.size() && q.front() <= i - m) q.pop_front();
        q.push_back(i);
        if (j > i - m) continue;
        j = q.front(); 
        q.pop_front();
        if (s[j] > c) c = s[j], num = 1;
        else if (s[j] == c) num++;
    }

    vector<char> ans;
    for (char ch : s) {
        if (ch < c) ans.push_back(ch);
    }
    
    sort(ans.begin(), ans.end());
    for (char x : ans) cout << x;
    while (num--) cout << c;
    return 0;
}
