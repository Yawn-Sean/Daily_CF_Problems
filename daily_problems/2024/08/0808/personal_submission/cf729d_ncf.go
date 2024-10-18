package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF729D(os.Stdin, os.Stdout) }

func CF729D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, a, b, k int
	var s string
	fmt.Fscan(in, &n, &a, &b, &k, &s)
	var ans []int
	cnt := 0
	for i := 0; i < n; i++ {
		if s[i] == '1' {
			cnt = 0
		} else {
			cnt++
			if cnt == b {
				cnt = 0
				ans = append(ans, i+1)
			}
		}
	}
	fmt.Fprintf(out, "%d\n", max(0, len(ans)-a+1))
	for i := 0; i < max(0, len(ans)-a+1); i++ {
		fmt.Fprintf(out, "%d ", ans[i])
	}
}
