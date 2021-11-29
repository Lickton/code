# 5.1 大数定律
---
> 大量重复试验的平均结果的稳定性
## 5.1.1 切比雪夫不等式
> 定理：$EX$和$DX$存在，$\forall\epsilon>0$，有
$$P(\vert X-EX \vert \geq \epsilon) \leq \frac{DX}{\epsilon^2}$$
*证明*：
假设$X$连续,左:
$=\int{f(x)} {\rm d}x\le \int_{\vert X-EX\vert 
\geq \epsilon}{\frac{(X-EX)^2}{\epsilon^2}f(x){\rm d}x}$
$\leq \int_{-\infin}^{+\infin}{\frac{[x-E(x)]^2}{\epsilon^2}} = \frac{1}{\epsilon^2}\int_{-\infin}^{+\infin}(x-E(x))^2f(x){\rm d}x$
$=\frac{DX}{\epsilon^2}$

对于$\frac{DX}{\epsilon^2}$:
    1. $DX$越小，波动越小，落在外面的概率越大
        2. $DX$越大，波动越大
        3. $\epsilon$越大，落在外面的概率越小
        4. $\epsilon$越小，落在外面的概率更大

*Example*:
对于$X\sim N(\mu,\sigma^2)$，求$P\{\vert x-\mu\vert\geq3\sigma^2\}$
*solution*:
$P\{\vert x-\mu\vert\geq3\sigma^2\}$
$=1-P\{-3\sigma<x-\mu<3\sigma\}$
$=1-P\{-3<\frac{x-\mu}{\sigma}<3\}$
$=1-(\Phi_o(3)-\Phi_o(-3))$
$=1-(\Phi_o(3)-1+\Phi_o(3))$
$=2-2\Phi_0(3)$

## 5.1.2 切比雪夫大数定律
+ 收敛： $a_n \to a. \forall \epsilon>0,\exist N>0, when\ n>N, \vert a_n - a \vert <\epsilon.$
+ 依概率收敛:$x_n\to a, P\{\vert x_n-a\vert<\epsilon\} = 1, \lim_{n\to\infin}P\{\vert x_n-a\vert<\epsilon\}=1$

频率$\to$概率
>伯努利大数定律:
$n$重，$A$发生了$m_n$次，$P$概率,$\frac{m_n}{n}$频率，
$$\lim_{n\to \infin}{P\{\vert \frac{m_n}{n}-P\vert <\epsilon}\} = 1 \tag{1}$$
*证明*:
$m_n\sim B(n,p)\ Em_n=np,Dm_n=np(1-p)$
$E(\frac{m_n}{n})=P,\ D(\frac{m_n}{n})=\frac{pn(1-p)}{n^2}=\frac{p(1-p)}{n}$
$1 \geq P\{\vert\frac{m_n}{n}-P\vert<\epsilon\}\geq 1-\frac{\frac{p(1-p)}{n}}{\epsilon^2}\to 1$
对于上式$n\to\infin,\ \frac{m_n}{n}\to p$

>独立同分布:
$x_1...x_n$（独立，且满足同一分布）
$$
x_i=
\begin{cases}
1, if\ occur \\
0, don't \ occur
\end{cases} \\
EX_i=p(1-p),\ DX_i=p(1-p),\\ m_n=\sum_{i=1}^{n}x_i,\ \frac{m_n}{n}=\frac{1}{n}\sum_{i=1}^{n}x_i\\P=E(\frac{1}{n}\sum x_i)=\frac{1}{n}\sum_{i=1}^{n}EX_i\tag{2}$$
将$2$式带入$1$式,得：
$$
\lim_{n\to\infin}{P\{\vert\frac{1}{n}\sum_{i=1}^{n}x_i-\frac{1}{n}\sum_{i=1}^{n}EX_i\vert<\epsilon\}=1}\tag{3}
$$
> 切比雪夫大数定律:
$x_1...x_n不相关的变量$,$EX_i$和$DX_i$都存在，方差有界，$DX_i\leq M,\forall\epsilon>0$
$$
\lim_{n\to\infin}{P\{\vert\frac{1}{n}\sum_{i=1}^{n}x_i-\frac{1}{n}\sum_{i=1}^{n}EX_i\vert<\epsilon\}=1}\tag{3}
$$
$3$式中，$\frac{1}{n}\sum_{i=1}^{n}x_i$为均值，$\frac{1}{n}\sum_{i=1}^{n}EX_i$为期望的均值，**意即变量的均值收敛与期望的均值**
证明:
$$
E(\frac{1}{n}\sum_{i=1}^{n}x_i)=\frac{1}{n}\sum_{i=1}^{n}EX_i,\\x_1...x_n不相关，则cov(x_i,x_j)=0,\ D(X+Y)=DX+DY-2cov(x,y)=DX+DY\\D(\frac{1}{n}\sum_{i=1}^{n}x_i)=\frac{1}{n^2}\sum_{i=1}^{n}DX_i\leq\frac{nM}{n^2}=\frac{M}{n}\\1\geq P\{\vert\frac{1}{n}\sum_{i=1}^{n}-\frac{1}{n}\sum_{i=1}{n}EX_i\vert<\epsilon\}\geq 1-\frac{D(\frac{1}{n}\sum{x_i})}{\epsilon^2}\geq 1-\frac{M}{n\epsilon^2}\to 1\tag{4}
$$
$4$式适用夹逼准则，故$3$式为成立.

推论:
+ $x_1...x_n$独立分布，$EX_i=\mu, DX_i=\sigma^2, \ \forall\epsilon>0$
$$
\lim_{n\to\infin}{P\{\vert\frac{1}{n}\sum_{i=1}^{n}x_i-\mu\vert<\epsilon\}=1}
$$
>辛钦大数定律:
$x_1...x_n$独立分布，$EX_i=\mu$，方差无要求，
$$
\lim_{n\to\infin}{P\{\vert\frac{1}{n}\sum_{i=1}^{n}x_i-\mu\vert<\epsilon\}=1}\tag{5}
$$
依然成立

# 5.2 中心极限定理
