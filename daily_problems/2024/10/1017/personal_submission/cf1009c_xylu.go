func solveC(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, m, v1, v2, ans, x, d int
	Fscan(in, &n, &m)
	for i := 0; i < n; i++ {
		v1 += i
		v2 += abs(i - n/2)
	}
	for i := 0; i < m; i++ {
		Fscan(in, &x, &d)
		ans += x * n
		if d > 0 {
			ans += v1 * d
		} else {
			ans += v2 * d
		}
	}
	Fprintf(out, "%.10f", float64(ans)/float64(n))
}
