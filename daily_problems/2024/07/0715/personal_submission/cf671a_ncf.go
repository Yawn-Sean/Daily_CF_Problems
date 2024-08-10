package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

func main() { CF671A(os.Stdin, os.Stdout) }

func CF671A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var ax, ay, bx, by, tx, ty, n, x, y int
	fmt.Fscan(in, &ax, &ay, &bx, &by, &tx, &ty, &n)
	mx := make([]float64, 4) // [a跟其他点的最大差值， a跟其他点的次大差值， b跟其他点的最大差值， b跟其他点的次大差值]  (未开方)
	for i := 0; i < 4; i++ {
		mx[i] = -1e18
	}
	mxIdx := make([]int, 4) // 对应mn中点的下标
	sm := 0.0
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &x, &y)
		v := math.Sqrt(float64(square671a(x-tx) + square671a(y-ty)))
		sm += v * 2
		av := v - math.Sqrt(float64(square671a(x-ax)+square671a(y-ay)))
		bv := v - math.Sqrt(float64(square671a(x-bx)+square671a(y-by)))
		if av > mx[1] {
			if av > mx[0] {
				mx[1] = mx[0]
				mxIdx[1] = mxIdx[0]
				mx[0] = av
				mxIdx[0] = i
			} else {
				mx[1] = av
				mxIdx[1] = i
			}
		}
		if bv > mx[3] {
			if bv > mx[2] {
				mx[3] = mx[2]
				mxIdx[3] = mxIdx[2]
				mx[2] = bv
				mxIdx[2] = i
			} else {
				mx[3] = bv
				mxIdx[3] = i
			}
		}
	}
	ans := min(min(math.Sqrt(float64(square671a(tx-ax)+square671a(ty-ay))), math.Sqrt(float64(square671a(tx-bx)+square671a(ty-by))))+sm, sm-mx[0], sm-mx[2])
	if mxIdx[0] != mxIdx[2] {
		ans = min(ans, sm-mx[0]-mx[2])
	} else {
		ans = min(ans, sm-mx[0]-mx[3], sm-mx[1]-mx[2])
	}
	fmt.Fprintf(out, "%.12f", ans)
}

func square671a(a int) int {
	return a * a
}
