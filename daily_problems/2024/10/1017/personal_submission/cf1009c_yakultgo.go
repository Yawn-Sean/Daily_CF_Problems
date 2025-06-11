package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, m int
	fmt.Fscan(in, &n, &m)
	sum := 0
	var x, d int
	for i := 1; i <= m; i++ {
		fmt.Fscan(in, &x, &d)
		sum += x * n
		if d > 0 {
			sum += d * n * (n - 1) / 2
		} else {
			sum += d * (n / 2) * (n/2 + 1)
			if n%2 == 0 {
				sum -= d * n / 2
			}
		}
	}
	ans := float64(sum) / float64(n)
	fmt.Fprintf(out, "%.15f\n", ans)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
