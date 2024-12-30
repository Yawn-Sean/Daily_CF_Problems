package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1153C(os.Stdin, os.Stdout) }

func CF1153C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	var s string
	fmt.Fscan(in, &s)
	if n == 1 || s[0] != '(' && s[0] != '?' || s[n-1] != ')' && s[n-1] != '?' {
		fmt.Fprintf(out, ":(")
		return
	}
	ans := make([]rune, n)
	ans[0] = '('
	ans[n-1] = ')'
	var st []int
	cur := 0
	for i := 1; i < n-1; i++ {
		if s[i] == '(' {
			cur += 1
			ans[i] = '('
		} else if s[i] == ')' {
			cur -= 1
			ans[i] = ')'
		} else {
			cur -= 1
			st = append(st, i)
			ans[i] = ')'
		}
		if cur < 0 {
			if len(st) > 0 {
				p := st[len(st)-1]
				st = st[:len(st)-1]
				ans[p] = '('
				cur += 2
			} else {
				fmt.Fprintf(out, ":(")
				return
			}
		}
	}
	if cur != 0 {
		fmt.Fprintf(out, ":(")
		return
	}
	fmt.Fprintf(out, "%s", string(ans))
}
