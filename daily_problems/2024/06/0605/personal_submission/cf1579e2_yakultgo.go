package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
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
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	mp := make(map[int]struct{})
	for i := range a {
		fmt.Fscan(in, &a[i])
		mp[a[i]] = struct{}{}
	}
	b := make([]int, 0)
	for k := range mp {
		b = append(b, k)
	}
	slices.Sort(b)
	m := len(b)
	fr := NewFenwickTree(m)
	ans := 0
	for _, x := range a {
		pos := sort.Search(m, func(j int) bool {
			return b[j] > x
		})
		head := fr.query(m) - fr.query(pos)
		tail := fr.query(pos - 1)
		ans += min(head, tail)
		fr.add(pos, 1)
	}
	fmt.Fprintln(out, ans)
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
