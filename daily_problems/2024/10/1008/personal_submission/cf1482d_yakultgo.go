package main

import (
	"bufio"
	"fmt"
	"os"
)

type Dsu struct {
	Fa     []int
	Size   []int
	Groups int
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}
	ans := make([]int, 0)
	nex := make([]int, n)
	for i := 0; i < n; i++ {
		nex[i] = (i + 1) % n
	}
	fa := make([]int, n)
	for i := range fa {
		fa[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if fa[x] != x {
			fa[x] = find(fa[x])
		}
		return fa[x]
	}
	union := func(x, y int) {
		x = find(x)
		y = find(y)
		if x == y {
			return
		}
		fa[x] = y
	}
	cur := 0
	for {
		fc := find(cur)
		if gcd(a[fc], a[nex[fc]]) > 1 {
			if find(fc) == find(nex[fc]) {
				break
			}
			union(fc, nex[fc])
			cur = nex[fc]
		} else {
			if len(ans) == n {
				break
			}
			ans = append(ans, nex[fc]+1)
			nex[fc] = nex[nex[fc]]
			cur = nex[fc]
		}
	}
	fmt.Fprint(out, len(ans), " ")
	for _, v := range ans {
		fmt.Fprint(out, v, " ")
	}
	fmt.Fprintln(out)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	fmt.Fscan(in, &T)
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
