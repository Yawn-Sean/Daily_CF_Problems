# Submission link: https://codeforces.com/contest/799/submission/260727028
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, c, d, ans int
	var s string
	Fscan(in, &n, &c, &d)
	type pair struct{ b, c int }
	a := [2][]pair{}
	for i := range a {
		a[i] = make([]pair, 0, n)
	}
	for i := 0; i < n; i++ {
		var rb, rc int
		Fscan(in, &rb, &rc)
		Fscan(in, &s)
		j := int(s[0] - 'C')
		a[j] = append(a[j], pair{rb, rc})
	}
	for i := range a {
		slices.SortFunc(a[i], func(a, b pair) int {
			return cmp.Compare(a.c, b.c)
		})
	}
	mxs := [2][]int{}
	mxs[0] = make([]int, len(a[0])+1)
	mxs[1] = make([]int, len(a[1])+1)
	for i, row := range a {
		for j, p := range row {
			mxs[i][j+1] = max(mxs[i][j], p.b)
		}
	}
	costs := [2]int{c, d}
	difs := [2]int{}
	for i, row := range a {
		difs[i], _ = slices.BinarySearchFunc(row, costs[i]+1, func(p pair, i int) int {
			return cmp.Compare(p.c, i)
		})
	}
	if difs[0] > 0 && difs[1] > 0 {
		ans = max(ans, mxs[0][difs[0]]+mxs[1][difs[1]])
	}
	for k, row := range a {
		for i, p1 := range row {
			j, _ := slices.BinarySearchFunc(row[:i], pair{0, costs[k] - p1.c + 1}, func(pa pair, pa2 pair) int {
				return cmp.Compare(pa.c, pa2.c)
			})
			if j > 0 {
				ans = max(ans, p1.b+mxs[k][j])
			}
		}
	}
	Fprintln(out, ans)
}