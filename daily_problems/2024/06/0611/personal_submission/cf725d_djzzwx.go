# Submission link: https://codeforces.com/contest/725/submission/265176005
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n int
	Fscan(in, &n)
	type Ba struct{ t, w int }
	hp := new(DHeap)
	a := make([]Ba, n)
	for i := 0; i < n; i++ {
		Fscan(in, &a[i].t, &a[i].w)
	}
	slices.SortFunc(a[1:], func(a, b Ba) int {
		return b.t - a.t
	})
	k := 1
	for ; k < n && a[k].t > a[0].t; k++ {
		hp.push(a[k].w - a[k].t)
	}
	ans := hp.Len() + 1
	for a[0].t > 0 && hp.Len() > 0 && a[0].t > (*hp)[0] {
		a[0].t -= hp.pop().(int) + 1
		for ; k < n && a[k].t > a[0].t; k++ {
			hp.push(a[k].w - a[k].t)
		}
		ans = min(ans, hp.Len()+1)
	}
	Fprintln(out, ans)
}