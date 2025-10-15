func cf102409j(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n int
	var L int64

	fmt.Fscan(in, &n, &L)
	xs := make([]int64, n-1)
	for i := range xs {
		fmt.Fscan(in, &xs[i])
	}

	p1, p2 := 0, 1
	ans := L
	for i := 1; i < n-2; i++ {
		for xs[p1+1] <= xs[i]-xs[p1+1] {
			p1 += 1
		}
		for p2+1 < n-1 && xs[p2+1]-xs[i] <= L-xs[p2+1] {
			p2 += 1
		}

		for u := p1; u <= min(p1+1, i-1); u++ {
			for v := p2; v <= min(p2+1, n-2); v++ {
				mi := min(xs[u], xs[i]-xs[u], xs[v]-xs[i], L-xs[v])
				ma := max(xs[u], xs[i]-xs[u], xs[v]-xs[i], L-xs[v])
				ans = min(ans, ma-mi)
			}
		}
	}

	fmt.Fprintln(out, ans)
}
