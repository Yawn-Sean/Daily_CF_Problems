package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, s int
	fmt.Fscan(in, &n, &s)
	type pair struct{ diff, cnt int }
	s1 := make([]pair, 0)
	s2 := make([]pair, 0)
	t1, t2 := 0, 0
	sum := 0
	for i := 0; i < n; i++ {
		var c, a, b int
		fmt.Fscan(in, &c, &a, &b)
		if a > b {
			s1 = append(s1, pair{a - b, c})
			sum += c * a
			t1 += c
		} else {
			s2 = append(s2, pair{b - a, c})
			sum += c * b
			t2 += c
		}
	}
	sort.Slice(s1, func(i, j int) bool { return s1[i].diff < s1[j].diff })
	sort.Slice(s2, func(i, j int) bool { return s2[i].diff < s2[j].diff })
	t1 %= s
	t2 %= s
	if t1+t2 > s {
		fmt.Fprintln(out, sum)
		return
	}
	c1, c2 := 0, 0
	for i := 0; i < len(s1); i++ {
		tmp := min(s1[i].cnt, t1)
		c1 += tmp * s1[i].diff
		t1 -= tmp
		if t1 == 0 {
			break
		}
	}
	for i := 0; i < len(s2); i++ {
		tmp := min(s2[i].cnt, t2)
		c2 += tmp * s2[i].diff
		t2 -= tmp
		if t2 == 0 {
			break
		}
	}
	fmt.Fprintln(out, sum-min(c1, c2))
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
