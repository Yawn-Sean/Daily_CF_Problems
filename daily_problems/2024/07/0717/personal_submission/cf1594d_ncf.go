package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1594D(os.Stdin, os.Stdout) }

func CF1594D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, m, x, y int
	var c string
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &m)
		ds := makeSet(n*2 + 1)
		for i := n + 1; i <= 2*n; i++ { // [1,n] 表示 i 是老实人, [n+1,2n] 表示 i 是骗子，考虑每个集合的代表是老实人/骗子的情况下，哪种老实人数量更多，累加起来就是答案
			ds.size[i] = 0
		}
		for i := 0; i < m; i++ {
			fmt.Fscan(in, &x, &y, &c)
			if c[0] == 'c' {
				union(x, y, ds)
				union(x+n, y+n, ds)
			} else { // 如果x 认为 y 是骗子，那么不论x是诚实的还是骗子，xy都是对立的
				union(x, y+n, ds)
				union(x+n, y, ds)
			}
		}
		ans := 0
		for i := 1; i <= n; i++ {
			if find(i, ds) == find(i+n, ds) {
				ans = -1
				break
			}
			ans += max(ds.size[find(i, ds)], ds.size[find(i+n, ds)])
			ds.size[find(i, ds)], ds.size[find(i+n, ds)] = 0, 0
		}
		fmt.Fprintf(out, "%d\n", ans)
	}
}

type DisjointSet struct {
	parent []int // 父节点数组
	rank   []int // 节点秩数组
	size   []int
}

func makeSet(n int) *DisjointSet {
	ds := &DisjointSet{
		parent: make([]int, n),
		rank:   make([]int, n),
		size:   make([]int, n),
	}
	for i := 0; i < n; i++ {
		ds.parent[i] = i
		ds.rank[i] = 1 // 初始化每个集合的秩为1
		ds.size[i] = 1
	}
	return ds
}

// 将递归的find()函数改为迭代形式
func find(x int, ds *DisjointSet) int {
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

func union(a, b int, ds *DisjointSet) {
	fa, fb := find(a, ds), find(b, ds)
	if fa != fb {
		if ds.rank[fa] > ds.rank[fb] {
			ds.parent[fb] = fa
			ds.size[fa] += ds.size[fb]
		} else if ds.rank[fa] < ds.rank[fb] {
			ds.parent[fa] = fb
			ds.size[fb] += ds.size[fa]
		} else { // 当两者秩相等时，将秩较小的集合赋给较大的集合，并将秩+1
			ds.parent[fb] = fa
			ds.size[fa] += ds.size[fb]
			ds.rank[fa]++
		}
	}
}
