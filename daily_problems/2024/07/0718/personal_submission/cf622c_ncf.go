package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF622C(os.Stdin, os.Stdout) }

func CF622C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m, l, r, x int
	fmt.Fscan(in, &n, &m)
	a := make([]int, n)
	last := make([]int, n)
	fmt.Fscan(in, &a[0])
	last[0] = -1
	for i := 1; i < n; i++ {
		fmt.Fscan(in, &a[i])
		if a[i] == a[i-1] {
			last[i] = last[i-1]
		} else {
			last[i] = i - 1
		}
	}
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &l, &r, &x)
		l, r = l-1, r-1
		v := -1
		if a[r] != x {
			v = r + 1
		} else if last[r] >= l {
			v = last[r] + 1
		}
		fmt.Fprintf(out, "%d\n", v)
	}
}
