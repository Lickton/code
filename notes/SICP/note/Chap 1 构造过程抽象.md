# Chap-1 构造过程抽象

## 1.1 程序设计的基本元素

+ 基本表达形式
+ 组合的方法
+ 抽象的方法

### 1.1.1 表达式

- 组合式：`(+ 99 20)`、`(* 1 2 3 4 5)`
- 运算符
- 运算对象
- 实际参数
- 前缀表示
- 嵌套：允许组合式的元素本身又是组合式
  `(+ (- 100 1) 200)`

### 1.1.2 命名和环境

+ 变量、定义（最简单的抽象方法）：`(define size 2)`

  `define`不是一种组合式

  > 一个程序通常是由一大批相对简单的过程组成的。
+ 环境：解释器维护并保持有关名-值对偶的轨迹的储存环境

  > 环境所扮演的角色就是用于确定表达式中各个符号的意义

### 1.1.3 组合式的求值

+ 求值一个组合式的标准流程：

  1. 求值该组合式的各个子表达式
  2. 将作为最左子表达式（运算符）的值的那个过程应用于相应的实际参数（也就是其他子表达式的值）

  > 性质上，这一求值过程是递归的
  >
  > 采用递归的思想可以简洁的描述深度嵌套的情况
  >
+ 递归视作一种处理层次性结构的强有力的技术
+ 树状积累
+ 求值规则：

  1. 数的值就是它们所表示的数值
  2. 内部运算符的值就是能够完成相应操作的机器指令序列
  3. 其他名字的值就是在环境中关联于这一名字的那个对象

### 1.1.4 复合过程

程序设计语言里的基本元素：

+ 数和算数运算是基本的数据和过程
+ 组合式的嵌套提供了一种组织起多个操作的方法
+ 定义是一种受限的抽象手段，它为名字关联相应的值
+ 过程定义：为复合操作提供名字

  `(define (square x) (* x x))`

  `(define (<name> <formal parameters>) <body>)`

### 1.1.5 过程应用的代换模型

+ 代换模型
+ 应用序与正则序
  + 正则序求值：先展开过程，再求值
  + 应用序求值：先求值，再代入过程

### 1.1.6 条件表达式和谓词

+ 分情况分析

  表达式的一般形式：

  ```lisp
  (cond (<p1> <e1>)
      (<p2> <e2>)
      ...
      (<pn> <en>))
  ```


  ```lisp
  (define (abs x)
      (cond ((> x 0) x)
         	 ((= x 0) 0)
         	 ((< x 0) (- x))))
  ```
+ 谓语：每个对偶的第一个表达式
+ 谓词：返回真或假的过程，也指能求出真或假的表达式

  ```lisp
  (define (abs x)
      (cond ((< x) (- x))
          (else x)))
  ```

  + `if`表达式的一般形式为:`(if <predicate> <consequent> <alternative>)`

  ```lisp
  (define (abs x)
      (if (< x 0)
          (- x)
          x))
  ```

  + `and`、`or`：都是特殊形式而非普通的过程，因为它们的子表达式不一定都求值，比如说 `(or 1 abs(0))`当中 `abs(0)`就没有求值

+ 练习1.2

  ```lisp
  (/ (+ 5
        4
        (- 2 
           (- 3 
              (+ 6
                 (/ 4 5)))))
     (* 3
        (- 6
           2)
        (- 2
           7)))
  ```
+ 练习1.3

  ```lisp
  (define (f x y z)
      (cond ((> x y) (if (> x z) 
                         x))
          ((> y z) y)
          (else z)))
  ```
+ 练习1.5

  在应用序中，所有被传入的实际参数都会立即被求值，因此，在使用应用序的解释器里执行 `(test 0 (p))` 时，实际参数 `0` 和 `(p)` 都会被求值，而对 `(p)` 的求值将使解释器进入无限循环，因此，如果一个解释器在运行 Ben 的测试时陷入停滞，那么这个解释器使用的是应用序求值模式。

  另一方面，在正则序中，传入的实际参数只有在有需要时才会被求值，因此，在使用正则序的解释器里运行 `(test 0 (p))` 时， `0` 和 `(p)` 都不会立即被求值，当解释进行到 `if` 语句时，形式参数 `x` 的实际参数(也即是 `0`)会被求值(求值结果也是为 `0` )，然后和另一个 `0` 进行对比(`(= x 0)`)，因为对比的值为真(`#t`),所以 `if` 返回 `0` 作为值表达式的值，而这个值又作为 `test` 函数的值被返回。

  因为在正则序求值中，调用 `(p)` 从始到终都没有被执行，所以也就不会产生无限循环，因此，如果一个解释器在运行 Ben 的测试时顺利返回 `0` ，那么这个解释器使用的是正则序求值模式。

  > Note
  >
  > 另一个需要说明的地方是『形式参数』和『实际参数』两个名词。
  >
  > 对于一个函数来说，它接受的参数的局部名被称为形式参数。
  >
  > 而调用函数时传入的表达式，被称为实际参数。
  >
  > 比如说，对于函数 `(define (square x) (* x x))` 来说， `x` 就是形式参数，当进行调用 `(square 2)` 时， `2` 就是形式参数 `x` 的实际参数。
  >
  > 当人们只说『参数』而不说明它是『形式参数』还是『实际参数』时，他们一般指的是『形式参数』，但是具体还是要看上下文来决定。
  >

### 1.1.7 实例：采用牛顿法求平方根

+ 函数与过程的矛盾

  数学里，人们关心说明性的描述（是什么）

  计算机科学里，人们通常关心行动性描述（怎么做）
+ 牛顿迭代法

  ```lisp
  (define (average x y)
      (/ (+ x y) 2))

  (define (improve guess x)
      (average guess (/ x guess)))

  (define (square x)
      (* x x))

  (define (good-enough? guess x)
      (< (abs (- (square guess) x)) 0.001))

  (define (sqrt-iter guess x)
      (if (good-enough? guess x)
          guess
          (sqrt-iter (improve guess x)
                     x)))

  (define (sqrt x)
      (sqrt-iter 1.0 x))
  ```

+ 练习1.6

  主要问题在于：`if` 语句是一种特殊形式，当它的 `predicate` 部分为真时， `then-clause` 分支会被求值，否则的话， `else-clause` 分支被求值，两个 `clause` 只有一个会被求值。

  而另一方面，新定义的 `new-if` 只是一个普通函数，它没有 `if` 所具有的特殊形式，根据解释器所使用的应用序求值规则，每个函数的实际参数在传入的时候都会被求值，因此，当使用 `new-if` 函数时，无论 `predicate` 是真还是假， `then-clause` 和 `else-clause` 两个分支都会被求值。

  [详解](https://sicp.readthedocs.io/en/latest/chp1/6.html)
+ 练习1.7

  改进 `good-enough?`函数

  ```lisp
  (define (good-enough? guess x)
      (> 0.01
         (/ (abs (- guess x))
            x)))
  ```
+ 练习1.8

  ```lisp
  (define (good-enough? y x)
      (> 0.000001
         (abs (- y x))))

  (define (cube x)
      (* x x x))

  (define (improve y x)
      (/ (+ (/ x (square y)) (* 2 y)) 3))

  (define (cbrt-iter y x)
      (if (good-enough? (cube y) x)
          y
          (cbrt-iter (improve y x) x)))

  (define (cbrt x)
      (cbrt-iter 1.0 x))
  ```

### 1.1.8 过程作为黑盒抽象

+ 过程抽象
+ 局域名
+ 约束变量：一个过程的定义约束了它的所有形式参数
+ 内部定义与块结构：嵌套的定义(`define`)
+ 词法作用域

## 1.2 过程及其产生的计算

> 一个过程也就是一种模式，他描述了一个计算过程的局部演化方式，描述了这一计算过程中每个步骤是怎样基于前面的步骤建立起来的。

### 1.2.1 线性的迭代和递归

阶乘：$n!=n\cdot(n-1)\cdot(n-2)\cdot\cdot\cdot\cdot3\cdot2\cdot1$

+ 线性递归过程

  ```lisp
  (define (factorial n)
      (if (= n 1)
          1
          (* n (factorial (- n 1)))))
  ```

![[image-20220105141508035.png]]
+ 线性迭代过程

  规则：

  $$
  product \leftarrow counter \cdot product\
  $$
  $$
  counter \leftarrow counter + 1
$$


```lisp
(define (fact-iter product counter max-count)
      (if (> counter max-count)
          product
          (fact-iter (* counter product)
                     (+ counter 1)
                     max-count)))

(define (factorial n)
      (factorial-iter 1 1 n))
```

![[image-20220105141615984.png]]

+ 练习1.9
```lisp
; 1 ed
(define (+ a b)
	(if (= a 0)
		b
		(inc (+ (dec a) b))))

#|
			(+ 4 5)
			(inc (+ 3 5))
			(inc (inc (+ 2 5)))
			(inc (inc (inc (+ 1 5))))
			(inc (inc (inc (inc (+ 0 5)))))
			(inc (inc (inc (inc 5))))
			(inc (inc (inc 6)))
			(inc (inc 7))
			(inc 8)
			9
|#

; 2ed
(define (+ a b)
	(if (= a 0)
		b
		(+ (dec a) (inc b))))
#|
			(+ 4 5)
			(+ 3 6)
			(+ 2 7)
			(+ 1 8)
			(+ 0 9)
			9
|#

```
+ 练习1.10
参见[阿克曼函数](https://zh.wikipedia.org/wiki/%E9%98%BF%E5%85%8B%E6%9B%BC%E5%87%BD%E6%95%B8)
```
(A 1 10)
	(A 0 (A 1 9))
	2 * (A 0 (A 1 8))
	2 * 2 * (A 0 (A 1 7))
	...
	2^10 = 1024

(A 2 4)
	2^16 = 65536

(A 3 3)
	2^16 = 65536

(f n) -> 2n
(g n) -> 2^n
(h n) -> 2^(2^(2^...))
```
### 1.2.2 树形递归
+ 斐波那契数列
+ 实例：换零钱方式的统计
	分为两组，树状
	1. 没有用第一种硬币
	2. 用了第一种硬币
+ 练习1.11
```lisp
; recursion
(define (f n)
	(if (< n 3)
		n
		(+ (f (- n 1)) (* 2 (f (- n 2))) (* 3 (f (- n 3))))))

; iteration
(define (f n)
	(define (f-iter a b c count)
		(if (= count 0)
			c
			(f-iter (+ a (* 2 b) (* 3 c)) a b (- count 1))))
	(f-iter 2 1 0 n))
```
+ 练习1.12
```lisp
(define (fact-iter product counter max-count)
      (if (> counter max-count)
          product
          (fact-iter (* counter product)
                     (+ counter 1)
                     max-count)))

(define (factorial n)
      (fact-iter 1 1 n))

(define (pascal row col)
    (/ (factorial row)
       (* (factorial col)
          (factorial (- row col)))))
```
+ 练习1.13
![[Pasted image 20220105193625.png]]
### 1.2.3 增长的阶
+ 练习1.14
![[Pasted image 20220105195526.png]]
+ 练习1.15
	1. 5次
	2. $O(\log a)$

### 1.2.4 求幂

定义：
$$b^n=b\cdot b^{n-1}$$
$$b^0=1$$
```lisp
; 由定义直接得
; 时间复杂度O(n) 空间复杂度O(n)
(define (exprt b n)
	(if (= n 0)
		1
		(* b (exprt b (- n 1)))))


; 等价的线性迭代
; 时间复杂度O(n) 空间复杂度O(1)
(define (expt-iter b counter product)
	(if (= counter 0)
		product
		(expt-iter b
				   (- counter 1)
				   (* b product))))

(define (expt b n)
	(expt-iter b n 1))
```

更改规则：
$$b^n=(b^{\frac{n}{2}})^2, if\ n \in2k$$
$$b^n=b\cdot b^{n-1},if \ n \in 2k+1$$
```lisp
; 时间复杂度 O(log n) 空间复杂度 O(1)
(define (even? n)
	(= (remainder n 2) 0))

(define (fast-expt b n)
	(cond ((= n 0) 1)
		((even? n) (square (fast-expt b (/ n 2))))
		(else (* b (fast-expt b (- n 1))))))
```

+ 练习1.16

>  一般来说，定义一个不变量，要求它在状态之间保持不变，这一技术是思考迭代算法设计问题时的一种强有力的方法

$$a \cdot b^n = c$$


```lisp
(define (even? n)
	(= (remainder n 2) 0))

(define (fast-expt b n)
	(define (iter n b a)
		(cond ((= n 0) a)
			((even? n) (iter (/ n 2) (square b) a))
			(else (iter (- n 1) b (* b a)))))
	(iter n b 1))
```

+ 练习1.17

```lisp
; 线性递归
#|
(define (even? n)
	(= (remainder n 2) 0))

(define (double x)
	(* x 2))

(define (half x)
	(/ x 2))

(define (mult a b)
	(cond ((or (= a 0) (= b 0)) 0)
		((= b 1) a)
		((even? b) (mult (double a) (half b)))
		(else (+ a (mult a (- b 1) ))))))

|#

; 线性迭代

(define (even? n)
	(= (reminder n 2) 0))

(define (double x)
	(* 2 x))

(define (half x)
	(/ x 2))

(define (mult a b)
	(define (mult-iter a b product)
		(cond ((= b 0) product)
			(even? b) (mult-iter (double a) (half b) product)
			(else (mult-iter a (- b 1) (+ a product)))))
	(mult-iter a b 0))
```

+ 练习1.18

+ 练习1.19

