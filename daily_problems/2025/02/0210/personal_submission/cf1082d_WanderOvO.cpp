/*
图连通、无重边和自环、直径尽可能长，如何去保证？
度为 1 的点，只能作为图的“端点”，可以不着急去连这样的点
度 >= 2 的点，可以变成链的中间部分，连链肯定是更长的做法
假如从一个图里面搞出一个生成树，那么这个生成树的直径一定不会更短
所以事实上就是构造一棵直径最长的树就好了，多余的边不会更优
我们先把所有度 >= 2 的点连到一起，得到一条链
然后剩下所有度 <= 1 的点，挂到链上剩余度 > 0 的点上，优先挂两头，剩下的随意
倘若无地方可挂了，说明连通不了
*/

int n, a[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int res = 0;
    vector<PII> e;
    vector<int> v1, v2;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            v1.push_back(i);
        } else {
            v2.push_back(i);
        }
    }

    for (int i = 0; i + 1 < v2.size(); i++) {
        e.push_back({v2[i], v2[i + 1]});
        a[v2[i]]--;
        a[v2[i + 1]]--;
        res++;
    }

    if (v2.size() > 0) {
        bool first = false, last = false;
        for (int i = 0; i < v1.size(); i++) {
            if (!first && a[v2[0]] > 0) {
                a[v2[0]]--;
                res++;
                e.push_back({v1[i], v2[0]});
                first = true;
            } else if (!last && a[v2.back()] > 0) {
                a[v2.back()]--;
                res++;
                e.push_back({v1[i], v2.back()});
                last = true;
            } else {
                bool ok = false;
                for (int j = 0; j < v2.size(); j++) {
                    if (a[v2[j]] > 0) {
                        a[v2[j]]--;
                        ok = true;
                        e.push_back({v1[i], v2[j]});
                        break;
                    }
                }
                if (!ok) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    } else {
        cout << "NO\n";
        return;
    }

    cout << "YES " << res << "\n";
    cout << e.size() << "\n";
    for (auto edge : e) {
        cout << edge.x << " " << edge.y << "\n";
    }
}
