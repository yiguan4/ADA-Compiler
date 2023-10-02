.class public testFor
.super java/lang/Object

.field private static _sysin Ljava/util/Scanner;
.field private static a [I
.field private static ch C
.field private static i I
.field private static j I

;
; Runtime input scanner
;
.method static <clinit>()V

	new	java/util/Scanner
	dup
	getstatic	java/lang/System/in Ljava/io/InputStream;
	invokespecial	java/util/Scanner/<init>(Ljava/io/InputStream;)V
	putstatic	testFor/_sysin Ljava/util/Scanner;
	return

.limit locals 0
.limit stack 3
.end method

;
; Main class constructor
;
.method public <init>()V
.var 0 is this LtestFor;

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

	iconst_5
	newarray	int
	putstatic	testFor/a [I

;
; 007 foriin1..5loopputLine("I = ",i);endloop
;
	iconst_1
	putstatic	testFor/i I
L001:
	getstatic	testFor/i I
	iconst_5
	if_icmpgt	L002
;
; 008 putLine("I = ",i)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"%s%d\n"
	iconst_2
	anewarray	java/lang/Object
	dup
	iconst_0
	ldc	"I = "
	aastore
	dup
	iconst_1
	getstatic	testFor/i I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
	getstatic	testFor/i I
	iconst_1
	iadd
	putstatic	testFor/i I
	goto	L001
L002:
;
; 011 forjinreverse1..5loopputLine("j = ",j);endloop
;
	iconst_5
	putstatic	testFor/j I
L003:
	getstatic	testFor/j I
	iconst_1
	if_icmplt	L004
;
; 012 putLine("j = ",j)
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
	getstatic	testFor/j I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
	getstatic	testFor/j I
	iconst_1
	isub
	putstatic	testFor/j I
	goto	L003
L004:
;
; 015 forchin'a'..'m'loopputLine("ch = ",ch);endloop
;
	bipush	97
	putstatic	testFor/ch C
L005:
	getstatic	testFor/ch C
	bipush	109
	if_icmpgt	L006
;
; 016 putLine("ch = ",ch)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"%s%c\n"
	iconst_2
	anewarray	java/lang/Object
	dup
	iconst_0
	ldc	"ch = "
	aastore
	dup
	iconst_1
	getstatic	testFor/ch C
	invokestatic	java/lang/Character/valueOf(C)Ljava/lang/Character;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
	getstatic	testFor/ch C
	iconst_1
	iadd
	putstatic	testFor/ch C
	goto	L005
L006:

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
