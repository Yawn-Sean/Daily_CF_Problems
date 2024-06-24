package main

import (
	"bufio"
	"fmt"
	"os"
)

// 优先将右括号填在最右边的问号
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	var s string
	fmt.Fscan(in, &s)
	t, p := 0, 0
	for _, v := range s {
		if v == '(' {
			t++
		} else if v == ')' {
			t--
		} else {
			p++
		}
	}
	if abs(t) > p || (p-abs(t))%2 == 1 {
		fmt.Fprintln(out, ":(")
		return
	}
	right := 0
	if t > 0 {
		right = t + (p-t)/2
	} else {
		right = (p + t) / 2
	}
	str := []byte(s)
	for i := n - 1; i >= 0; i-- {
		if str[i] == '?' {
			if right > 0 {
				str[i] = ')'
				right--
			} else {
				str[i] = '('
			}
		}
	}
	s = string(str)
	cur := 0
	for i := 0; i < n; i++ {
		if s[i] == '(' {
			cur++
		} else {
			cur--
		}
		if cur < 0 {
			fmt.Fprintln(out, ":(")
			return
		}
		if cur == 0 && i < n-1 {
			fmt.Fprintln(out, ":(")
			return
		}
	}
	fmt.Fprintln(out, s)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
