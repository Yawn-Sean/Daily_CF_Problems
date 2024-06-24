# Submission link: https://codeforces.com/contest/609/submission/263101370
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, m, k, s int
	Fscan(in, &n, &m, &k, &s)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}
	b := make([]int, n)
	for i := range b {
		Fscan(in, &b[i])
	}
	ms := make([][2]int, m)
	for i := range ms {
		Fscan(in, &ms[i][0], &ms[i][1])
	}
	const inf int = 0x3f3f3f3f
	type cp struct{ i, c, t int }
	c := make([]cp, m)
	resC := make([]cp, m)
	res := sort.Search(n+1, func(i int) bool {
		mia, mib, mja, mjb := inf, inf, inf, inf
		for j := 0; j < i; j++ {
			if a[j] < mia {
				mia = a[j]
				mja = j + 1
			}
			if b[j] < mib {
				mib = b[j]
				mjb = j + 1
			}
		}
		for j, v := range ms {
			c[j].i = j + 1
			if v[0] == 1 {
				c[j].c = v[1] * mia
				c[j].t = mja
			} else {
				c[j].c = v[1] * mib
				c[j].t = mjb
			}
		}
		slices.SortFunc(c, func(a, b cp) int {
			return a.c - b.c
		})
		tot := 0
		for _, v := range c[:k] {
			tot += v.c
		}
		if s >= tot {
			copy(resC, c)
			return true
		}
		return false
	})
	if res == n+1 {
		Fprintln(out, -1)
		return
	}
	Fprintln(out, res)
	for _, rc := range resC[:k] {
		Fprintln(out, rc.i, rc.t)
	}
}
