package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"slices"
)

const mod int = 998244353

func solveD(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	// 对于一个子序列 b, f(b) = max(max(b), (sum(b)+1)/2)
	// 排序后，仅与当前遍历到的元素和元素和有关
	slices.Sort(a)
	ans := 0
	cntsum := [5001]int{}
	cntsum[0] = 1
	for _, v := range a {
		for j := 5000 - v; j >= 0; j-- {
			ans = (ans + cntsum[j]*max(v, (j+v+1)/2)) % mod
			cntsum[j+v] = (cntsum[j+v] + cntsum[j]) % mod
		}
	}
	fmt.Fprintln(out, ans)
}

func main() {
	solveD(os.Stdin, os.Stdout)
}
