package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1041D(os.Stdin, os.Stdout) }

func CF1041D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, h int
	fmt.Fscan(in, &n, &h)
	x := make([][]int, n)
	for i := 0; i < n; i++ {
		x[i] = make([]int, 2)
		fmt.Fscan(in, &x[i][0], &x[i][1])
	}
	l, r, cur, xSum, ans := 0, 0, h, 0, 0

	for l < n { // 枚举所有左端点
		for r < n-1 && x[r+1][0]-x[r][1] < cur { // 如果当前高度能到达下一个上升点，右端点右移
			xSum += x[r][1] - x[r][0] // 上升区域总和
			cur -= x[r+1][0] - x[r][1] // 当前高度
			r++
		}
		ans = max(ans, xSum+x[r][1]-x[r][0]+h) 
		xSum -= x[l][1] - x[l][0] 
		l++
		if l < n {
			cur += x[l][0] - x[l-1][1]
		}
	}

	fmt.Fprintf(out, "%d", ans)
}
