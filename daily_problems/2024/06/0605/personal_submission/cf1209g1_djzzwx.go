# Submission link: https://codeforces.com/contest/1209/submission/264234972
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, q int
	Fscan(in, &n, &q)
	a := make([]int, n)
	cnt := map[int]int{}
	pos := map[int]int{}
	for i := range a {
		Fscan(in, &a[i])
		pos[a[i]] = i
		cnt[a[i]]++
	}
	l, r, mx := 0, 0, 0
	ans := 0
	for i, v := range a {
		if r < i {
			ans += r - l + 1 - mx
			l, r, mx = i, pos[v], 0
		} else {
			r = max(r, pos[v])
		}
		mx = max(mx, cnt[v])
	}
	if l < r {
		ans += r - l + 1 - mx
	}
	Fprintln(out, ans)
}