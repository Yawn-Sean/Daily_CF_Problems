package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF1468J(os.Stdin, os.Stdout) }

func CF1468J(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, m, k int
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &m, &k)
		us := make([]int, m)
		vs := make([]int, m)
		ws := make([]int, m)
		ans := int(1e9)

		for i := 0; i < m; i++ {
			fmt.Fscan(in, &us[i], &vs[i], &ws[i])
			us[i], vs[i] = us[i]-1, vs[i]-1
			ans = min(ans, abs(ws[i]-k))
		}

		ds := makeSet(n)
		cur := 0
		a := make([]int, m)
		for i := 0; i < m; i++ {
			a[i] = i
		}
		sort.Slice(a, func(i, j int) bool {
			return ws[a[i]] < ws[a[j]]
		})
		for i := 0; i < m; i++ {
			idx := a[i]
			if find(us[idx], ds) != find(vs[idx], ds) { // 从最小边开始生成最小生成树
				union(us[idx], vs[idx], ds)
				cur += max(0, ws[idx]-k) // 如果有多条边超过k，累加
			}
		}

		if cur > 0 {
			ans = cur
		}
		fmt.Fprintf(out, "%d\n", ans)
	}
}

func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}

type DisjointSet struct {
	parent []int // 父节点数组
	rank   []int // 节点秩数组
}

func makeSet(n int) *DisjointSet {
	ds := &DisjointSet{
		parent: make([]int, n),
		rank:   make([]int, n),
	}
	for i := 0; i < n; i++ {
		ds.parent[i] = i
		ds.rank[i] = 1 // 初始化每个集合的秩为1
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
		} else if ds.rank[fa] < ds.rank[fb] {
			ds.parent[fa] = fb
		} else { // 当两者秩相等时，将秩较小的集合赋给较大的集合，并将秩+1
			ds.parent[fb] = fa
			ds.rank[fa]++
		}
	}
}
