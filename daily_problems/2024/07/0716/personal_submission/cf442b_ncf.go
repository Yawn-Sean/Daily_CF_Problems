package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF442B(os.Stdin, os.Stdout) }

func CF442B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	p := make([]float64, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &p[i])
	}
	sort.Slice(p, func(i, j int) bool {
		return p[i] > p[j]
	})
	p0, p1 := 1.0, 0.0
	ans := 0.0

	for _, e := range p {
		p1 = p1*(1-e) + p0*e
		p0 *= 1 - e
		ans = max(ans, p1)
		if p0 <= p1 {
			break
		}
	}
	fmt.Fprintf(out, "%.12f", ans)
}
