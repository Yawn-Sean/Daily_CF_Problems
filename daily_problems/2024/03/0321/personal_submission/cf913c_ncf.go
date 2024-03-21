package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

func main() { CF913C(os.Stdin, os.Stdout) }

func CF913C(_r io.Reader, out io.Writer) {
	type pair struct{ x, y int }
	in := bufio.NewReader(_r)
	var n, l int
	fmt.Fscan(in, &n, &l)
	c := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &c[i])
	}
	var s []pair
	s = append(s, pair{0, c[0]})
	for i := 1; i < n; i++ {
		p := s[len(s)-1]
		v := p.y * (1 << (i - p.x))
		if v > c[i] {
			s = append(s, pair{i, c[i]})
		}
	}
	ans := math.MaxInt
	cAns := 0
	for l > 0 {
		cur := s[len(s)-1]
		curL := 1 << cur.x
		count := l / curL
		l -= count * curL
		cAns += count * cur.y
		if l > 0 {
			ans = min913C(ans, cAns+cur.y)
		}
		s = s[:len(s)-1]
	}
	ans = min913C(ans, cAns)
	fmt.Fprintf(out, "%d ", ans)
}

func min913C(a, b int) int {
	if a < b {
		return a
	}
	return b
}
