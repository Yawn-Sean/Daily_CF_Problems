func cf104785k(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	ans, ans1, ans2 := make([]int32, 0), make([]int32, 0), make([]int32, 0)

	var n, m int32
	fmt.Fscan(in, &n, &m)
	for i := range n {
		var u, v int32
		fmt.Fscan(in, &u, &v)
		if u > v {
			ans1 = append(ans1, i+1)
		} else {
			ans2 = append(ans2, i+1)
		}
	}
	if len(ans1) > len(ans2) {
		ans = ans1
	} else {
		ans = ans2
	}
	fmt.Fprintln(out, "YES")
	fmt.Fprintln(out, len(ans))
	for i, x := range ans {
		if i > 0 {
			fmt.Fprint(out, " ")
		}
		fmt.Fprint(out, x)
	}
	fmt.Fprintln(out)
}
