package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"io"
	"os"
)

func main() { CF747D(os.Stdin, os.Stdout) }

func CF747D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, k int
	fmt.Fscan(in, &n, &k)
	t := make([]int, n)
	hp := NewIntMinHeap747d()
	last := -1
	r := k
	ans := 0
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &t[i])
		if t[i] < 0 {
			if last != -1 {
				heap.Push(hp, i-last)
			}
			last = i
			r -= 1
			ans += 2
		}
	}
	if r < 0 {
		fmt.Fprintf(out, "-1")
		return
	}
	for hp.Len() > 0 {
		p := heap.Pop(hp).(int)
		r -= p - 1
		if r >= 0 {
			ans -= 2
		} else {
			r += p - 1
			break
		}
	}
	if last != -1 && r >= n-last-1 {
		ans -= 1
	}
	fmt.Fprintf(out, "%d", ans)
}

// 定义一个实现了 heap.Interface 的结构体
type IntMinHeap747d struct {
	items []int
}

// 实现 Len() 方法，返回堆中元素数量
func (h IntMinHeap747d) Len() int { return len(h.items) }

// 实现 Less() 方法，对于两个索引 i, j 返回 true 如果 items[i] < items[j]
func (h IntMinHeap747d) Less(i, j int) bool { return h.items[i] < h.items[j] }

// 实现 Swap() 方法，交换索引 i 和 j 处的元素
func (h IntMinHeap747d) Swap(i, j int) { h.items[i], h.items[j] = h.items[j], h.items[i] }

// 必须提供一个指针接收者的方法，以便修改底层数组
func (h *IntMinHeap747d) Push(x interface{}) {
	h.items = append(h.items, x.(int))
}

// Pop() 方法，删除并返回堆顶元素
func (h *IntMinHeap747d) Pop() interface{} {
	old := h.items
	n := len(old)
	x := old[n-1]
	h.items = old[0 : n-1]
	return x
}

// 初始化堆
func NewIntMinHeap747d() *IntMinHeap747d {
	h := &IntMinHeap747d{items: []int{}}
	heap.Init(h)
	return h
}
