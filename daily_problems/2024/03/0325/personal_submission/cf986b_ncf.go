package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF986B(os.Stdin, os.Stdout) }

func CF986B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	count := 0
	tree := make(fenwick986b, n+1)
	for i := n - 1; i > -1; i-- {
		tree.add(a[i], 1)
		count += tree.pre(a[i] - 1)
	}
	if n%2 == count%2 {
		fmt.Fprintf(out, "Petr")
	} else {
		fmt.Fprintf(out, "Um_nik")
	}
}

type fenwick986b []int

// 把下标为 i 的元素增加 val
func (f fenwick986b) add(i, val int) {
	for ; i < len(f); i += i & -i {
		f[i] += val
	}
}

// 返回下标在 [1,i] 的元素之和
func (f fenwick986b) pre(i int) (res int) {
	for ; i > 0; i &= i - 1 {
		res += f[i]
	}
	return
}
