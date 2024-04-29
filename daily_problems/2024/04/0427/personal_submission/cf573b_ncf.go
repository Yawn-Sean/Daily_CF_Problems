package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF573B(os.Stdin, os.Stdout) }

func CF573B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	h := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &h[i])
	}
	h[0] = 1
	h[len(h)-1] = 1
	for i := 1; i < n; i++ {
		h[i] = min(h[i], h[i-1]+1)
	}
	for i := n - 2; i > -1; i-- {
		h[i] = min(h[i], h[i+1]+1)
	}
	ans := 0
	for i := 0; i < n; i++ {
		ans = max(ans, h[i])
	}
	fmt.Fprintf(out, "%d\n", ans)
}
