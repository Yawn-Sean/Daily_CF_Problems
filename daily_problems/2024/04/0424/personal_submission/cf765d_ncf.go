package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF765D(os.Stdin, os.Stdout) }

func CF765D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	f := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &f[i])
		f[i] -= 1
	}
	var fixPoints []int
	for i := 0; i < n; i++ {
		if f[f[i]] != f[i] {
			fmt.Fprintf(out, "-1\n")
			return
		}
		if f[i] == i {
			fixPoints = append(fixPoints, i)
		}
	}
	m := len(fixPoints)
	g, h := make([]int, n), make([]int, m)

	d := map[int]int{}
	for i, v := range fixPoints {
		d[v] = i
	}

	for i := 0; i < n; i++ {
		g[i] = d[f[i]]
		if f[i] == i {
			h[g[i]] = i
		}
	}
	fmt.Fprintf(out, "%d\n", m)
	for _, e := range g {
		fmt.Fprintf(out, "%d ", e+1)
	}
	fmt.Fprintf(out, "\n")
	for _, e := range h {
		fmt.Fprintf(out, "%d ", e+1)
	}
}
