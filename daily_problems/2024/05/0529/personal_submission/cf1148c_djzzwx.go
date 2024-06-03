# Submission link: https://codeforces.com/contest/1148/submission/263080356
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)

	defer out.Flush()
	var n int
	Fscan(in, &n)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}
	ops := [][2]int{}
	m := n / 2
	swap := func(i, j int) {
		a[i], a[j] = a[j], a[i]
	}
	do := func(i, j int) {
		ops = append(ops, [2]int{i, j})
		swap(i, j)
	}
	if a[0] != 1 {
		for i, v := range a {
			if v == 1 {
				if i >= m {
					do(0, i)
				} else {
					do(i, n-2)
					do(n-2, 0)
				}
				break
			}
		}
	}
	if a[n-1] != n {
		for i, v := range a {
			if v == n {
				if i < m {
					do(i, n-1)
				} else {
					do(i, 1)
					do(1, n-1)
				}
				break
			}
		}
	}
	do2 := func(k1, k2, k3, k4 int) {
		ops = append(ops, [2]int{k1, k3})
		ops = append(ops, [2]int{k2, k4})
		ops = append(ops, [2]int{k1, k4})
		ops = append(ops, [2]int{k1, k3})
		ops = append(ops, [2]int{k2, k4})
		swap(k1, k3)
		swap(k2, k4)
		swap(k1, k4)
		swap(k1, k3)
		swap(k2, k4)
	}
	for i := 1; i < n-1; i++ {
		for a[i]-1 != i {
			v := a[i]
			if v == i+1 {
				continue
			}
			if v-1 < m && i < m {
				do(i, n-1)
				do(v-1, n-1)
				do(i, n-1)
			} else if v-1 >= m && i >= m {
				do(i, 0)
				do(v-1, 0)
				do(i, 0)
			} else {
				if i >= m {
					do2(0, v-1, i, n-1)
				} else {
					do2(0, i, v-1, n-1)
				}
			}
		}
	}
	Fprintln(out, len(ops))
	for _, op := range ops {
		Fprintln(out, op[0]+1, op[1]+1)
	}
}
