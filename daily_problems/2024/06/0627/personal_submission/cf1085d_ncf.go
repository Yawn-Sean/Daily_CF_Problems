package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1085D(os.Stdin, os.Stdout) }

func CF1085D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, s, a, b int
	fmt.Fscan(in, &n, &s)
	g := make([]int, n+1)
	for i := 1; i < n; i++ {
		fmt.Fscan(in, &a, &b)
		g[a] += 1
		g[b] += 1
	}
	count := 0
	for i := 1; i <= n; i++ {
		if g[i] == 1 {
			count += 1
		}
	}
	fmt.Fprintf(out, "%.12f\n", float64(s*2)/float64(count))
}
