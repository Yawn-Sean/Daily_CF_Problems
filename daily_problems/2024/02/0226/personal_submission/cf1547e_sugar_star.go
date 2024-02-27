package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func cf1547E(_r io.Reader, w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(w)
	defer out.Flush()
	var t int
	for Fscan(in, &t); t > 0; t-- {
		var n, k int
		Fscan(in, &n, &k)
		a := make([]int, n)
		var q = make([]int, k)
		for i := 0; i < k; i++ {
			Fscan(in, &q[i])
			q[i]--
		}
		for i := range q {
			Fscan(in, &a[q[i]])
		}
		L := make([]int, n)
		R := make([]int, n)
		// [j,i] 当前位置为i j有空调
		// res = i - j + a[j]
		//     = i + (a[j] - j)
		// 保持最小即可 因此保存的是a[i]-i的最小值
		pre := 0x3f3f3f3f
		for i := 0; i < n; i++ {
			if a[i] != 0 {
				pre = min(pre, a[i]-i)
			}
			L[i] = pre + i
		}
		pre = 0x3f3f3f3f
		// [i,j]
		// res = j - i + a[j]
		//     = j + a[j] - i
		// 保存最小即可 因此保存的是a[i]+i的最小值
		for i := n - 1; i >= 0; i-- {
			if a[i] != 0 {
				pre = min(pre, a[i]+i)
			}
			R[i] = pre - i
		}
		for i := 0; i < n; i++ {
			Fprint(out, min(L[i], R[i]), " ")
		}
		Fprintln(out)
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	cf1547E(os.Stdin, os.Stdout)
}
