package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF863D(os.Stdin, os.Stdout) }

func CF863D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, q, m, t, l, r int
	fmt.Fscan(in, &n, &q, &m)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	queries := make([][]int, q)
	for i := 0; i < q; i++ {
		fmt.Fscan(in, &t, &l, &r)
		queries[i] = []int{t, l, r}
	}
	b := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &b[i])
	}
	for i := q - 1; i > -1; i-- {
		query := queries[i]
		if query[0] == 1 {
			for j := 0; j < m; j++ {
				if query[1]+1 <= b[j] && b[j] <= query[2] {
					b[j] -= 1
				} else if b[j] == query[1] {
					b[j] = query[2]
				}
			}
		} else {
			for j := 0; j < m; j++ {
				if query[1] <= b[j] && b[j] <= query[2] {
					b[j] = query[1] + query[2] - b[j]
				}
			}
		}
	}
	for i := 0; i < m; i++ {
		fmt.Fprintf(out, "%d ", a[b[i]-1])
	}
}
