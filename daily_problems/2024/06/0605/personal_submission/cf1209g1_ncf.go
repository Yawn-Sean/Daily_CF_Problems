package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1209G1(os.Stdin, os.Stdout) }

func CF1209G1(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, q int
	fmt.Fscan(in, &n, &q)
	a := make([]int, n)
	last := make([]int, int(2e5+1))
	count := make([]int, int(2e5+1))
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		last[a[i]] = i
		count[a[i]] += 1
	}
	l, r := 0, 0
	mx := 0
	ans := 0
	for i := 0; i < n; i++ {
		if r < i {
			ans += r - l + 1 - mx
			l = i
			r = last[a[i]]
			mx = 0
		}
		r = max(r, last[a[i]])
		mx = max(mx, count[a[i]])
	}
	ans += r - l + 1 - mx
	fmt.Fprintf(out, "%d", ans)
}
