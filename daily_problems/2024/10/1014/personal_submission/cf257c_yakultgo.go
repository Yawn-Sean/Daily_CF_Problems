package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	angle := make([]float64, 0)
	var x, y int
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &x, &y)
		tmp := math.Atan2(float64(y), float64(x)) * 180 / math.Pi
		angle = append(angle, tmp)
	}
	sort.Slice(angle, func(i, j int) bool {
		return angle[i] < angle[j]
	})
	angle = append(angle, angle[0]+360)
	ans := -1.0
	for i := 0; i < n; i++ {
		ans = math.Max(ans, angle[i+1]-angle[i])
	}
	fmt.Fprintf(out, "%.10f\n", 360-ans)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
