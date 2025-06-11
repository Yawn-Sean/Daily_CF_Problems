package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF578A(os.Stdin, os.Stdout) }

func CF578A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var a, b int
	fmt.Fscan(in, &a, &b)
	if a < b {
		fmt.Fprintf(out, "-1")
		return
	} else if a == b {
		fmt.Fprintf(out, "%d", b)
		return
	}
	fmt.Fprintf(out, "%.12f", min(float64(a-b)/float64((a-b)/(b*2)), float64(a+b)/float64((a+b)/(b*2)))/float64(2))
}
