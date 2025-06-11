package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, q int
	fmt.Fscan(in, &n, &q)
	a := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}
	last := make(map[int]int)
	for i, x := range a {
		last[x] = i
	}
	type pair struct{ l, r int }
	seg := make([]pair, 0)
	pre := 0
	right := 0
	for i := range a {
		right = max(right, last[a[i]])
		if i == right {
			seg = append(seg, pair{pre, right})
			pre = right + 1
		}
	}
	ans := 0
	for i := range seg {
		cnt := 0
		mapCnt := make(map[int]int)
		for j := seg[i].l; j <= seg[i].r; j++ {
			mapCnt[a[j]]++
			cnt = max(cnt, mapCnt[a[j]])
		}
		ans += seg[i].r - seg[i].l + 1 - cnt
	}
	fmt.Fprintln(out, ans)
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
