package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF645D(os.Stdin, os.Stdout) }

func CF645D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m int
	fmt.Fscan(in, &n, &m)
	us, vs := make([]int, m), make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &us[i], &vs[i])
		us[i], vs[i] = us[i]-1, vs[i]-1
	}
	var check func(count int) bool
	check = func(count int) bool {
		inDegree := make([]int, n)
		out := make([][]int, n)
		for i := 0; i < count; i++ {
			inDegree[vs[i]] += 1
			out[us[i]] = append(out[us[i]], vs[i])
		}
		num := -1
		for i := 0; i < n; i++ {
			if inDegree[i] == 0 {
				if num == -1 {
					num = i
				} else {
					return false
				}
			}
		}
		c := n - 1
		for c > 0 {
			cc := 0
			for _, e := range out[num] {
				inDegree[e] -= 1
				if inDegree[e] == 0 {
					cc += 1
					num = e
				}
			}
			if cc != 1 {
				return false
			}
			c -= 1
		}
		return true
	}
	l, r := 1, m
	for l <= r {
		mid := (l + r) / 2
		if check(mid) {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	if l == m+1 {
		fmt.Fprintf(out, "-1\n")
	} else {
		fmt.Fprintf(out, "%d\n", l)
	}
}
