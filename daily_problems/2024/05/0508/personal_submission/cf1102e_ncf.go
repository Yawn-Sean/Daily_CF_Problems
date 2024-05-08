package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1102E(os.Stdin, os.Stdout) }

func CF1102E(_r io.Reader, _o io.Writer) {
	const eof = 0
	out := bufio.NewWriter(_o)
	defer out.Flush()
	_i, _n, buf := 0, 0, make([]byte, 1<<12) // 4KB
	var n int
	// 读一个字符
	rc := func() byte {
		if _i == _n {
			_n, _ = os.Stdin.Read(buf)
			// EOF 一定要判断！不判断会 RE：https://codeforces.com/problemset/submission/323/250522741
			if _n == 0 { // EOF
				return eof
			}
			_i = 0
		}
		b := buf[_i]
		_i++
		return b
	}
	// 读一个非负整数
	r := func() (x int) {
		b := rc()
		for ; '0' > b || b > '9'; b = rc() {
			// 某些多组数据的题目，不告诉有多少组数据，那么需要额外判断是否读到了 EOF
			if b == eof {
				return
			}
		}
		for ; '0' <= b && b <= '9'; b = rc() {
			x = x*10 + int(b&15)
		}
		return
	}
	n = r()
	a := make([]int, n)
	m := map[int]int{}
	for i := 0; i < n; i++ {
		a[i] = r()
		m[a[i]] = i
	}
	count := -1
	idx := 0
	for idx < n {
		right := m[a[idx]]
		for idx < right {
			idx += 1
			right = max(right, m[a[idx]])
		}
		count += 1
		idx += 1
	}
	ans := 1
	for i := 0; i < count; i++ {
		ans = ans * 2 % 998244353
	}
	fmt.Fprintf(out, "%d", ans)
}
