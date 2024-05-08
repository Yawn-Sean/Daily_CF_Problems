func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var T, n, m, k int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n, &m, &k)
		a := make([]int, n)
		b := make([]int, m)
		for i := range a {
			Fscan(in, &a[i])
		}
		for i := range b {
			Fscan(in, &b[i])
		}
		cntx := make([]int, n)
		cnty := make([]int, m)
		cntxcnt := make([]map[int]int, n)
		cntycnt := make([]map[int]int, m)
		for i := range cntxcnt {
			cntxcnt[i] = map[int]int{}
		}
		for i := range cntycnt {
			cntycnt[i] = map[int]int{}
		}
		for ; k > 0; k-- {
			var x, y int
			Fscan(in, &x, &y)
			x0 := sort.SearchInts(a, x)
			y0 := sort.SearchInts(b, y)
			if a[x0] == x && b[y0] == y {
				continue
			}
			if x == a[x0] {
				cnty[y0] += 1
				cntxcnt[x0][y0] += 1
			} else {
				cntx[x0] += 1
				cntycnt[y0][x0] += 1
			}
		}
		var ans int
		for i := range a {
			ans += cntx[i] * (cntx[i] - 1) / 2
			for _, v := range cntxcnt[i] {
				ans -= v * (v - 1) / 2
			}
		}
		for i := range b {
			ans += cnty[i] * (cnty[i] - 1) / 2
			for _, v := range cntycnt[i] {
				ans -= v * (v - 1) / 2
			}
		}
		Fprintln(out, ans)
	}
}
