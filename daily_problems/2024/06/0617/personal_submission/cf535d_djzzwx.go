# Submission link: https://codeforces.com/contest/535/submission/266140159

func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, m int
	var s string
	Fscan(in, &n, &m, &s)
	a := make([]byte, n+1)
	mxs := make([]int, m)
	for i := range mxs {
		Fscan(in, &mxs[i])
	}
	slices.SortFunc(mxs, func(a, b int) int {
		return b - a
	})
	z := zFunc(s)
	sn := len(s)
nxt:
	for _, x := range mxs {
		for j := range s {
			if a[x+j] > '0' {
				if z[j] != sn-j {
					Fprintln(out, 0)
					return
				}
				continue nxt
			}
			a[x+j] = s[j]
			n--
		}
	}
	Fprintln(out, powMod(26, n, int(1e9+7)))
}