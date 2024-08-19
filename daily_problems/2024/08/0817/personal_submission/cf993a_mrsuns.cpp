using P = array<int, 2>;
using LI = array<P, 2>;
P uv(P u, P v) {
    return { v[0] - u[0],v[1] - u[1] };
}
int dot(P u, P v) {
    return u[0] * v[0] + u[1] * v[1];
}

int cross(P u, P v) {
    return u[0] * v[1] - u[1] * v[0];
}
int sgn(int x) {
    if (x == 0) return 0;
    else if (x > 0) return 1;
    return -1;
}
int loca(P u, P v, P w) {
    return sgn(cross(uv(u, v), uv(u, w)));
}
int next(int i, int n) {
    return i == n - 1 ? 0 : i + 1;
}
bool point_on_segment(P a, LI line) {
    return sgn(cross(uv(a, line[0]), uv(a, line[1]))) == 0
        && sgn(dot(uv(a, line[0]), uv(a, line[1]))) <= 0;
}
bool inter_judge_segment(LI a, LI b) {
    if (point_on_segment(b[0], a)
        || point_on_segment(b[1], a)
        || point_on_segment(a[0], b)
        || point_on_segment(a[1], b))
        return 1;
    //跨立试验
    return (loca(a[0], b[0], a[1]) * loca(a[0], b[1], a[1]) < 0
        && loca(b[0], a[0], b[1]) * loca(b[0], a[1], b[1]) < 0
        );
}
void Solve() {
    vector<P> a(4), b(4);
    for (int i = 0;i < 4;i++) {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 0;i < 4;i++) {
        cin >> b[i][0] >> b[i][1];
    }
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            if (inter_judge_segment({ a[i],a[next(i,4)] }, { b[j],b[next(j,4)] })) {
                return cout << "YES\n", void();
            }
        }
    }
    {
        set<int> st;
        for (int i = 0;i < 4;i++) {
            auto u = a[i], v = a[next(i, 4)];
            for (int j = 0;j < 4;j++) {
                st.insert(loca(u, v, b[j]));
            }
        }
        if (st.size() == 1) return cout << "YES\n", void();
    }
    {
        set<int> st;
        for (int i = 0;i < 4;i++) {
            auto u = b[i], v = b[next(i, 4)];
            for (int j = 0;j < 4;j++) {
                st.insert(loca(u, v, a[j]));
            }
        }
        if (st.size() == 1) return cout << "YES\n", void();
    }
    cout << "NO\n";
}
