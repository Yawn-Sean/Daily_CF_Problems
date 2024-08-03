/*
    Submission link: https://codeforces.com/contest/1148/submission/254646328
    1、把二元组分为两类：上升（a < b）和 下降(a > b)，
    2、同一类中的二元组才能拼接
    3、对于上升类：a0 < b0, a1 < b1已经满足，还需要b0 > a1,
        放缩为b0 > a0 > a1,
    4、对上升类，按照a的降序进行排序；对下降类，按照b的升序进行排序
*/
using PII = pair<int, int>;
int n, t, m;
vector<array<int, 3>> pup, pdw;

void sol()
{
    cin >> n;
    int x, y;
    for (int i = 1; i <= n; i++){
        cin >> x >> y;
        if (x > y) pdw.push_back({x, y, i});
        else pup.push_back({x, y, i});
    }
    sort(pup.begin(), pup.end(), [&](auto &a, auto &b) {
        return a[0] > b[0];
    });
    sort(pdw.begin(), pdw.end(), [&](auto &a, auto &b) {
        return a[1] < b[1];
    });
    if (pup.size() > pdw.size()) {
        cout << pup.size() << '\n';
        for (auto &[x, y, i] : pup)
            cout << i << " ";
        cout << '\n';
    } else {
        cout << pdw.size() << '\n';
        for (auto &[x, y, i] : pdw)
            cout << i << " ";
        cout << '\n';
    }

}
