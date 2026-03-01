func main() {
	in, out := bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)
	defer out.Flush()
	const M = 1_000_000
	fm, cnts := make([]int, M+1), make([]int, M+1)
	for i := range fm {
		fm[i] = i
	}
	for i := 2; i <= M; i++ {
		if fm[i] == i {
			for j := i; j <= M; j += i {
				cnts[j] += 1
				if fm[j] == j {
					fm[j] = i
				}
			}
		}
	}

	var T, n int
	for fmt.Fscan(in, &T); T > 0; T-- {
		fmt.Fscan(in, &n)
		a := make([]int, n)
		for i := range a {
			fmt.Fscan(in, &a[i])
		}
		check := func() bool {
			for i := 1; i < n; i++ {
				if a[i] < a[i-1] {
					return false
				}
			}
			return true
		}
		if check() {
			fmt.Fprintln(out, "Bob")
			continue
		}

		var flg bool
		for i := range a {
			if cnts[a[i]] > 1 {
				flg = true
				break
			}
			a[i] = fm[a[i]]
		}
		if flg {
			fmt.Fprintln(out, "Alice")
		} else {
			if check() {
				fmt.Fprintln(out, "Bob")
			} else {
				fmt.Fprintln(out, "Alice")
			}
		}
	}
}
