令 $p:=\texttt{popcount}(x)-1$

由定义知：$f(0,x)=x$

考虑每 1 位会在 $2^p$ 个“子数”里出现，故 $f(1,x)=2^px$

考虑 $f(2,x)$，有 $\binom{p}{p}$ 个“子数”的贡献是 $2^p$，$\binom{p}{p-1}$ 个“子数”的贡献是 $2^{p-1}$，$\cdots$

$$
\begin{eqnarray}
f(2,x)&=&\left[\binom{p}{p}2^p+\binom{p}{p-1}2^{p-1}+\cdots+\binom{p}{0}2^0\right]x \\ 
&=&(1+2)^px=3^px
\end{eqnarray}
$$

以此类推，得到 $\text{ans}:=(k+1)^px$
