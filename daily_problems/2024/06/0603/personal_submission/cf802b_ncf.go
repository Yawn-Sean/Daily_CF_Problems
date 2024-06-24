package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"io"
	"os"
)

func main() { CF802B(os.Stdin, os.Stdout) }

func CF802B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, k int
	fmt.Fscan(in, &n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		a[i] -= 1
	}
	nxPos := make([]int, n)
	pos := make([]int, n)
	for i := n - 1; i > -1; i-- {
		cur := pos[a[i]]
		if cur == 0 {
			cur = n
		}
		nxPos[i] = cur
		pos[a[i]] = i
	}

	// vis用于维护书本还在不在，true代表在
	vis := make([]bool, n)
	// 手动维护size，旧元素不好删就不删了
	ans, size := 0, 0
	h := hp{}
	for i := 0; i < n; i++ {
		if !vis[a[i]] {
			if size == k {
				vis[heap.Pop(&h).(pair).y] = false
				size -= 1
			}
			ans += 1
			size += 1
			vis[a[i]] = true
		}
		heap.Push(&h, pair{nxPos[i], a[i]})
	}
	fmt.Fprintf(out, "%d", ans)
}

type pair struct{ x, y int }

type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].x > h[j].x }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(x any)        { *h = append(*h, x.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
