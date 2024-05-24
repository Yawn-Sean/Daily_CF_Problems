package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF900C(os.Stdin, os.Stdout) }

func CF900C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	tree := make(fenwick900c, n+1)  // 用于统计某个值域内的元素个数
	tree2 := make(fenwick900c, n+1) // 用于统计前面只有一个数大于自身的元素
	m := map[int]int{}              // 用于记录某个元素本身是否记录
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		cur := tree.pre(a[i])
		if cur == i {
			m[a[i]] = 1
		} else if i-cur == 1 {
			tree2.add(a[i], 1)
		}
		tree.add(a[i], 1)
	}
	ans, mx := n, -1
	for i := 0; i < n; i++ {
		cur := tree2.pre(a[i] - 1)
		v := m[a[i]]
		if cur-v > mx {
			mx = cur - v
			ans = a[i]
		} else if cur-v == mx {
			ans = min(ans, a[i])
		}
		if tree2.pre(a[i])-cur == 1 {
			tree2.add(a[i], -1)
		}
	}
	fmt.Fprintf(out, "%d", ans)
}

type fenwick900c []int

// 把下标为 i 的元素增加 val
func (f fenwick900c) add(i, val int) {
	for ; i < len(f); i += i & -i {
		f[i] += val
	}
}

// 返回下标在 [1,i] 的元素之和
func (f fenwick900c) pre(i int) (res int) {
	for ; i > 0; i &= i - 1 {
		res += f[i]
	}
	return
}
