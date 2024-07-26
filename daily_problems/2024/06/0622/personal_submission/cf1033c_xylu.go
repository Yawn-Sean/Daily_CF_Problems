func CF1033C(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	n := readNum(in)
	a := readNNums(in, n)
	nums := make([]pair, n)
	for i, v := range a {
		nums[i] = pair{v, i}
	}
	sort.Slice(nums, func(i, j int) bool { return nums[i].x > nums[j].x })
	ans := make([]byte, n)
	for _, p := range nums {
		f := false
		for i := p.y % p.x; i < n && !f; i += p.x {
			if a[i] > a[p.y] {
				f = f || (ans[i] == 'B')
			}
		}
		if f {
			ans[p.y] = 'A'
		} else {
			ans[p.y] = 'B'
		}
	}
	fmt.Fprintf(out, "%s\n", string(ans))
}
