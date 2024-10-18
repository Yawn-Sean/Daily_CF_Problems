package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF597C(os.Stdin, os.Stdout) }

func CF597C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, k int
	fmt.Fscan(in, &n, &k)
	a := make([]int, n)
	f := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		f[i] = 1
	}
	for i := 0; i < k; i++ { // 序列长度为2遍历到序列长度为k + 1
		tree := make(fenwick, n+1)
		for j := 0; j < n; j++ {
			tree.add(a[j], f[j])
			f[j] = tree.pre(a[j] - 1)
		}
	}
	ans := 0
	for i := 0; i < n; i++ {
		ans += f[i]
	}
	fmt.Fprintf(out, "%d\n", ans)
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
