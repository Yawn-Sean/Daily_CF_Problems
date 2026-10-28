package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var T int
	fmt.Fscan(in, &T)
	for ; T > 0; T-- {
		var n int
		fmt.Fscan(in, &n)
		arrX := make([]int, 0)
		arrY := make([]int, 0)
		minX, minY, maxX, maxY := math.MaxInt, math.MaxInt, math.MinInt, math.MinInt
		for range n {
			var x, y int
			fmt.Fscan(in, &x, &y)
			arrX = append(arrX, x)
			arrY = append(arrY, y)
			minX = min(minX, x)
			minY = min(minY, y)
			maxX = max(maxX, x)
			maxY = max(maxY, y)
		}
		var check = func(x, y int) bool {
			for i := range n {
				if arrX[i] == x && arrY[i] == y {
					return true
				}
			}
			return false
		}
		if check(minX, minY) && check(minX, maxY) && check(maxX, maxY) && check(maxX, minY) {
			fmt.Fprintln(out, "YES")
		} else {
			fmt.Fprintln(out, "NO")
		}
	}
}
