# Submission link: https://codeforces.com/contest/1619/submission/264373799
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var T, n, k int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &k)
		type pair struct {
			i, x, y, t int
		}
		a := make([]pair, n)
		for i := range a {
			Fscan(in, &a[i].x, &a[i].y, &a[i].t)
			a[i].i = i
		}
		uf := newUnionFind(n)
		slices.SortFunc(a, func(a, b pair) int {
			if a.y == b.y {
				return a.x - b.x
			}
			return a.y - b.y
		})
		for i, p := range a[1:] {
			if p.y == a[i].y && p.x-a[i].x <= k {
				uf.union(p.i, a[i].i)
			}
		}
		slices.SortFunc(a, func(a, b pair) int {
			if a.x == b.x {
				return a.y - b.y
			}
			return a.x - b.x
		})
		for i, p := range a[1:] {
			if p.x == a[i].x && p.y-a[i].y <= k {
				uf.union(p.i, a[i].i)
			}
		}
		has := map[int]int{}
		for _, p := range a {
			fa := uf.find(p.i)
			if _, ok := has[fa]; !ok {
				has[fa] = p.t
			} else {
				has[fa] = min(has[fa], p.t)
			}
		}
		ts := make([]int, len(has))
		i := 0
		for _, t := range has {
			ts[i] = t
			i++
		}
		slices.Sort(ts)
		m := len(ts)
		ans := m - 1
		for i, t := range ts {
			ans = min(ans, max(t, m-i-2))
		}
		Fprintln(out, ans)
	}
}