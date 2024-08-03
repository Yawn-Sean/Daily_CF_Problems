package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1561D1(os.Stdin, os.Stdout) }

func CF1561D1(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m int
	fmt.Fscan(in, &n, &m)
	mx := int(4e6 + 2)
	pre := make([]int, mx)
	f := make([]int, mx)
	f[n] = 1
	pre[n] = 1
	for i := n - 1; i > 0; i-- {
		f[i] = (f[i] + pre[i+1]) % m
		for j := 2; i*j <= n; j++ {
			f[i] = (f[i] + pre[i*j] - pre[min(i*j+j, n+1)] + m) % m
		}
		pre[i] = (pre[i+1] + f[i]) % m
	}
	fmt.Fprintf(out, "%d", f[1])
}
