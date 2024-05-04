/*
有一个数出现 1 次，其他的出现次数相等，符合题意
有一个数出现次数为 cnt + 1 次，其他数出现次数都是 cnt 次，符合题意
维护每个数的出现次数，以及每个出现次数的出现次数
*/

int T;
map<int, int> cnt, ccnt;
int n, a[N];

void solve1() {
    cin >> n;
    cnt.clear();
    ccnt.clear();
    int res = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        int c = cnt[a[i]];
        if (ccnt.count(c - 1)) {
            ccnt[c - 1]--;
            if (ccnt[c - 1] == 0) {
                ccnt.erase(c - 1);
            }
        }
        ccnt[c]++;
        if (ccnt.size() == 1) {
            auto it = ccnt.begin();
            if (it->x == 1 || cnt.size() == 1) {
                res = i;
            }
        } else if (ccnt.size() == 2) {
            auto it1 = ccnt.begin(), it2 = prev(ccnt.end());
            int key1 = it1->x, val1 = it1->y, key2 = it2->x, val2 = it2->y;
            if ( (key1 == 1 && val1 == 1) || (key2 == 1 && val2 == 1) ) {
                res = i;
            } else if ( key2 - key1 == 1 && val2 == 1 ) {
                res = i;
            }
        }
    }
    cout << res << "\n";
}               