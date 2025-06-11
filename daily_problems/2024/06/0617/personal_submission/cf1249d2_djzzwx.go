# Submission link: https://codeforces.com/contest/1249/submission/266127618

func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, k, mx int
	Fscan(in, &n, &k)
	a := make([]pair, n)
	for i := range a {
		Fscan(in, &a[i].l, &a[i].r)
		mx = max(mx, a[i].r)
		a[i].i = i
	}
	slices.SortFunc(a, func(a, b pair) int {
		if a.l == b.l {
			return b.r - a.r
		}
		return a.l - b.l
	})
	hp := new(DHeap)
	dif := make([]int, mx+1)
	ans := []int{}
	for i, j := 1, 0; i <= mx; i++ {
		for ; j < n && a[j].l <= i; j++ {
			hp.push(a[j])
			dif[a[j].l] += 1
			if a[j].r+1 <= mx {
				dif[a[j].r+1] -= 1
			}
		}
		dif[i] += dif[i-1]
		for ; dif[i] > k; dif[i]-- {
			p := hp.pop().(pair)
			if p.r+1 <= mx {
				dif[p.r+1] += 1
			}
			ans = append(ans, p.i+1)
		}
	}
	Fprintln(out, len(ans))
	for _, v := range ans {
		Fprint(out, v, " ")
	}
}
