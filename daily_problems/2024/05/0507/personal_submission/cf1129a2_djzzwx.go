
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, m, a, b int
	Fscan(in, &n, &m)
	cnt := make([]int, n)
	to := make([]int, n)
	for i := range to {
		to[i] = math.MaxInt
	}
	for ; m > 0; m-- {
		Fscan(in, &a, &b)
		a--
		b--
		to[a] = min(to[a], (b-a+n)%n)
		cnt[a]++
	}
	ans := make([]int, n)
	for i := range ans {
		for j := 0; j < n; j++ {
			t := (i + j) % n
			if cnt[t] > 0 {
				ans[i] = max(ans[i], j+(cnt[t]-1)*n+to[t])
			}
		}
	}
	for _, v := range ans {
		Fprint(out, v, " ")
	}
}
