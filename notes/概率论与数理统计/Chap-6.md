# 6.1 总体与样本
> 基本概念：
1. 总体、个体、有限总体、无线总体
2. $X$的分布为总体分布
3. 样本:抽样$(X_1,...,X_n)$(变量),$(x_1,...x_n)$(观测值)
4. 简单随机抽样
    + 同分布
    + 独立

>样本的分布:
对于$(x_1,..,x_n)$，有
$$
F(x_1...x_n)=F(x_1)...F(x_n)\\
P(X_1=x_1,...,X_n=x_n)=P(X_1=x_1)...P(X_n=x_n)\\
f(x_1...x_n)=f(x_1)...f(x_n)
$$
证明:
$x:0-1分布$,$p$,$(x_1,...x_n)$是样本
$\therefore P(X=x)=p^x(1-p)^{1-x},x=0,1$
$\therefore P(X_1=x_1,...X_n=x_n)=p(X_1=x_1)...P(X_n=x_n)=p^{x_1}(1-p)^{1-x_1}...p^{x_n}(1-p)^{1-x_n}$
$=p^{x_1+...+x_n}(1-p)^{n-(x_1+...+x_n)}$

# 6.2 统计量
>定义:
不含任何**未知**参数的样本的函数
例如：  $x_1+x_2+...+x_n$, $max\{\vert x_1\vert ...\vert x_n\vert\}$是统计量

>常用统计量:
设样本$(X_1,X_2,...,X_n)$来自总体$X$,即有
+ 样本均值: $\overline{X}=\frac{1}{n}\sum_{i=1}^{n}X_i$
+ 未修正的样本方差: $S_0=\frac{1}{n}\sum_{i=1}^{n}(X_i-\overline{X})^2$
+ 样本方差(*修正的样本方差*):$S^2=\frac{1}{n-1}\sum_{i=1}^{n}(X_i-\overline{X})^2$
+ 样本标准差:$S=\sqrt{S^2}$
+ 样本$k$阶原点矩:$A_k=\frac{1}{n}\sum_{i=1}^{n}X_i^k$      *一阶原点矩即为均值*
+ 样本$k$阶中心矩:     $B_k=\frac{1}{n}\sum_{i=1}{n}(X_i-\overline{X})^k$       *二阶中心矩即为方差$B_2=S_0^2$*
+ 协方差:$S_{12}=\frac{1}{n}\sum(X_i-\overline{X})(Y_i-\overline{Y}),R=\frac{S_{12}}{S_1S_2}$，其中$R$为相关系数

*Example*:
$\lambda$为参数的泊松分布，$EX=DX=\lambda$
$E\overline{X}=E(\frac{1}{n}\sum_{i=1}^{n}x_i)=\frac{1}{n}E(\sum x_i)=\frac{1}{n}\sum Ex_i=\frac{1}{n}n\lambda=\lambda$
$D\overline{X}=D(\frac{1}{n}\sum_{i=1}^{n}x_i)=\frac{1}{n^2}D(\sum x_i)=\frac{1}{n^2}\sum Dx_i=\frac{1}{n^2}n\lambda=\frac{\lambda}{n}$

>定理:
设总体$X$的均值为$EX=\mu$，方差为$DX=\sigma^2$，样本$(X_1,...,X_n)$来自总体$X$，则
+ $E\overline{X}=\mu$
+ $D\overline{X}=\frac{1}{n}\sigma^2$
+ $ES^2=\sigma^2$

# 6.3 抽样分布
>统计量的分布

## 1. 正态分布
略

## 2. $\chi^2$分布
$\chi^2(n)$，其中$n$为自由度
1. $\chi^2$，为$\lambda=\frac{1}{2}$的指数分布
2. 单峰曲线，$n=2$取最大值，图像不对称,$n$越大，越接近正态分布

> 定理：
若$x_1,...,x_n$满足$N(0,1)$，$$\chi^2=\sum_{i=1}^{n}x_i^2\sim\chi^2(n)\tag{1}$$
$EX=n,DX=2n$

由中心极限定理知,$X\sim\chi^2(n)$,$n$充分大,$\frac{X-n}{\sqrt{2n}}\sim N(0,1)$

>定理:
$X\sim\chi^2(n),Y\sim\chi^2(m)$，$X,Y$独立，$X+Y\sim\chi^2(m+n)$
推论：
$X_i\sim\chi^2(m_i)$，独立$\sum_{i=1}^{n}x_i\sim\chi^2(\sum_{i=1}^{n}m_i)$

>上$\alpha$分位数:
$$P(\chi^2>\chi^2_{\alpha}(n))=\alpha$$
其中,$\alpha$的统计意义为面积（概率），$\chi^2_{\alpha}(n)$的统计意义为点

![1035701-20180113204005816-212118222](/assets/1035701-20180113204005816-212118222.jpg)

*Example*:
$X\sim\chi^2(10)$,求$P(x>a)=0.025$,$P(x>a)$,$P(x<b)=0.05$ 的$a$和$b$.
*Solution*:
$n=10,\alpha=0.025$
$\therefore\chi^2_{0.025}(10)=20.5=a$
$P(x<b)=1-P(x\geq b)=0.05$
$\therefore b=\chi^2_{0.095}(10)=3.94$

*Example*:
$X_1,...,X_6，N(0,2^2)$,求$P(\sum_{i=1}^6x_i^2>6.54)$
*Solution*:
首先化为标准正态分布$X_i\sim N(0,2^2)$
$\frac{x_i}{2}\sim N(0,1)$
$\therefore \sum_{i=1}^{6}(\frac{x_i}{2})^2\sim \chi^2$
$\therefore P(\frac{\sum_{i=1}^{6}x_i^2}{4}>\frac{6.54}{4})=P(\chi^2(6)>1.635)=0.95$

## 3. $t$分布
$X\sim t(n)$
$n\geq30$时，与正态分布差别不大
![TStudent](/assets/TStudent.png)
>定理
$X\sim N(0,1),Y\sim\chi^2(n)$若$X,Y$独立，则：
$$
\frac{X}{\sqrt{Y/n}}\sim t(n)\tag{2}
$$

上$\alpha$分位数:$P(T>t_{\alpha}(n))=\alpha$
$t_{1-\alpha}(n)=-t_{\alpha}(n)$

*Example*:
$X\sim N(2,1),Y_1,...Y_4,\sim N(0,4)$，独立,令$T=\frac{4(x-2)}{\sqrt{\sum_{i=1}^4Y_i^2}}$，$P(\vert T\vert>t_0)=0.01$
*Solution*:
标准化$\frac{X-2}{1}\sim N(0,1),\frac{Y_i-0}{2}\sim N(0,1)$
由$1$式可知:$$\sum_{i=1}^{4}(\frac{Y_i}{2})^2\sim\chi^2(4),\frac{\frac{x-2}{1}}{\sqrt{\sum_{i=1}^{4}(\frac{Y_i}{2})^2/4}}\tag{3}$$
由$2$式得$3$式为$\frac{4(x-2)}{\sqrt{\sum_{i=1}^{4}}Y_i^2}\sim t(4)$
由于$t$分布关于原点对称，查表$P(T>t_0)=0.005$,此$t_0=4.604$

## 4. $F$分布
$F(n_1,n_2)$

>定理
$X\sim\chi^2(n_1),Y\sim\chi^2(n_2）$,独立,则$$
\frac{X/n_1}{Y/n_2}\sim F(n_1,n_2)\tag{4}
$$