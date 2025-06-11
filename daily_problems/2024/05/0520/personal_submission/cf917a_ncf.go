package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF917A(os.Stdin, os.Stdout) }

func CF917A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var s string
	fmt.Fscan(in, &s)
	ans := 0
	n := len(s)
out:
	for i := 0; i < n; i++ {
		// c1 左括号+1，右括号-1
		// c2 可用于转左括号的（问号转成的右括号）的数量
		c1, c2 := 0, 0
		for j := i; j < n; j++ {
			if s[j] == '(' {
				c1 += 1
			} else if s[j] == ')' {
				c1 -= 1
			} else {
				// 遇到问号直接默认右括号
				c1 -= 1
				c2 += 1
			}
			if c1 < 0 {
				if c2 > 0 {
					// 将问号变的右括号转成左括号
					c2 -= 1
					c1 += 2
				} else {
					// 没有问号变的右括号了，从这里开始的字符串全都不符合
					continue out
				}
			}
			if (j-i)%2 == 1 && c1 == 0 {
				ans += 1
			}
		}
	}
	fmt.Fprintf(out, "%d", ans)
}
