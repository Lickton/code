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