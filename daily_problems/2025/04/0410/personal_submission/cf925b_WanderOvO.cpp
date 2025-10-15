/*
将服务器按能力排序
资源最小的服务器用的谁才是重要的，所以只需要枚举最小的服务器用的谁
假如第一个服务用的最小的服务器提供 cnt 的能力，则至少需要 (k1 + cnt - 1) / cnt 个服务器
枚举第一个服务用的最小的服务器，快速判断第二个服务是否能部署
剩下的服务器是前缀 + 后缀
- 对于后缀，假如最小选第 i 个服务器，总共需要 cnt[i] 个服务器
  则只要 n - i + 1 >= cnt[i] 即可
  即 cnt[i] + i <= n + 1
  维护 cnt[i] + i 的后缀最小
- 对于前缀，假如最小选第 i 个服务器，总共需要 cnt[i] 个服务器
  则需要满足 n - i + 1 - 用掉的服务器 >= cnt[i]
  即 cnt[i] + i <= n - 用掉的服务器 + 1
  预处理 cnt[i] + i，求前缀最小即可
*/

PII servers[N];
int n, s1, s2, cnt[N], pre[N], suf[N];

void meibao() {
    cin >> n >> s1 >> s2;
    for (int i = 1; i <= n; i++) {
        cin >> servers[i].x;
        servers[i].y = i;
    }
    sort(servers + 1, servers + n + 1);
    for (int i = 1; i <= n; i++) {
        cnt[i] = (s1 + servers[i].x - 1) / servers[i].x;
    }
    pre[0] = INF;
    suf[n + 1] = INF;
    for (int i = 1; i <= n; i++) {
        pre[i] = min(pre[i - 1], cnt[i] + i);
    }
    for (int i = n; i > 0; i--) {
        suf[i] = min(suf[i + 1], cnt[i] + i);
    }
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        int used = (s2 + servers[i].x - 1) / servers[i].x;
        int l = i - 1, r = i + used;
        if (r > n + 1) {
            continue;
        }

        if (pre[l] <= n - used + 1 || suf[r] <= n + 1) {
            ok = true;
            cout << "Yes\n";
            int cnt1 = 0, cnt2 = used, st = 0;
            for (int j = r; j <= n; j++) {
                if (cnt[j] + j <= n + 1) {
                    cnt1 = cnt[j];
                    st = j;
                    break;
                }
            }
            if (cnt1 == 0) {
                for (int j = 1; j <= l; j++) {
                    if (cnt[j] + j <= n + 1 - used) {
                        cnt1 = cnt[j];
                        st = j;
                        break;
                    }
                }
            }
            assert(cnt1 != 0);
            cout << cnt1 << " " << cnt2 << "\n";
            for (int j = st; j <= n && cnt1 > 0; j++) {
                if (j >= i && j < i + used) {
                    continue;
                }
                cnt1--;
                cout << servers[j].y << " ";
            }
            cout << "\n";
            assert(cnt1 == 0);
            for (int j = i; j < i + used; j++) {
                cout << servers[j].y << " ";
            }
            cout << "\n";
            break;
        }
    }
    if (!ok) {
        cout << "No\n";
    }
}
