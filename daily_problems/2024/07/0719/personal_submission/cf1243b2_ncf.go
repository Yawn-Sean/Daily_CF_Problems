package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1243B2(os.Stdin, os.Stdout) }

func CF1243B2(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n int
	var a, b string
	fmt.Fscan(in, &t)
out:
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &a, &b)
		c := make([]int, 26)
		for _, e := range a {
			c[e-'a'] += 1
		}
		for _, e := range b {
			c[e-'a'] += 1
		}
		for i := 0; i < 26; i++ {
			if c[i]%2 != 0 {
				fmt.Fprintf(out, "No\n")
				continue out
			}
		}
		fmt.Fprintf(out, "Yes\n")
		s1, s2 := make([]uint8, n), make([]uint8, n)
		for i := 0; i < n; i++ {
			s1[i] = a[i]
			s2[i] = b[i]
		}
		var ans [][]int
		for i := 0; i < n; i++ {
			if s1[i] != s2[i] {
				for j := i + 1; j < n; j++ {
					if s2[i] == s2[j] {
						s2[j], s1[i] = s1[i], s2[j]
						ans = append(ans, []int{i + 1, j + 1})
						break
					}
				}
				if s1[i] != s2[i] {
					for j := i + 1; j < n; j++ {
						if s1[j] == s2[i] {
							s1[j] = s2[n-1]
							ans = append(ans, []int{j + 1, n})
							s2[n-1] = s1[i]
							ans = append(ans, []int{i + 1, n})
							break
						}
					}
				}
			}
		}
		fmt.Fprintf(out, "%d\n", len(ans))
		for _, e := range ans {
			fmt.Fprintf(out, "%d %d\n", e[0], e[1])
		}
	}
}
