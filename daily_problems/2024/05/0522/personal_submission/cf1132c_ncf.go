package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1132C(os.Stdin, os.Stdout) }

func CF1132C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, q int
	fmt.Fscan(in, &n, &q)

	// 读入数据并差分统计每个点的值
	diff := make([]int, n+2)
	a := make([][]int, q)
	for i := 0; i < q; i++ {
		a[i] = make([]int, 2)
		fmt.Fscan(in, &a[i][0], &a[i][1])
		diff[a[i][0]] += 1
		diff[a[i][1]+1] -= 1
	}

	// 前缀和求值为1的点个数
	acc := make([]int, n+1)
	// 前缀和求值为2的点个数
	acc2 := make([]int, n+1)
	// cur为当前值，sm为值大于0的点的个数
	cur, sm := 0, 0
	for i := 1; i <= n; i++ {
		acc[i] = acc[i-1]
		acc2[i] = acc2[i-1]
		cur += diff[i]
		if cur > 0 {
			sm += 1
			if cur == 1 {
				acc[i] += 1
			} else if cur == 2 {
				acc2[i] += 1
			}
		}
	}

	ans := 0
	for i := 0; i < q-1; i++ {
		for j := i + 1; j < q; j++ {
			l1, l2, r1, r2 := a[i][0], a[j][0], a[i][1], a[j][1]
			if l1 > l2 {
				l1, l2, r1, r2 = l2, l1, r2, r1
			}
			repeat := 0
			if r1 >= l2 { // 区间重合，需要减去两个点的情况
				repeat = acc2[min(r1, r2)] - acc2[l2-1]
			}
			ans = max(ans, sm-(acc[r1]-acc[l1-1])-(acc[r2]-acc[l2-1])-repeat)
		}
	}

	fmt.Fprintf(out, "%d", ans)
}
