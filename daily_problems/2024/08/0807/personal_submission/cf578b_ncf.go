package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF578B(os.Stdin, os.Stdout) }

func CF578B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, k, x int
	fmt.Fscan(in, &n, &k, &x)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	pre, suf := make([]int, n+1), make([]int, n+1)
	for i := 0; i < n; i++ {
		pre[i+1] = pre[i] | a[i]
	}
	for i := n; i > 0; i-- {
		suf[i-1] = suf[i] | a[i-1]
	}
	v := 1
	for i := 0; i < k; i++ {
		v *= x
	}
	ans := 0
	for i := 0; i < n; i++ {
		ans = max(ans, pre[i]|(v*a[i])|suf[i+1])
	}
	fmt.Fprintf(out, "%d", ans)
}
