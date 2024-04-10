package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF439D(os.Stdin, os.Stdout) }

func CF439D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m int
	fmt.Fscan(in, &n, &m)
	a, b := make([]int, n), make([]int, m)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &b[i])
	}
	sort.Ints(a)
	sort.Slice(b, func(i, j int) bool {
		return b[i] > b[j]
	})
	ans := 0
	for i := 0; i < m && i < n && a[i] < b[i]; i++ {
		ans += b[i] - a[i]
	}
	fmt.Fprintf(out, "%d\n", ans)
}
