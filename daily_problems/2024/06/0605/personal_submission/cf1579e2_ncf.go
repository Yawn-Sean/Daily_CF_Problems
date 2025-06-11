package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF1579E2(os.Stdin, os.Stdout) }

func CF1579E2(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n int
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n)
		m := map[int]bool{}
		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
			m[a[i]] = true
		}
		var li []int
		for k, _ := range m {
			li = append(li, k)
		}
		sort.Ints(li)
		kv := map[int]int{}
		for i, v := range li {
			kv[v] = i + 1
		}
		mx := len(li)
		tree := make(fenwick1579e2, mx+1)
		ans := 0
		for i := 0; i < n; i++ {
			cur := kv[a[i]]
			v1 := tree.pre(cur - 1)
			v2 := tree.pre(cur)
			ans += min(i-v2, v1)
			tree.add(cur, 1)
		}
		fmt.Fprintf(out, "%d\n", ans)
	}
}

type fenwick1579e2 []int

// 把下标为 i 的元素增加 val
func (f fenwick1579e2) add(i, val int) {
	for ; i < len(f); i += i & -i {
		f[i] += val
	}
}

// 返回下标在 [1,i] 的元素之和
func (f fenwick1579e2) pre(i int) (res int) {
	for ; i > 0; i &= i - 1 {
		res += f[i]
	}
	return
}
