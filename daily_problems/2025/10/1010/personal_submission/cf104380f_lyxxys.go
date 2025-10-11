func cf104380f(in io.Reader, _out io.Writer) {
	out := bufio.NewWriter(_out)
	defer out.Flush()
	var n, L, R int
	Fscan(in, &n, &L, &R)
	arr := make([]int, 0, n)
	for i := 1; i <= n; i++ {
		var x int
		Fscan(in, &x)
		l, r := n-i+1, i
		if l < r && l < L && r > R {
			continue
		}
		arr = append(arr, x)
	}
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] > arr[j]
	})
	var sum int64 = 0
	for _, v := range arr[:R-L+1] {
		sum += int64(v)
	}

	Fprintln(out, sum)
}
