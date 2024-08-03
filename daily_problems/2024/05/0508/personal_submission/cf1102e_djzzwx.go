func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, x int
	Fscan(in, &n)
	left := map[int]int{}
	right := map[int]int{}
	for i := 0; i < n; i++ {
		Fscan(in, &x)
		if _, ok := left[x]; !ok {
			left[x] = i
		}
		right[x] = i
	}
	diff := make([]int, n)
	for k, l := range left {
		diff[l]++
		diff[right[k]]--
	}
	mod := 998244353
	ans := 0
	c := 0
	for _, v := range diff {
		c += v
		if c == 0 {
			if ans == 0 {
				ans = 1
			} else {
				ans = ans * 2 % mod
			}
		}
	}
	Fprintln(out, ans)
}