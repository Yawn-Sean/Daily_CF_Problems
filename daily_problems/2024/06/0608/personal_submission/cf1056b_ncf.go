package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1056B(os.Stdin, os.Stdout) }

func CF1056B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m int
	fmt.Fscan(in, &n, &m)
	a := make([]int, m)

	div := n / m
	for i := 1; i <= m; i++ {
		a[i*i%m] += 1
	}
	for i := 0; i < m; i++ {
		a[i] *= div
	}

	remainder := n % m
	for i := 1; i <= remainder; i++ {
		a[i*i%m] += 1
	}

	ans := a[0] * a[0]
	for i := 1; i < m; i++ {
		ans += a[i] * a[m-i]
	}
	fmt.Fprintf(os.Stdout, "%d", ans)
}
