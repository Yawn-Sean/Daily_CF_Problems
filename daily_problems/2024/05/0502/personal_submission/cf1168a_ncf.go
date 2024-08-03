package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1168A(os.Stdin, os.Stdout) }

func CF1168A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m int
	fmt.Fscan(in, &n, &m)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	l, r := 0, m-1
	for l <= r {
		mid := (l + r) >> 1
		last := 0
		flag := true
		for _, e := range a {
			if e < last {
				if mid < last-e {
					flag = false
				}
			} else {
				if e+mid >= m && e+mid-m >= last {
					continue
				}
				last = e
			}
		}
		if flag {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	fmt.Fprintf(out, "%d\n", l)
}
