package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF725D(os.Stdin, os.Stdout) }

func CF725D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, t, w int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &t, &w)
	n -= 1
	a := make([]pair725d, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i].x, &a[i].y)
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i].x > a[j].x
	})
	rank, idx := 1, 0
	h := hp725d{}
	for ; idx < n && a[idx].x > t; idx++ {
		heap.Push(&h, a[idx])
		rank += 1
	}
	ans := rank
	for t >= 0 {
		ans = min(ans, rank)
		if len(h) == 0 {
			break
		}
		peek := h[0]
		nt := t - (peek.y - peek.x + 1)
		for ; idx < n && nt < a[idx].x; idx++ {
			heap.Push(&h, a[idx])
			rank += 1
		}
		pop := heap.Pop(&h).(pair725d)
		t -= pop.y - pop.x + 1
		rank -= 1
	}
	fmt.Fprintf(out, "%d", ans)
}

type pair725d struct{ x, y int }
type hp725d []pair725d

func (h hp725d) Len() int           { return len(h) }
func (h hp725d) Less(i, j int) bool { return h[i].y-h[i].x < h[j].y-h[j].x }
func (h hp725d) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp725d) Push(v any)        { *h = append(*h, v.(pair725d)) }
func (h *hp725d) Pop() (v any)      { a := *h; *h, v = a[:len(a)-1], a[len(a)-1]; return }
