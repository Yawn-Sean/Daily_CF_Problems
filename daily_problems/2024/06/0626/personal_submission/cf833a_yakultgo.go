package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var a, b int
	fmt.Fscan(in, &a, &b)
	mul := a * b
	k := int(math.Round(math.Cbrt(float64(mul))))
	if k*k*k == mul && a%k == 0 && b%k == 0 {
		fmt.Fprintln(out, "Yes")
	} else {
		fmt.Fprintln(out, "No")
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	fmt.Fscan(in, &T)
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
