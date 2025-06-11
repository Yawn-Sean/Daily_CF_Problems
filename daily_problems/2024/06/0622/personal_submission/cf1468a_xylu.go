func CF1468A(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	for T := readNum(in); T > 0; T-- {
		n := readNum(in)
		a := readNNums(in, n)
		idx := make([]int, n)
		for i := range idx {
			idx[i] = i
		}
		sort.SliceStable(idx, func(i, j int) bool { return a[idx[i]] < a[idx[j]] })

		leftBig := make([]int, n) // a[l[i]] > a[i]
		st := []int{}
		for i, v := range a {
			for len(st) > 0 && a[st[len(st)-1]] < v {
				st = st[:len(st)-1]
			}
			if len(st) > 0 {
				leftBig[i] = st[len(st)-1]
			} else {
				leftBig[i] = -1
			}
			st = append(st, i)
		}

		segtree := newSegmentTree(n)
		for _, i := range idx {
			if leftBig[i] == -1 {
				segtree.update(1, i+1, segtree.query(1, 1, i)+1)
			} else {
				// max(max(dp[0...l[i]-1]) + 2, max(dp[l[i]...i-1]) + 1)
				segtree.update(1, i+1, max(segtree.query(1, leftBig[i]+1, i)+1, segtree.query(1, 1, leftBig[i])+2))
			}
		}
		fmt.Fprintln(out, segtree.queryAll())
	}
}
