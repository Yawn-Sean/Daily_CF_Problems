package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solveE(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	var s, t string
	fmt.Fscan(in, &n, &s, &t)
	l, r := -1, n
	for i := 0; i < n; i++ {
		if s[i] != t[i] {
			if l == -1 {
				l = i
			}
			r = i
		}
	}
	// s 和 t 前缀[0, l) 和 后缀(r, n-1] 是相同的
	// 分别判断 s[l+1:r+1] 和 s[l:r] 是否等于 t[l:r] 和 t[l+1:r+1]
	ans := 0
	if s[l+1:r+1] == t[l:r] {
		ans++
	}
	if s[l:r] == t[l+1:r+1] {
		ans++
	}
	fmt.Fprintln(out, ans)
}

func main() {
	solveE(os.Stdin, os.Stdout)
}
