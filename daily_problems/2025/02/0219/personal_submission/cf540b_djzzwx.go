# https://codeforces.com/contest/540/submission/306851135

package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

const inf int = 0x3f3f3f3f
const mod int = 1e9 + 7

func slove(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, k, p, x, y int
	Fscan(in, &n, &k, &p, &x, &y)
	var s, v, opmi int
	for i := 0; i < k; i++ {
		Fscan(in, &v)
		s += v
		if v < y {
			opmi++
		}
	}
	h := (n+1)/2 - 1
	tmp := s + h - opmi
	if opmi >= h+1 || s > x || tmp+(n-k-(h-opmi))*y > x {
		Fprintln(out, -1)
		return
	}
	n -= k
	ans := make([]any, 0, n)
	for i := 0; i < h-opmi && n > 0; i++ {
		ans = append(ans, 1)
		n--
		s++
	}
	for ; n > 0; n-- {
		ans = append(ans, y)
		s += y
	}
	if s > x {
		Fprintln(out, -1)
		return
	}
	Fprintln(out, ans...)
}

func main() { slove(os.Stdin, os.Stdout) }

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

//func max(a, b int) int {
//	if a > b {
//		return a
//	}
//	return b
//}
//
//func min(a, b int) int {
//	if a < b {
//		return a
//	}
//	return b
//}
