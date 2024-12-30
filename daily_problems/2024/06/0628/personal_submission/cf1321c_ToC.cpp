// https://codeforces.com/contest/1321/submission/268155764
int check(pair<char, int> *ss, int *pos, int len) {
    bool ok = false;
    char letter = '?';
    for (int i = len; i >= 1; i--) {
        if (i + 1 <= len && ss[i + 1].first + 1 == ss[i].first) {
            if (!ok) {
                letter = ss[i].first;
                *pos = i;
                ok = true;
            } else if (ss[i].first > letter) {
                letter = ss[i].first;
                *pos = i;
            }
        }
        if (i - 1 >= 1 && ss[i - 1].first + 1 == ss[i].first) {
            if (!ok) {
                letter = ss[i].first;
                *pos = i;
                ok = true;
            } else if (ss[i].first > letter) {
                letter = ss[i].first;
                *pos = i;
            }
        }
    }
    return ok ? *pos : INF;
}
void sol()
{
    char str[MAXN];
    pair<char, int> ss[MAXN];

    scanf("%d", &n);
    scanf("%s", str + 1);
    vector<int> start;
    int i = 1, j = 0;
    while (i <= n) {
        ss[++j].first = str[i];
        ss[j].second = i;

        start.push_back(i);
        i++;
        while (i <= n && str[i] == ss[j].first) {
            i++;
        }
    }
    int pos = 0;
    vector<int> remv;
    while (check(ss, &pos, j) != INF) {
        remv.push_back(ss[pos].second);
        ss[pos] = {'?', 0};
        k = 0;
        for (int i = 1; i <= j; i++) {
            if (ss[i].first != '?') {
                ss[++k] = ss[i];
            }
        }
        j--;
    }
    sort(remv.begin(), remv.end());
    int cnt = 0;
    for (auto &e : remv) {
        char c = str[e];
        for (int i = e; i <= n && str[i] == c; i++)
            cnt++;
    }
    cout << cnt << '\n';
}   
