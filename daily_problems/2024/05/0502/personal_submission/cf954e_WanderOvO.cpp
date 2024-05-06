/*
sum(x[i]) = sum(x[i] * t[i]) / T, 0 <= x[i] <= a[i]
sum(x[i] * (t[i] - T)) = 0
T, t[i] 已知，要最大化 sum(x[i])
- 所有 x[i] = 0，则只有 T = 0 时才能满足题意
  如果所有 t[i] > T 或者 t[i] < T，则当且仅当 T = 0 时有唯一解 sum(x[i]) = 0
- x[i] 不全为 0
  对于 t[i] = T 的，流量直接拉满即可
  对于 t[i] > T 和 t[i] < T 的，我们考虑分正负
  对于所有 t[i] > T 的 i，我们看 sum(x[i] * (t[i] - T)) 最大能到多少
  对于所有 t[i] < T 的 i，我们看 sum(x[i] * (t[i] - T)) 最小能到多少
  让这两部分加起来等于 0，且流量尽可能大
  如果两边的上限一样，则都拉满即可
  如果不一样，以绝对值小的那个为上限，多的那边尽可能选 abs(t[i] - T) 小的
*/

int T;
PDD a[N];
vector<PDD> pos, neg;
int n;
double t;

bool cmp(const PDD &o1, const PDD &o2) {
    if (fabs(o1.y - o2.y) < eps) {
        return o1.x < o2.x;
    }
    return o1.y < o2.y;
}

void solve1() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].y;
        a[i].y -= t;
    }
    double res = 0;
    pos.clear();
    neg.clear();
    for (int i = 1; i <= n; i++) {
        if (fabs(a[i].y) < eps) {
            res += a[i].x;
        } else if (a[i].y > 0) {
            pos.pb(a[i]);
        } else {
            neg.pb({a[i].x, -a[i].y});
        }
    }
    
    sort(pos.begin(), pos.end(), cmp);
    sort(neg.begin(), neg.end(), cmp);
    
    if (pos.size() == 0 || neg.size() == 0) {
        printf("%.14lf\n", res);
        return;
    }
    
    double pos_weight_sum = 0, neg_weight_sum = 0;
    double pos_flow_sum = 0, neg_flow_sum = 0;
    for (auto &it : pos) {
        pos_weight_sum += (it.x * it.y);
        pos_flow_sum += it.x;
    }
    for (auto &it : neg) {
        neg_weight_sum += (it.x * it.y);
        neg_flow_sum += it.x;
    }
    
    if (fabs(pos_weight_sum - neg_weight_sum) < eps) {
        res += pos_flow_sum;
        res += neg_flow_sum;
    } else if (pos_weight_sum > neg_weight_sum) {
        double cur_weight_sum = 0, cur_flow_sum = 0;
        for (auto &it : pos) {
            if (cur_weight_sum + (it.x * it.y) < neg_weight_sum) {
                cur_weight_sum += (it.x * it.y);
                cur_flow_sum += it.x;
            } else {
                double d = neg_weight_sum - cur_weight_sum;
                cur_flow_sum += d / it.y;
                break;
            }
        }
        res += neg_flow_sum;
        res += cur_flow_sum;
    } else {
        double cur_weight_sum = 0, cur_flow_sum = 0;
        for (auto &it : neg) {
            if (cur_weight_sum + (it.x * it.y) < pos_weight_sum) {
                cur_weight_sum += (it.x * it.y);
                cur_flow_sum += it.x;
            } else {
                double d = pos_weight_sum - cur_weight_sum;
                cur_flow_sum += d / it.y;
                break;
            }
        }
        res += pos_flow_sum;
        res += cur_flow_sum;
    }
    printf("%.14lf\n", res);
}                