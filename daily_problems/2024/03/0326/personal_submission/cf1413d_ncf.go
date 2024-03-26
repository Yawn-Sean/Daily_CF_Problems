package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"io"
	"os"
)

func main() { CF1413D(os.Stdin, os.Stdout) }

func CF1413D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	arr := make([]int, 2*n)
	hp := NewIntMinHeap()
	var t string
	flag := false
	for i := 0; i < 2*n; i++ {
		fmt.Fscan(in, &t)
		if t == "+" {
			heap.Push(hp, -i)
		} else {
			fmt.Fscan(in, &arr[i])
			if hp.Len() == 0 {
				flag = true
				// 不读取完不知道有没有问题，还是continue吧
				continue
			}
			idx := -heap.Pop(hp).(int)
			arr[idx] = arr[i]
			arr[i] = -arr[i]
		}
	}
	if flag {
		fmt.Fprintf(out, "NO")
	} else {
		for i := 0; i < 2*n; i++ {
			if arr[i] > 0 {
				heap.Push(hp, arr[i])
			} else {
				mn := heap.Pop(hp).(int)
				if mn != -arr[i] {
					flag = true
					break
				}
			}
		}
		if flag {
			fmt.Fprintf(out, "NO")
		} else {
			fmt.Fprintf(out, "YES\n")
			for i := 0; i < 2*n; i++ {
				if arr[i] > 0 {
					fmt.Fprintf(out, "%d ", arr[i])
				}
			}
		}
	}
}

// 定义一个实现了 heap.Interface 的结构体
type IntMinHeap struct {
	items []int
}

// 实现 Len() 方法，返回堆中元素数量
func (h IntMinHeap) Len() int { return len(h.items) }

// 实现 Less() 方法，对于两个索引 i, j 返回 true 如果 items[i] < items[j]
func (h IntMinHeap) Less(i, j int) bool { return h.items[i] < h.items[j] }

// 实现 Swap() 方法，交换索引 i 和 j 处的元素
func (h IntMinHeap) Swap(i, j int) { h.items[i], h.items[j] = h.items[j], h.items[i] }

// 必须提供一个指针接收者的方法，以便修改底层数组
func (h *IntMinHeap) Push(x interface{}) {
	h.items = append(h.items, x.(int))
}

// Pop() 方法，删除并返回堆顶元素
func (h *IntMinHeap) Pop() interface{} {
	old := h.items
	n := len(old)
	x := old[n-1]
	h.items = old[0 : n-1]
	return x
}

// 初始化堆
func NewIntMinHeap() *IntMinHeap {
	h := &IntMinHeap{items: []int{}}
	heap.Init(h)
	return h
}
