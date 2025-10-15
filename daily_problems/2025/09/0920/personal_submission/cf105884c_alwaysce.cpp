#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Pt {
  i64 x, y;
  int id;
};
static inline i64 cross(const Pt& a, const Pt& b, const Pt& c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Graham scan
static vector<Pt> convex_hull(vector<Pt> p) {
  sort(p.begin(), p.end(), [](const Pt& a, const Pt& b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.id < b.id;
  });
  int n = (int)p.size();
  vector<Pt> lo, up;
  for (int i = 0; i < n; ++i) {
    while (lo.size() >= 2 && cross(lo[lo.size() - 2], lo.back(), p[i]) <= 0)
      lo.pop_back();
    lo.push_back(p[i]);
  }
  for (int i = n - 1; i >= 0; --i) {
    while (up.size() >= 2 && cross(up[up.size() - 2], up.back(), p[i]) <= 0)
      up.pop_back();
    up.push_back(p[i]);
  }
  lo.pop_back();
  up.pop_back();
  lo.insert(lo.end(), up.begin(), up.end());
  return lo;
}

static inline bool inside_tri_strict(const Pt& a, const Pt& b, const Pt& c,
                                     const Pt& p) {
  i64 s1 = cross(a, b, p);
  i64 s2 = cross(b, c, p);
  i64 s3 = cross(c, a, p);
  bool pos = (s1 > 0 && s2 > 0 && s3 > 0);
  bool neg = (s1 < 0 && s2 < 0 && s3 < 0);
  return pos || neg;
}

static bool inside_convex_polygon_strict(const vector<Pt>& poly, const Pt& p) {
  int m = (int)poly.size();
  if (m < 3) return false;
  if (cross(poly[0], poly[1], p) <= 0) return false;
  if (cross(poly[0], poly[m - 1], p) >= 0) return false;
  int l = 1, r = m - 1;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (cross(poly[0], poly[mid], p) > 0)
      l = mid;
    else
      r = mid;
  }
  return inside_tri_strict(poly[0], poly[l], poly[l + 1], p);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<Pt> pts(n);
    for (int i = 0; i < n; ++i) {
      cin >> pts[i].x >> pts[i].y;
      pts[i].id = i + 1;
    }

    auto hull = convex_hull(pts);
    int H = (int)hull.size();
    if (H < 3) {
      cout << -1 << '\n';
      continue;
    }

    vector<char> onHull(n + 1, 0);
    for (auto& v : hull) onHull[v.id] = 1;

    sort(pts.begin(), pts.end(),
         [](const Pt& a, const Pt& b) { return a.id < b.id; });

    bool found = false;
    for (auto& pi : pts) {
      if (onHull[pi.id]) continue;
      if (!inside_convex_polygon_strict(hull, pi)) continue;

      // 验证某个点在凸包上三点构成的三角形
      // 总是可以构造 出这样的三角形(hull[0], hull[i], hull[i+1])
      // 原因: 角度覆盖是从0-360度的 点在凸包里面 肯定在某个三角形里面(某个角度范围内部)
      int l = 1, r = H - 1;
      while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (cross(hull[0], hull[mid], pi) > 0)
          l = mid;
        else
          r = mid;
      }

      auto try_emit = [&](int a, int b, int c) -> bool {
        if (a < 0 || b < 0 || c < 0 || a >= H || b >= H || c >= H) return false;
        if (inside_tri_strict(hull[a], hull[b], hull[c], pi)) {
          cout << pi.id << ' ' << hull[a].id << ' ' << hull[b].id << ' '
               << hull[c].id << '\n';
          return true;
        }
        return false;
      };
      if (try_emit(0, l, l + 1) || try_emit(0, l - 1, l) ||
          try_emit(0, l + 1, l + 2)) {
        found = true;
        break;
      }
    }
    if (!found) cout << -1 << '\n';
  }
  return 0;
}
