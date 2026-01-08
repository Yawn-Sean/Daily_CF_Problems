func main() {
	const mod, tot = int(1e9 + 7), int(3e5)
	f := make([]int, tot+1)
	f[0] = 1
	for i := 1; i <= tot; i++ {
		f[i] = f[i-1] * i % mod
	}

	var n, T int
	in, out := bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)
	defer out.Flush()
	for fmt.Fscan(in, &T); T > 0; T-- {
		fmt.Fscan(in, &n)
		x := n / 2
		ans := f[x] * f[n-x] % mod
		if n%2 == 0 {
			ans = ans * (x + 1) % mod
		} else {
			y := (x + 2) * (x + 1) / 2
			ans = ans * y % mod
		}
		fmt.Fprintln(out, ans)
	}
}
