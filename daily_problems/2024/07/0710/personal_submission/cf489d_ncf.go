package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF489D(os.Stdin, os.Stdout) }

func CF489D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m, a, b int
	fmt.Fscan(in, &n, &m)
	g := make([][]int, n+1)
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &a, &b)
		g[a] = append(g[a], b)
	}
	ans := 0
	count := make([]int, n+1)
	for i := 1; i <= n; i++ {
		for _, j := range g[i] {
			for _, k := range g[j] {
				count[k] += 1
			}
		}
		for j := 1; j <= n; j++ {
			if j != i {
				ans += count[j] * (count[j] - 1) / 2
			}
			count[j] = 0
		}
	}
	fmt.Fprintf(out, "%d", ans)
}
