package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF1185C2(os.Stdin, os.Stdout) }

func CF1185C2(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m int
	fmt.Fscan(in, &n, &m)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &arr[i])
	}
	sarr := make([]int, len(arr))
	copy(sarr, arr)
	sort.Ints(sarr)
	mp := map[int]int{}
	index := 1
	for _, e := range sarr {
		_, exist := mp[e]
		if !exist {
			mp[e] = index
		}
		index++
	}
	mp2 := map[int]int{}
	tree1 := make(fenwick, index+1)
	tree2 := make(fenwick, index+1)
	for i := 0; i < n; i++ {
		l, r := 1, index-1
		for l <= r {
			mid := (l + r) / 2
			if tree1.pre(mid) > m-arr[i] {
				r = mid - 1
			} else {
				l = mid + 1
			}
		}
		fmt.Fprintf(out, "%d ", i-tree2.pre(l-1))
		idx := mp[arr[i]] + mp2[arr[i]]
		tree1.add(idx, arr[i])
		tree2.add(idx, 1)
		mp2[arr[i]]++
	}
}

type fenwick []int

// 把下标为 i 的元素增加 val
func (f fenwick) add(i, val int) {
	for ; i < len(f); i += i & -i {
		f[i] += val
	}
}

// 返回下标在 [1,i] 的元素之和
func (f fenwick) pre(i int) (res int) {
	for ; i > 0; i &= i - 1 {
		res += f[i]
	}
	return
}
