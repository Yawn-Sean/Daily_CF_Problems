func main() { CF924B(os.Stdin, os.Stdout) }

func CF924B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, u int
	fmt.Fscan(in, &n, &u)
	e := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &e[i])
	}
	ans := 0.0
	l, r := 0, 0
	for l < n {
		for r < n && e[r]-e[l] <= u {
			r += 1
		}
		if r-l > 2 {
			ans = max924b(ans, float64(e[r-1]-e[l+1])/float64(e[r-1]-e[l]))
		}
		l += 1
	}
	if ans == 0.0 {
		fmt.Fprintf(out, "-1")
	} else {
		fmt.Fprintf(out, "%.12f ", ans)
	}
}

func max924b(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}
