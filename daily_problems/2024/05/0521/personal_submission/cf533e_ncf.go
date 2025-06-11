package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF533E(os.Stdin, os.Stdout) }

func CF533E(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	var s1, s2 string
	fmt.Fscan(in, &s1, &s2)
	l, r := -1, n-1
	for i := 0; i < n; i++ {
		if s1[i] != s2[i] {
			if l == -1 {
				l = i
			}
			r = i
		}
	}
	ans := 0
	if s1[l:r] == s2[l+1:r+1] {
		ans += 1
	}
	if s1[l+1:r+1] == s2[l:r] {
		ans += 1
	}
	fmt.Fprintf(out, "%d", ans)
}
