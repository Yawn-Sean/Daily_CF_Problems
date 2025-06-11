package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solveA(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var s string
	fmt.Fscan(in, &s)
	n, ans := len(s), 0
	for i := 0; i < n; i++ {
		cnt, cq := 0, 0
		for j := i; j < n; j++ {
			if s[j] == '(' {
				cnt++
			} else if s[j] == ')' {
				cnt--
			} else {
				// 先假定为右括号
				cnt, cq = cnt-1, cq+1
			}

			if cnt < 0 && cq > 0 {
				// 把最前面的右括号改为左括号
				cnt, cq = cnt+2, cq-1
			}

			if cnt == 0 {
				ans++
			} else if cnt < 0 {
				// 后续不可能匹配
				break
			}
		}
	}
	fmt.Fprintln(out, ans)
}

func main() {
	solveA(os.Stdin, os.Stdout)
}
