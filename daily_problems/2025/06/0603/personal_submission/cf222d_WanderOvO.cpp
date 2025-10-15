/*
题目给定了我总得分的最小值，所以最大值可以是两天各自的最大值加起来，因此最好名次一定是第一，下面只需要考虑最差名次怎么求
不妨把两天的分数分别排个序
事实上，我们其实就是要构造尽可能多的对，使得这些对的和 >= x，有多少对则自己最差成绩就是多少名
假设能构造出 cnt 对，使得和 >= x，如何检查是否真的可以？
最可能的情况是选这两天分别的前 cnt 大，然后进行组合
二分答案，检查时在 multiset 上二分，带两个 log
*/

int n, x, a[N], b[N];

void meibao() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    reverse(a + 1, a + n + 1);
    reverse(b + 1, b + n + 1);
    cout << "1 ";
    int l = 1, r = n, mid;

    auto check = [&] (int ans) -> bool {
        multiset<int> st;
        for (int i = 1; i <= ans; i++) {
            st.insert(a[i]);
        }

        for (int i = 1; i <= ans; i++) {
            int min_val = x - b[i];
            auto it = st.lower_bound(min_val);
            if (it != st.end()) {
                st.erase(it);
            } else {
                return false;
            }
        }
        return true;
    };

    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (check(r)) {
        cout << r << "\n";
    } else {
        cout << l << "\n";
    }
}
