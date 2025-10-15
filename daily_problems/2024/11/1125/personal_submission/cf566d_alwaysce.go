package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

type UnionFind struct {
	Fa     []int
	Groups int // 连通分量个数
}

func NewUnionFind(n int) UnionFind {
	fa := make([]int, n) // n+1
	for i := range fa {
		fa[i] = i
	}
	return UnionFind{fa, n}
}

// 非递归版本
func (u UnionFind) Find(x int) int {
	root := x
	for u.Fa[root] != root {
		root = u.Fa[root]
	}
	for u.Fa[x] != root {
		u.Fa[x], x = root, u.Fa[x]
	}
	return root
}

// newRoot = -1 表示未发生合并
func (u *UnionFind) Merge(from, to int) (newRoot int) {
	x, y := u.Find(from), u.Find(to)
	if x == y {
		return -1
	}
	u.Fa[x] = y
	u.Groups--
	return y
}

func (u UnionFind) Same(x, y int) bool {
	return u.Find(x) == u.Find(y)
}

func cf566D(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	/*
		并查集 fa[u]为u能够一次走到的最右侧端点
		2操作实际上不会执行很多次合并
	*/

	var n, q int
	fmt.Fscan(in, &n, &q)

	d1, d2 := NewUnionFind(n), NewUnionFind(n)
	for ; q > 0; q-- {
		var tp, u, v int
		fmt.Fscan(in, &tp, &u, &v)
		u--
		v--

		switch tp {
		case 1:
			d1.Merge(u, v)
		case 2:
			for d2.Find(u) < v {
				fu := d2.Find(u)
				d1.Merge(fu, fu+1)
				d2.Merge(fu, fu+1)
			}
		case 3:
			if d1.Same(u, v) {
				fmt.Fprintln(out, "YES")
			} else {
				fmt.Fprintln(out, "NO")
			}
		}
	}
}

// func main() {
// 	cf566D(bufio.NewReader(os.Stdin), os.Stdout)
// }
