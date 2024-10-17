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

func NewFenwickTree(n int) *FenwickTree {
	return &FenwickTree{tr: make([]int, n+10)}
}
func solve(in *bufio.Reader, out *bufio.Writer) {
	var q int
	fmt.Fscan(in, &q)
	type query struct{ op, t, idx int }
	mp := make(map[int][]query)
	var op, t, val int
	ans := make([]int, q)
	for i := range ans {
		ans[i] = -1
	}
	for i := 0; i < q; i++ {
		fmt.Fscan(in, &op, &t, &val)
		mp[val] = append(mp[val], query{op, t, i})
	}
	for _, v := range mp {
		time := make([]int, 0)
		for _, val := range v {
			time = append(time, val.t)
		}
		sort.Slice(time, func(i, j int) bool { return time[i] < time[j] })
		bit := NewFenwickTree(len(time))
		for _, val := range v {
			idx := sort.Search(len(time), func(i int) bool { return time[i] >= val.t })
			if val.op == 1 {
				bit.add(idx+1, 1)
			} else if val.op == 2 {
				bit.add(idx+1, -1)
			} else {
				ans[val.idx] = bit.query(idx + 1)
			}
		}
	}
	for _, v := range ans {
		if v != -1 {
			fmt.Fprintln(out, v)
		}
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
