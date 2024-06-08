package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1217C(os.Stdin, os.Stdout) }

func CF1217C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t int
	fmt.Fscan(in, &t)
	var s string
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &s)
		n := len(s)
		pre := make([]int, n+1)
		for i := 0; i < n; i++ {
			if s[i] == '0' {
				pre[i+1] = pre[i] + 1
			} else {
				pre[i+1] = 0
			}
		}
		ans := 0
		for i := 0; i < n; i++ {
			if s[i] == '0' {
				continue
			}
			cur := 0
			for j := i; j < min(n, i+18); j++ {
				cur = cur*2 + int(s[j]-'0')
				if pre[i] < cur-(j-i+1) {
					break
				}
				ans += 1
			}
		}
		fmt.Fprintf(out, "%d\n", ans)
	}
}
