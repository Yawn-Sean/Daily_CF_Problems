package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF1249D2(os.Stdin, os.Stdout) }

func CF1249D2(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, k int
	fmt.Fscan(in, &n, &k)

	a := make([]segment1249d2, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i].l, &a[i].r)
		a[i].num = i + 1
	}
	sort.Slice(a, func(i, j int) bool { // 根据左端点从小到大排序
		return a[i].l < a[j].l
	})
	mx := int(2e5 + 1)
	diff := make([]int, mx)
	cur := 0
	idx := 0
	h := hp1249d2{} // 堆的作用是找到当前最右端点的线段，如果当前点被超过k个线段覆盖，那么最右端点所在的线段必然是最优删除选择之一
	var ans []int
	for i := 1; i < mx; i++ {
		for idx < n && i >= a[idx].l { // 如果当前点被某些线段覆盖，将线段加入堆，维护当前被覆盖数量cur
			heap.Push(&h, a[idx])
			diff[a[idx].r] -= 1
			idx += 1
			cur += 1
		}
		cur += diff[i-1]
		for cur > k {
			seg := heap.Pop(&h).(segment1249d2)
			diff[seg.r] += 1
			ans = append(ans, seg.num)
			cur -= 1
		}
	}

	fmt.Fprintf(out, "%d\n", len(ans))
	for _, e := range ans {
		fmt.Fprintf(out, "%d ", e)
	}
}

type segment1249d2 struct{ l, r, num int }

type hp1249d2 []segment1249d2

func (h hp1249d2) Len() int           { return len(h) }
func (h hp1249d2) Less(i, j int) bool { return h[i].r > h[j].r }
func (h hp1249d2) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp1249d2) Push(x any)        { *h = append(*h, x.(segment1249d2)) }
func (h *hp1249d2) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
