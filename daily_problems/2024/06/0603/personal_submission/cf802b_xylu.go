package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"io"
	"os"
)

type pair struct{ x, y int }

func solveB(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, k int
	fmt.Fscan(in, &n, &k)
	a := make([]int, n)
	// next[i] 记录 a[i] 的下一个出现位置
	next := make([]int, n)
	preidx := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
		a[i]--
		if preidx[a[i]] > 0 {
			next[preidx[a[i]]-1] = i
		}
		preidx[a[i]] = i + 1
	}
	for i := range preidx {
		if preidx[i] > 0 {
			next[preidx[i]-1] = n
		}
	}
	vis := make([]bool, n)
	ans, sz := 0, 0
	h := hp{}
	for i := 0; i < n; i++ {
		if !vis[a[i]] {
			if sz == k {
				// 删除当前下一次最晚出现的元素
				vis[heap.Pop(&h).(pair).y] = false
				sz--
			}
			ans, sz = ans+1, sz+1
			vis[a[i]] = true
		}
		heap.Push(&h, pair{next[i], a[i]})
	}
	fmt.Fprintln(out, ans)
}

func main() {
	solveB(os.Stdin, os.Stdout)
}

type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].x > h[j].x }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(x any)        { *h = append(*h, x.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
