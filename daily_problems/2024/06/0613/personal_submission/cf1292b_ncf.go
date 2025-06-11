package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1292B(os.Stdin, os.Stdout) }

func CF1292B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var x, y, ax, ay, bx, by, xs, ys, t int
	fmt.Fscan(in, &x, &y, &ax, &ay, &bx, &by, &xs, &ys, &t)

	var xList, yList []int

	for x+y-xs-ys <= t {
		xList = append(xList, x)
		yList = append(yList, y)
		x = ax*x + bx
		y = ay*y + by
	}

	n := len(xList)
	ans := 0
	for i := 0; i < n; i++ { // 第一个点
		for j := 0; j < i+1; j++ {
			for k := i; k < n; k++ { // [j, k]
				if abs1292b(xs-xList[i])+abs1292b(ys-yList[i])+
					min(xList[k]-xList[i]+yList[k]-yList[i], xList[i]-xList[j]+yList[i]-yList[j])+
					xList[k]-xList[j]+yList[k]-yList[j] <= t { // 到第一个点的距离 + 较短的端点距离 + 整段的距离 <= t
					ans = max(ans, k-j+1)
				}
			}
		}
	}

	fmt.Fprintf(out, "%d", ans)
}

func abs1292b(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}
