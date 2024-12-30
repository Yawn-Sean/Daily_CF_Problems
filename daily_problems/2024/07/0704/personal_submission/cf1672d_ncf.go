package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1672D(os.Stdin, os.Stdout) }

func CF1672D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n int
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n)
		a := make([]int, n)
		b := make([]int, n)
		nx := make([]int, n)
		c := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
			c[i] = 1
		}
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &b[i])
		}
		m := map[int]int{}
		for i := n - 1; i > -1; i-- {
			idx, exist := m[a[i]]
			if exist {
				nx[i] = idx
			} else {
				nx[i] = -1
			}
			m[a[i]] = i
		}
		i, j := 0, 0
		for j < n && i < n {
			if a[i] == b[j] {
				c[i] -= 1
				if c[i] == 0 {
					i += 1
				}
				j += 1
			} else {
				nextIndex := nx[i]
				if nextIndex == -1 {
					break
				}
				c[nextIndex] += c[i]
				i += 1
			}
		}
		if j == n {
			fmt.Fprintf(out, "YES\n")
		} else {
			fmt.Fprintf(out, "NO\n")
		}
	}
}
