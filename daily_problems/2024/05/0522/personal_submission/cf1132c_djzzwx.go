# Submission link: https://codeforces.com/contest/1132/submission/262082854

func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, m, x, y int
	Fscan(in, &n, &m)
	type pair struct{ st, en int }
	queries := make([]pair, m)
	dif := make([]int, n+2)
	for i := range queries {
		Fscan(in, &x, &y)
		queries[i] = pair{x, y}
		dif[x]++
		dif[y+1]--
	}
	for i := 1; i <= n; i++ {
		dif[i] += dif[i-1]
	}
	p1 := make([]int, n+1)
	p2 := make([]int, n+1)
	all := 0
	for i := 1; i <= n; i++ {
		p1[i] = p1[i-1]
		if dif[i] == 1 {
			p1[i] += 1
		}
		p2[i] = p2[i-1]
		if dif[i] == 2 {
			p2[i] += 1
		}
		if dif[i] > 0 {
			all++
		}
	}
	slices.SortFunc(queries, func(a, b pair) int {
		return a.en - b.en
	})
	del := math.MaxInt
	for i, q2 := range queries {
		for _, q := range queries[:i] {
			tmp := 0
			if q.en < q2.st {
				tmp += p1[q.en] - p1[q.st-1]
				tmp += p1[q2.en] - p1[q2.st-1]
			} else {
				if q.en != q2.en {
					tmp += p1[max(q2.st, q.st)] - p1[min(q2.st, q.st)-1]
					tmp += p1[q2.en] - p1[q.en-1]
					tmp += p2[q.en] - p2[max(q2.st, q.st)-1]
				} else {
					tmp += p1[max(q2.st, q.st)] - p1[min(q2.st, q.st)-1]
					tmp += p2[q.en] - p2[max(q2.st, q.st)-1]
				}
			}
			del = min(del, tmp)
		}
	}
	Fprintln(out, all-del)
}