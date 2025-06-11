#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        长度为n的字符串
        最多分成r行
        要求每行最多只有c个字符
        单词不能被拆开
        问: 最多的构造方法是什么? 需要保持相对的顺序
    */
    int n, r, c;
    cin >> n >> r >> c;

    vector<string> strs(n);
    for (auto&s: strs) {
        cin >> s;
    }

    // next[i]: i位置作为一个新行的开头 最多能够包含多少字符(完整的单词)
    int left = 0, right = 0;
    int tot = 0;
    vector<int> next(n + 1);
    while (left < n) {
        while (right < n && right - left + tot + (int)strs[right].size() <= c) {
            tot += (int)strs[right].size();    
            right++;
        }
        next[left] = right;
        tot -= (int)strs[left].size();
        left++;
    }
    next[n] = n;

    vector<int> tmp = next;
    vector<int> cur(n + 1);
    iota(cur.begin(), cur.end(), 0);

    for (int i = 0; i < 20; i++) {
        if ((r >> i) & 1) {
            for (int j = 0; j <= n; j++) {
                cur[j] = tmp[cur[j]];
            }
        }

        vector<int> ntmp(n + 1);
        for (int j = 0; j <= n; j++) {
            ntmp[j] = tmp[tmp[j]];
        }
        swap(ntmp, tmp);
    }

    int ans = -1, idx = -1;
    for (int i = 0; i < n; i++) {
        if (cur[i] - i > ans) {
            ans = cur[i] - i;
            idx = i;
        }
    }

    while (r--) {
        if (next[idx] > idx) {
            for (int i = idx; i < next[idx]; i++) {
                cout << strs[i] << ((i == next[idx] - 1) ? '\n' : ' ');
            }
            idx = next[idx];
        }
    }


    return 0;
}
