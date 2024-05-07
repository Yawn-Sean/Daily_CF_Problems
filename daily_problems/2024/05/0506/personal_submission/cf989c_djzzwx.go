func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	ans := make([][]string, 50)
	for i := range ans {
		ans[i] = make([]string, 50)
	}
	a := [4]int{}
	for i := range a {
		Fscan(in, &a[i])
	}
	ss := []string{"A", "B", "C", "D"}
	for i := 0; i < 50; i++ {
		for j := 0; j < 50; j++ {
			var k int
			if i >= 25 {
				k++
			}
			k *= 2
			if j >= 25 {
				k++
			}
			ans[i][j] = ss[k]
		}
	}
	for i := range a {
		x, y := (i+1)%4/2, (i+1)%4%2
		for j := 1; j < 22; j += 2 {
			for k := 1; k < 22; k += 2 {
				if a[i] > 1 {
					ans[j+x*25][k+y*25] = ss[i]
					a[i]--
				}
			}
		}
	}
	Fprintln(out, 50, 50)
	for _, row := range ans {
		Fprintln(out, strings.Join(row, ""))
	}
}
