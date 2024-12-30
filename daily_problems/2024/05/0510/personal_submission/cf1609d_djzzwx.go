# Submission link: https://codeforces.com/contest/1609/submission/260217793
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, d, x, y int
	Fscan(in, &n, &d)
	sur := 1
	uf := newUnionFind(n + 1)
	for i := 0; i < d; i++ {
		Fscan(in, &x, &y)
		if uf.find(x) == uf.find(y) {
			sur++
		} else {
			uf.union(x, y)
		}
		us := []int{}
		for j := 1; j <= n; j++ {
			if j == uf.find(j) {
				us = append(us, uf.getSize(j))
			}
		}
		slices.Sort(us)
		ans := -1
		cur := sur
		for j := len(us) - 1; j >= 0 && cur > 0; j-- {
			ans += us[j]
			cur--
		}
		Fprintln(out, ans)
	}
}