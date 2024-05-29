package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solveB(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var s string
	fmt.Fscan(in, &s)
	// 长度 >= 9 一定满足
	n := len(s)
	ans := n*(n-1)/2 - (n - 1) // 长度 >=3 的子串个数

	check := func(l, r int) int {
		for i := l; i < r-1; i++ {
			for j := i + 1; j < r; j++ {
				if s[i] == s[j] && 2*j-i <= r && s[j] == s[2*j-i] {
					return 0
				}
			}
		}
		return 1
	}

	for len := 3; len < 9; len++ {
		for i := 0; i+len <= n; i++ {
			ans -= check(i, i+len-1)
		}
	}
	fmt.Fprintln(out, ans)
}

func main() {
	solveB(os.Stdin, os.Stdout)
}
