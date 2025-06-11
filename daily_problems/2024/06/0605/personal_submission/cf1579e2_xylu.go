package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"slices"
)

func main() {
	solveE(os.Stdin, os.Stdout)
}

func solveE(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var T, n int
	for fmt.Fscan(in, &T); T > 0; T-- {
		fmt.Fscan(in, &n)
		a := make([]int, n)
		for i := range a {
			fmt.Fscan(in, &a[i])
		}
		distinct := append([]int{}, a...)
		slices.Sort(distinct)
		distinct = slices.Compact(distinct)
		mp := make(map[int]int)
		for i, v := range distinct {
			mp[v] = i
		}
		tr := newFenwick(len(distinct))
		cnt := make([]int, len(distinct))
		ans := 0
		for i, v := range a {
			t := tr.sum(mp[v] - 1) // 比 v 小的数的个数
			ans += min(t, i-t-cnt[mp[v]])
			tr.add(mp[v])
			cnt[mp[v]]++
		}
		fmt.Fprintln(out, ans)
	}
}

type fenwick struct {
	n    int
	data []int
}

func newFenwick(n int) *fenwick {
	return &fenwick{n: n, data: make([]int, n+1)}
}

func (f *fenwick) add(i int) {
	for i++; i <= f.n; i += i & -i {
		f.data[i]++
	}
}

func (f *fenwick) sum(i int) (s int) {
	for i++; i > 0; i -= i & -i {
		s += f.data[i]
	}
	return
}
