package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"sort"
)

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, d int
	Fscan(in, &n, &d)
	fa, sz := make([]int, n), make([]int, n)
	for i := range fa {
		fa[i], sz[i] = i, 1
	}
	var find func(int) int
	find = func(x int) int {
		if fa[x] != x {
			fa[x] = find(fa[x])
		}
		return fa[x]
	}
	cnt := 1
	szs := make([]int, 0, n)
	for i := 0; i < d; i++ {
		var x, y int
		Fscan(in, &x, &y)
		x, y = find(x-1), find(y-1)
		if x != y {
			if sz[x] < sz[y] {
				x, y = y, x
			}
			fa[y], sz[x] = x, sz[x]+sz[y]
		} else {
			cnt++
		}

		szs = szs[:0]
		for i := range fa {
			if fa[i] == i {
				szs = append(szs, sz[i])
			}
		}
		ans := 0
		sort.Slice(szs, func(i, j int) bool { return szs[i] > szs[j] })
		for i, s := range szs {
			if i >= cnt {
				break
			}
			ans += s
		}
		Fprintln(out, ans-1)
	}
}

func main() {
	solveD(os.Stdin, os.Stdout)
}
