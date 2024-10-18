package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var a, b, h, w, n int
	fmt.Fscan(in, &a, &b, &h, &w, &n)
	arr := make([]int, n)
	for i := range arr {
		fmt.Fscan(in, &arr[i])
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i] > arr[j] })
	type tuple struct{ u, v, op int }
	type pair struct{ first, second int }
	calc := func(x, y int) int {
		mp := make(map[pair]struct{})
		queue := make([]tuple, 0, n)
		queue = append(queue, tuple{u: x, v: y, op: 0})
		for len(queue) > 0 {
			t := queue[0]
			queue = queue[1:]
			if t.u >= a && t.v >= b {
				return t.op
			}
			if t.op >= n {
				continue
			}
			if t.v < b {
				if _, ok := mp[pair{t.u, t.v * arr[t.op]}]; !ok {
					queue = append(queue, tuple{u: t.u, v: t.v * arr[t.op], op: t.op + 1})
					mp[pair{t.u, t.v * arr[t.op]}] = struct{}{}
				}
			}
			if t.u < a {
				if _, ok := mp[pair{t.u * arr[t.op], t.v}]; !ok {
					queue = append(queue, tuple{u: t.u * arr[t.op], v: t.v, op: t.op + 1})
					mp[pair{t.u * arr[t.op], t.v}] = struct{}{}
				}
			}
		}
		return int(1e5)
	}
	t1 := calc(h, w)
	t2 := calc(w, h)
	ans := min(t1, t2)
	if ans >= 40 {
		ans = -1
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
