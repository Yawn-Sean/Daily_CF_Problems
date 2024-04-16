package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF933A(os.Stdin, os.Stdout) }

// 未进行空间优化版本  https://codeforces.com/problemset/submission/933/256735050
func CF933A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	suf := make([]int, n+1)
	for i := n - 1; i > -1; i-- {
		suf[i] = suf[i+1]
		if a[i] == 2 {
			suf[i] += 1
		}
	}
	ans := max933a(suf[0], 1)
	/*
		f0 以a[i]结尾 且 未使用反转机会时1的个数
		f1 以a[i]结尾 且 已使用反转机会 且 a[i]不反转 时1的个数
		f2 以a[i]结尾 且 未使用反转机会 且 a[i]反转 时1的个数
		a[i] = 1 ->
				f0 = f0 + 1
				f1 = max(2, f1 + 1)
				f2 = f2
		a[i] = 2 ->
				f0 = f0
				f1 = f1
				f2 = max(f0, f2) + 1
	*/
	var f0, f1, f2 int
	if a[0] == 1 {
		f0 = 1
		f1 = 1
	} else {
		f2 = 1
	}
	for i := 1; i < n; i++ {
		if a[i] == 1 {
			f0, f1 = f0+1, max933a(f2, f1)+1
		} else {
			f2 = max933a(f0, f2) + 1
		}
		ans = max933a(ans, max933a(f0, max933a(f1, f2))+suf[i+1])
	}
	fmt.Fprintf(out, "%d\n", ans)
}

func max933a(a, b int) int {
	if a > b {
		return a
	}
	return b
}
