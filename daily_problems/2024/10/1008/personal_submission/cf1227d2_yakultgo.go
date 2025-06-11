package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type FenwickTree struct {
	tr []int
}

func NewFenwickTree(n int) *FenwickTree {
	return &FenwickTree{tr: make([]int, n+10)}
}
func lowbit(x int) int {
	return x & -x
}
func (ft *FenwickTree) add(x, delta int) {
	for x < len(ft.tr) {
		ft.tr[x] += delta
		x += lowbit(x)
	}
}

func (ft *FenwickTree) query(x int) int {
	var res int
	for x > 0 {
		res += ft.tr[x]
		x -= lowbit(x)
	}
	return res
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, q int
	fmt.Fscan(in, &n)
	type pair struct{ val, idx int }
	a := make([]pair, n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i].val)
		a[i].idx = i
		arr[i] = a[i].val
	}
	sort.Slice(a, func(i, j int) bool {
		if a[i].val == a[j].val {
			return a[i].idx < a[j].idx
		}
		return a[i].val > a[j].val
	})
	bit := NewFenwickTree(n)
	fmt.Fscan(in, &q)
	type tuple struct{ k, pos, idx int }
	query := make([]tuple, q)
	for i := 0; i < q; i++ {
		fmt.Fscan(in, &query[i].k, &query[i].pos)
		query[i].idx = i
	}
	sort.Slice(query, func(i, j int) bool {
		return query[i].k < query[j].k
	})
	ans := make([]int, q)
	for i, j := 0, 0; i < q; i++ {
		for j < n && j < query[i].k {
			bit.add(a[j].idx+1, 1)
			j++
		}
		left, right := 1, n+1
		for left < right {
			mid := (left + right) >> 1
			if bit.query(mid) >= query[i].pos {
				right = mid
			} else {
				left = mid + 1
			}
		}
		ans[query[i].idx] = arr[left-1]
	}
	for i := 0; i < q; i++ {
		fmt.Fprintln(out, ans[i])
	}
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
