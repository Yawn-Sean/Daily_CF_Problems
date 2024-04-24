package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF444A(os.Stdin, os.Stdout) }

func CF444A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, m, a, b int
	var c float64
	for t = 1; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &m)
		x := make([]float64, n+1)
		for i := 1; i <= n; i++ {
			fmt.Fscan(in, &x[i])
		}
		ans := 0.0
		for i := 0; i < m; i++ {
			fmt.Fscan(in, &a, &b, &c)
			ans = max444a(ans, (x[a]+x[b])/c)
		}
		fmt.Fprintf(out, "%.15f ", ans)
	}
}

func max444a(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}
