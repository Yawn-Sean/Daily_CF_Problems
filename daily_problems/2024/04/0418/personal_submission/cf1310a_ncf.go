package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF1310A(os.Stdin, os.Stdout) }

func CF1310A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, 2)
		fmt.Fscan(in, &a[i][0])
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i][1])
	}
	sort.Slice(a, func(i, j int) bool {
		if a[i][0] == a[j][0] {
			return a[i][1] > a[j][1]
		}
		return a[i][0] < a[j][0]
	})
	ans := 0
	hp := NewIntMaxHeap1310a()
	cur := 0
	val := 0
	for i := 0; i < n; {
		if val < a[i][0] {
			if hp.Len() > 0 {
				p := heap.Pop(hp).(int)
				cur -= p
				ans += cur
				val += 1
				continue
			}
			val = a[i][0] + 1
		} else {
			if a[i][0] < val {
				ans += a[i][1]
			}
			cur += a[i][1]
			heap.Push(hp, a[i][1])
		}
		i += 1
	}
	for hp.Len() > 0 {
		p := heap.Pop(hp).(int)
		cur -= p
		ans += cur
	}
	fmt.Fprintf(out, "%d\n", ans)
}

// IntMaxHeap1310a 定义一个实现了 heap.Interface 的结构体
type IntMaxHeap1310a struct {
	items []int
}

// Len 实现 Len() 方法，返回堆中元素数量
func (h *IntMaxHeap1310a) Len() int { return len(h.items) }

// Less 实现 Less() 方法，对于两个索引 i, j 返回 true 如果 items[i] < items[j]
func (h *IntMaxHeap1310a) Less(i, j int) bool { return h.items[i] > h.items[j] }

// Swap 实现 Swap() 方法，交换索引 i 和 j 处的元素
func (h *IntMaxHeap1310a) Swap(i, j int) { h.items[i], h.items[j] = h.items[j], h.items[i] }

// Push 必须提供一个指针接收者的方法，以便修改底层数组
func (h *IntMaxHeap1310a) Push(x interface{}) {
	h.items = append(h.items, x.(int))
}

// Pop 方法，删除并返回堆顶元素
func (h *IntMaxHeap1310a) Pop() interface{} {
	old := h.items
	n := len(old)
	x := old[n-1]
	h.items = old[0 : n-1]
	return x
}

// NewIntMaxHeap1310a 初始化堆
func NewIntMaxHeap1310a() *IntMaxHeap1310a {
	h := &IntMaxHeap1310a{items: []int{}}
	heap.Init(h)
	return h
}
