.class public testFunction
.super java/lang/Object

.field private static _sysin Ljava/util/Scanner;
.field private static a I
.field private static b I

;
; Runtime input scanner
;
.method static <clinit>()V

	new	java/util/Scanner
	dup
	getstatic	java/lang/System/in Ljava/io/InputStream;
	invokespecial	java/util/Scanner/<init>(Ljava/io/InputStream;)V
	putstatic	testFunction/_sysin Ljava/util/Scanner;
	return

.limit locals 0
.limit stack 3
.end method

;
; Main class constructor
;
.method public <init>()V
.var 0 is this LtestFunction;

	aload_0
	invokespecial	java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

;
; FUNCTION sumsqr
;
.method private static sumsqr(II)I

.var 2 is a I
.var 3 is sumsqr I
.var 0 is x I
.var 1 is y I
;
; 006 X:=X*X
;
	iload_0
	iload_0
	imul
	istore_0
;
; 007 A:=X+Y*Y
;
	iload_0
	iload_1
	iload_1
	imul
	iadd
	istore_2
;
; 008 ReturnA
;
	iload_2

	ireturn

.limit locals 4
.limit stack 3
.end method

;
; PROCEDURE print
;
.method private static print(I)V

.var 0 is n I
;
; 014 putline("result is: ",n)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"%s%d\n"
	iconst_2
	anewarray	java/lang/Object
	dup
	iconst_0
	ldc	"result is: "
	aastore
	dup
	iconst_1
	iload_0
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop

	return

.limit locals 1
.limit stack 6
.end method

;
; MAIN
;
.method public static main([Ljava/lang/String;)V
.var 0 is args [Ljava/lang/String;
.var 1 is _start Ljava/time/Instant;
.var 2 is _end Ljava/time/Instant;
.var 3 is _elapsed J

	invokestatic	java/time/Instant/now()Ljava/time/Instant;
	astore_1

;
; 021 A:=2
;
	iconst_2
	putstatic	testFunction/a I
;
; 022 B:=2
;
	iconst_2
	putstatic	testFunction/b I
;
; 024 print(Sumsqr(A,B))
;
	getstatic	testFunction/a I
	getstatic	testFunction/b I
	invokestatic	testFunction/sumsqr(II)I
	invokestatic	testFunction/print(I)V
;
; 026 NewLine
;

	invokestatic	java/time/Instant/now()Ljava/time/Instant;
	astore_2
	aload_1
	aload_2
	invokestatic	java/time/Duration/between(Ljava/time/temporal/Temporal;Ljava/time/temporal/Temporal;)Ljava/time/Duration;
	invokevirtual	java/time/Duration/toMillis()J
	lstore_3
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"\n[%,d milliseconds execution time.]\n"
	iconst_1
	anewarray	java/lang/Object
	dup
	iconst_0
	lload_3
	invokestatic	java/lang/Long/valueOf(J)Ljava/lang/Long;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop

	return

.limit locals 6
.limit stack 8
.end method
