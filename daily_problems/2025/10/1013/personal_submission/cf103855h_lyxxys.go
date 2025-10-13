func cf103855h(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	mod := int64(1e9 + 7)

	var n int
	fmt.Fscan(in, &n)
	idx := make([]int, n)
	for i := range idx {
		var x int
		fmt.Fscan(in, &x)
		x -= 1
		idx[x] = i
	}

	l, res := idx[n-1], int64(1)
	for i := n - 2; i >= 0; i-- {
		if idx[i] < l {
			res = (res * int64(l-idx[i]+1)) % mod
			l = idx[i]
		}
	}

	fmt.Fprintln(out, res)
}
