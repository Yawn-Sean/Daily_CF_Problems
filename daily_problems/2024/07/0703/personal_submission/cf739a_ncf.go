package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF739A(os.Stdin, os.Stdout) }

func CF739A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m, l, r int
	fmt.Fscan(in, &n, &m)
	mex := n
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &l, &r)
		mex = min(mex, r-l+1)
	}
	fmt.Fprintf(out, "%d\n", mex)
	for i := 0; i < n; i++ {
		fmt.Fprintf(out, "%d ", i%mex)
	}
}
