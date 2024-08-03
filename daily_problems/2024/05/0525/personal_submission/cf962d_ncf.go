package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF962D(os.Stdin, os.Stdout) }

func CF962D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	g := map[int][]int{}
	hp := NewIntMinHeap962d()
	type tuple struct {
		val, idx int
	}
	var ans []tuple
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		if len(g[a[i]]) == 0 {
			heap.Push(hp, a[i])
		}
		g[a[i]] = append(g[a[i]], i)
	}
	for hp.Len() > 0 {
		key := heap.Pop(hp).(int)
		cur := g[key]
		sort.Ints(cur)
		m := len(cur)
		j := 1
		nextKey := key << 1
		for j < m {
			if len(g[nextKey]) == 0 {
				heap.Push(hp, nextKey)
			}
			g[nextKey] = append(g[nextKey], cur[j])
			j += 2
		}
		if j == m {
			ans = append(ans, tuple{key, cur[m-1]})
		}
	}

	sort.Slice(ans, func(i, j int) bool {
		return ans[i].idx < ans[j].idx
	})

	fmt.Fprintf(out, "%d\n", len(ans))
	for _, e := range ans {
		fmt.Fprintf(out, "%d ", e.val)
	}
}

// 定义一个实现了 heap.Interface 的结构体
type IntMinHeap962d struct {
	items []int
}

// 实现 Len() 方法，返回堆中元素数量
func (h IntMinHeap962d) Len() int { return len(h.items) }

// 实现 Less() 方法，对于两个索引 i, j 返回 true 如果 items[i] < items[j]
func (h IntMinHeap962d) Less(i, j int) bool { return h.items[i] < h.items[j] }

// 实现 Swap() 方法，交换索引 i 和 j 处的元素
func (h IntMinHeap962d) Swap(i, j int) { h.items[i], h.items[j] = h.items[j], h.items[i] }

// 必须提供一个指针接收者的方法，以便修改底层数组
func (h *IntMinHeap962d) Push(x interface{}) {
	h.items = append(h.items, x.(int))
}

// Pop() 方法，删除并返回堆顶元素
func (h *IntMinHeap962d) Pop() interface{} {
	old := h.items
	n := len(old)
	x := old[n-1]
	h.items = old[0 : n-1]
	return x
}

// 初始化堆
func NewIntMinHeap962d() *IntMinHeap962d {
	h := &IntMinHeap962d{items: []int{}}
	heap.Init(h)
	return h
}
