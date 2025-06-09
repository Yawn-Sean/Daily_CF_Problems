/*
给了 (a[i], b[i], c[i])，先算单个的最大是多少（最短边 / 2）
然后考虑拼接，考虑和前面的 1 到 i - 1 拼接
枚举 6 种情况，记为 (len1, len2)，如果前面也有 (len1, len2)，取第三条边最长的
*/

map<PII, PII> max_len;
int n, a[N], b[N], c[N];

void meibao() {
    cin >> n;
    int res = 0;
    vector<int> choices;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        res = max(res, min({a[i], b[i], c[i]}));
        if (res == min({a[i], b[i], c[i]})) {
            choices.clear();
            choices.push_back(i);
        }
        if (max_len.count({a[i], b[i]})) {
            PII choice = max_len[{a[i], b[i]}];
            int cc = min({a[i], b[i], c[i] + choice.x});
            if (res < cc) {
                res = cc;
                choices.clear();
                choices.push_back(i);
                choices.push_back(choice.y);
            }
        }
        if (max_len.count({b[i], a[i]})) {
            PII choice = max_len[{b[i], a[i]}];
            int cc = min({a[i], b[i], c[i] + choice.x});
            if (res < cc) {
                res = cc;
                choices.clear();
                choices.push_back(i);
                choices.push_back(choice.y);
            }
        }
        if (max_len.count({a[i], c[i]})) {
            PII choice = max_len[{a[i], c[i]}];
            int cc = min({a[i], c[i], b[i] + choice.x});
            if (res < cc) {
                res = cc;
                choices.clear();
                choices.push_back(i);
                choices.push_back(choice.y);
            }
        }
        if (max_len.count({c[i], a[i]})) {
            PII choice = max_len[{c[i], a[i]}];
            int cc = min({a[i], c[i], b[i] + choice.x});
            if (res < cc) {
                res = cc;
                choices.clear();
                choices.push_back(i);
                choices.push_back(choice.y);
            }
        }
        if (max_len.count({b[i], c[i]})) {
            PII choice = max_len[{b[i], c[i]}];
            int cc = min({b[i], c[i], a[i] + choice.x});
            if (res < cc) {
                res = cc;
                choices.clear();
                choices.push_back(i);
                choices.push_back(choice.y);
            }
        }
        if (max_len.count({c[i], b[i]})) {
            PII choice = max_len[{c[i], b[i]}];
            int cc = min({b[i], c[i], a[i] + choice.x});
            if (res < cc) {
                res = cc;
                choices.clear();
                choices.push_back(i);
                choices.push_back(choice.y);
            }
        }
        PII cur1 = max_len[{a[i], b[i]}], cur2 = max_len[{a[i], c[i]}], cur3 = max_len[{b[i], c[i]}];
        if (cur1.x < c[i]) {
            max_len[{a[i], b[i]}] = {c[i], i};
        }
        if (cur2.x < b[i]) {
            max_len[{a[i], c[i]}] = {b[i], i};
        }
        if (cur3.x < a[i]) {
            max_len[{b[i], c[i]}] = {a[i], i};
        }
    }
    cout << choices.size() << "\n";
    for (auto choice : choices) {
        cout << choice << " ";
    }

}   
