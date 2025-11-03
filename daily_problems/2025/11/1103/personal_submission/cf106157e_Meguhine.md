以下推导基于 $t>3m>0,\ 3\le n\le\left\lfloor\dfrac{t}{m}\right\rfloor$

$$
\begin{eqnarray}
f(n)&=&\frac{n(\dfrac{t}{n}-m)^2}{4\tan(\dfrac{\pi}{n})} \\
&=&\frac{(t-nm)^2}{4n\tan(\dfrac{\pi}{n})}
\end{eqnarray}
$$

令 $k=\dfrac{t}{m}$，把 $f(n)$ 当成连续函数：

$$
\begin{eqnarray}
f(n)&=&\frac{(t-nm)^2}{4n\tan(\dfrac{\pi}{n})} \\
&=&\frac{m^2(k-n)^2}{4n\tan(\dfrac{\pi}{n})}
\end{eqnarray}
$$

两边同时取对数：

$$
\ln\left[f(n)\right]=2\ln(m)+2\ln(k-n)-\ln 4-\ln n-\ln \tan(\dfrac{\pi}{n})
$$

两边取导：

$$
\begin{eqnarray}
\frac{\mathrm{d}}{\mathrm{d}n}\ln\left[f(n)\right] &=& 2\cdot\frac{\mathrm{d}}{\mathrm{d}n}\ln\left(k-n\right) - \frac{1}{n} - \frac{\mathrm{d}}{\mathrm{d}n}\ln\tan\left(\dfrac{\pi}{n}\right) \\
&=& \frac{-2}{k-n} - \frac{1}{n} - \frac{1}{\tan\left(\dfrac{\pi}{n}\right)}\cdot\frac{1}{\cos^2\left(\dfrac{\pi}{n}\right)}\cdot\frac{-\pi}{n^2} \\
&=& \frac{-2}{k-n} - \frac{1}{n} - \frac{-\pi}{n^2\sin\left(\dfrac{\pi}{n}\right)\cos\left(\dfrac{\pi}{n}\right)} \\
&=& \frac{-2}{k-n} - \frac{1}{n} + \frac{2\pi}{n^2\sin\left(\dfrac{2\pi}{n}\right)} \\
\end{eqnarray}
$$

这个函数设为 $\varphi(n)$，~~后面不会严谨证了~~，代几个值乱搞一通发现 $\varphi(n)$ 单调递减，所以 $f(n)$ 最多只有一个峰，三分即可
