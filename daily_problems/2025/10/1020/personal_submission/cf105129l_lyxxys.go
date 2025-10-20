func cf105129l(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var T, n int
	fmt.Fscan(in, &T)
	prime := []int64{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}
	all := 1 << 15

	for _ = range T {
		fmt.Fscan(in, &n)
		vis := make([]int64, 51)
		var x int
		for _ = range n {
			fmt.Fscan(in, &x)
			vis[x] = 1
		}
		var res int64
		res = math.MaxInt64

		for mask := range all {
			success := true
			ans := int64(1)
			for i := range 15 {
				if (mask >> i & 1) > 0 {
					ans = ans * prime[i]
				}
			}
			for i := range vis {
				if vis[i] > 0 && gcd(ans, int64(i)) <= 1 {
					success = false
					break
				}
			}
			if success {
				res = min(res, ans)
			}
		}

		fmt.Fprintln(out, res)
	}
}
