package main

import (
	"bufio"
	"fmt"
	"os"
)

type FenwickTree struct {
	Tree []int
}

func (f *FenwickTree) lowbit(i int) int {
	return i & (-i)
}

func (f *FenwickTree) add(i, delta int) {
	for ; i < len(f.Tree); i += f.lowbit(i) {
		f.Tree[i] += delta
	}
}

func (f *FenwickTree) get(i int) int {
	sum := 0
	for ; i > 0; i -= f.lowbit(i) {
		sum += f.Tree[i]
	}
	return sum
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int

	fmt.Fscan(in, &n)
	data := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &data[i])
	}

	// 树状数组
	f := FenwickTree{make([]int, n+1)}

	ans := 0
	for i, v := range data {
		ans += i - f.get(v)
		f.add(data[i], 1)
	}

	if (n*3%2 == 1 && ans%2 == 1) || (n*3%2 == 0 && ans%2 == 0) {
		fmt.Fprintln(out, "Petr")
	} else {
		fmt.Fprintln(out, "Um_nik")
	}

}
