package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF830B(os.Stdin, os.Stdout) }

func CF830B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	m := map[int][]int{}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		m[a[i]] = append(m[a[i]], i)
	}
	var b []int
	for k := range m {
		b = append(b, k)
	}
	sort.Ints(b)
	idx := 0
	tree := make(fenwick830b, n+2)
	for i := 0; i < n; i++ {
		tree.add(i, 1)
	}
	last := -1
	ans := 0
	count := n
	for i := 0; i < len(b); i++ {
		c := m[b[idx]]
		if c[0] > last {
			r := c[len(c)-1]
			ans += tree.pre(r) - tree.pre(last)
			last = r
		} else {
			j := 0
			for j < len(c) && c[j] < last {
				j++
			}
			if j == len(c) || c[j] > last {
				j -= 1
			}
			ans += tree.pre(n) - tree.pre(last) + tree.pre(c[j])
			last = c[j]
		}
		count -= len(c)

		for _, e := range c {
			tree.add(e, -1)
		}
		idx++
	}
	fmt.Fprintf(out, "%d\n", ans)
}

type fenwick830b []int

// 把下标为 i 的元素增加 val
func (f fenwick830b) add(i, val int) {
	i += 1
	for ; i < len(f); i += i & -i {
		f[i] += val
	}
}

// 返回下标在 [1,i] 的元素之和
func (f fenwick830b) pre(i int) (res int) {
	i += 1
	for ; i > 0; i &= i - 1 {
		res += f[i]
	}
	return
}
