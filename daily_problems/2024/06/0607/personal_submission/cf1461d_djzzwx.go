# Submission link: https://codeforces.com/contest/1461/submission/264530422
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var T, n, q, s int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &q)
		a := make([]int, n)
		for i := range a {
			Fscan(in, &a[i])
		}
		slices.Sort(a)
		ps := make([]int, n+1)
		for i, v := range a {
			ps[i+1] = ps[i] + v
		}
		has := map[int]bool{}
		var dfs func(l, r int)
		dfs = func(l, r int) {
			sum := ps[r+1] - ps[l]
			has[sum] = true
			if l == r {
				return
			}
			m := (a[l] + a[r]) / 2
			k, _ := slices.BinarySearch(a, m+1)
			if k > r {
				return
			}
			dfs(l, k-1)
			dfs(k, r)
		}
		dfs(0, n-1)
		for ; q > 0; q-- {
			Fscan(in, &s)
			if has[s] {
				Fprintln(out, "YES")
			} else {
				Fprintln(out, "NO")
			}
		}
	}
}