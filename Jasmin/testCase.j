.class public testCase
.super java/lang/Object

.field private static _sysin Ljava/util/Scanner;
.field private static ch C
.field private static i I
.field private static j I
.field private static str Ljava/lang/String;

;
; Runtime input scanner
;
.method static <clinit>()V

	new	java/util/Scanner
	dup
	getstatic	java/lang/System/in Ljava/io/InputStream;
	invokespecial	java/util/Scanner/<init>(Ljava/io/InputStream;)V
	putstatic	testCase/_sysin Ljava/util/Scanner;
	return

.limit locals 0
.limit stack 3
.end method

;
; Main class constructor
;
.method public <init>()V
.var 0 is this LtestCase;

	aload_0
	invokespecial	java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
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
; 007 i:=3
;
	iconst_3
	putstatic	testCase/i I
;
; 008 Ch:='b'
;
	bipush	98
	putstatic	testCase/ch C
;
; 009 caseI+1iswhen1=>j:=i;when-8=>j:=8*i;when5|7|4=>j:=574*i;endcase
;
	getstatic	testCase/i I
	iconst_1
	iadd
	iconst_1
	if_icmpeq	L002
	getstatic	testCase/i I
	iconst_1
	iadd
	bipush	-8
	if_icmpeq	L003
	getstatic	testCase/i I
	iconst_1
	iadd
	iconst_5
	if_icmpeq	L004
	getstatic	testCase/i I
	iconst_1
	iadd
	bipush	7
	if_icmpeq	L004
	getstatic	testCase/i I
	iconst_1
	iadd
	iconst_4
	if_icmpeq	L004
	goto	L001
L002:
;
; 010 j:=i
;
	getstatic	testCase/i I
	putstatic	testCase/j I
	goto	L001
L003:
;
; 011 j:=8*i
;
	bipush	8
	getstatic	testCase/i I
	imul
	putstatic	testCase/j I
	goto	L001
L004:
;
; 012 j:=574*i
;
	sipush	574
	getstatic	testCase/i I
	imul
	putstatic	testCase/j I
	goto	L001
L001:
;
; 014 putline("j = ",j)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"%s%d\n"
	iconst_2
	anewarray	java/lang/Object
	dup
	iconst_0
	ldc	"j = "
	aastore
	dup
	iconst_1
	getstatic	testCase/j I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
;
; 016 casechiswhen'c'|'b'=>str:="p";when'a'=>str:="q";endcase
;
	getstatic	testCase/ch C
	bipush	99
	if_icmpeq	L006
	getstatic	testCase/ch C
	bipush	98
	if_icmpeq	L006
	getstatic	testCase/ch C
	bipush	97
	if_icmpeq	L007
	goto	L005
L006:
;
; 017 str:="p"
;
	ldc	"p"
	putstatic	testCase/str Ljava/lang/String;
	goto	L005
L007:
;
; 018 str:="q"
;
	ldc	"q"
	putstatic	testCase/str Ljava/lang/String;
	goto	L005
L005:
;
; 020 putline("str = ",str)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"%s%s\n"
	iconst_2
	anewarray	java/lang/Object
	dup
	iconst_0
	ldc	"str = "
	aastore
	dup
	iconst_1
	getstatic	testCase/str Ljava/lang/String;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop

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
