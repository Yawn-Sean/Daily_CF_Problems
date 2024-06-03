package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solveC(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, x int
	fmt.Fscan(in, &n, &x)
	// if x % 2 == 0 -> x ^ (x+1) ^ (x+2) ^ (x+3) = 0
	if n == 2 && x == 0 {
		fmt.Fprintln(out, "NO")
	} else if n%4 == 2 && x == 0 {
		fmt.Fprintln(out, "YES")
		for i := 0; i < (n-1)/4*4-4; i++ {
			fmt.Fprint(out, i+(1<<18)+2, " ")
		}
		fmt.Fprintln(out, "0 1 2 4 8 15")
	} else {
		fmt.Fprintln(out, "YES")
		for i := 0; i < (n-1)/4*4; i++ {
			fmt.Fprint(out, i+(1<<18)+2, " ")
		}
		n = (n - 1) % 4
		if n == 0 {
			fmt.Fprintln(out, x)
		} else if n == 1 {
			fmt.Fprintln(out, 0, x)
		} else if n == 2 {
			fmt.Fprintln(out, 1<<18, 1<<18|1<<17, (1<<17)^x)
		} else {
			fmt.Fprintln(out, 0, 1<<18, 1<<18|1<<17, (1<<17)^x)
		}
	}
}

func main() {
	solveC(os.Stdin, os.Stdout)
}
