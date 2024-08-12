package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1131F(os.Stdin, os.Stdout) }

func CF1131F(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, x, y int
	fmt.Fscan(in, &n)
	set := makeSet1131f(n)
	for i := 0; i < n-1; i++ {
		fmt.Fscan(in, &x, &y)
		x, y = x-1, y-1
		union1131f(x, y, set)
	}
	fa := find1131f(0, set)
	for set.next[fa] != fa {
		fmt.Fprintf(out, "%d ", fa+1)
		fa = set.next[fa]
	}
	fmt.Fprintf(out, "%d", fa+1)
}

type DisjointSet1131f struct {
	parent []int // 父节点数组
	rank   []int // 节点秩数组
	start  []int
	end    []int
	next   []int
}

func makeSet1131f(n int) *DisjointSet1131f {
	ds := &DisjointSet1131f{
		parent: make([]int, n),
		rank:   make([]int, n),
		start:  make([]int, n),
		end:    make([]int, n),
		next:   make([]int, n),
	}
	for i := 0; i < n; i++ {
		ds.parent[i] = i
		ds.rank[i] = 1 // 初始化每个集合的秩为1
		ds.start[i] = i
		ds.end[i] = i
		ds.next[i] = i
	}
	return ds
}

// 将递归的find()函数改为迭代形式
func find1131f(x int, ds *DisjointSet1131f) int {
	var root int = x
	for root != ds.parent[root] {
		root = ds.parent[root]
	}

	// 路径压缩：将x到root路径上的所有节点直接指向root
	for x != root {
		next := ds.parent[x]
		ds.parent[x] = root
		x = next
	}

	return root
}

func union1131f(a, b int, ds *DisjointSet1131f) {
	fa, fb := find1131f(a, ds), find1131f(b, ds)
	if fa != fb {
		if ds.rank[fa] > ds.rank[fb] {
			ds.parent[fb] = fa
			ds.next[ds.end[fa]] = ds.start[fb]
			ds.end[fa] = ds.end[fb]
		} else if ds.rank[fa] < ds.rank[fb] {
			ds.parent[fa] = fb
			ds.next[ds.end[fb]] = ds.start[fa]
			ds.end[fb] = ds.end[fa]
		} else { // 当两者秩相等时，将秩较小的集合赋给较大的集合，并将秩+1
			ds.parent[fb] = fa
			ds.rank[fa]++
			ds.next[ds.end[fa]] = ds.start[fb]
			ds.end[fa] = ds.end[fb]
		}
	}
}
