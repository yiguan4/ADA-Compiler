.class public testIf
.super java/lang/Object

.field private static _sysin Ljava/util/Scanner;
.field private static ch C
.field private static grade I
.field private static i I
.field private static j I
.field private static x I

;
; Runtime input scanner
;
.method static <clinit>()V

	new	java/util/Scanner
	dup
	getstatic	java/lang/System/in Ljava/io/InputStream;
	invokespecial	java/util/Scanner/<init>(Ljava/io/InputStream;)V
	putstatic	testIf/_sysin Ljava/util/Scanner;
	return

.limit locals 0
.limit stack 3
.end method

;
; Main class constructor
;
.method public <init>()V
.var 0 is this LtestIf;

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
; 005 i:=1
;
	iconst_1
	putstatic	testIf/i I
;
; 006 j:=2
;
	iconst_2
	putstatic	testIf/j I
;
; 007 grade:=75
;
	bipush	75
	putstatic	testIf/grade I
;
; 009 ifi<jthenx:=-3;elsifi>jthenx:=10;elsex:=0;endif
;
	getstatic	testIf/i I
	getstatic	testIf/j I
	if_icmplt	L004
	iconst_0
	goto	L005
L004:
	iconst_1
L005:
	ifne	L002
	getstatic	testIf/i I
	getstatic	testIf/j I
	if_icmpgt	L006
	iconst_0
	goto	L007
L006:
	iconst_1
L007:
	ifne	L003
;
; 011 x:=0
;
	iconst_0
	putstatic	testIf/x I
	goto	L001
L002:
;
; 009 x:=-3
;
	iconst_3
	ineg
	putstatic	testIf/x I
	goto	L001
L003:
;
; 010 x:=10
;
	bipush	10
	putstatic	testIf/x I
	goto	L001
L001:
;
; 014 putline("x = ",x)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"%s%d\n"
	iconst_2
	anewarray	java/lang/Object
	dup
	iconst_0
	ldc	"x = "
	aastore
	dup
	iconst_1
	getstatic	testIf/x I
	invokestatic	java/lang/Integer/valueOf(I)Ljava/lang/Integer;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop
;
; 017 ifgrade>=90thench:='A';elsifgrade>=80thench:='B';elsifgrade>=70thench: ...
;
	getstatic	testIf/grade I
	bipush	90
	if_icmpge	L013
	iconst_0
	goto	L014
L013:
	iconst_1
L014:
	ifne	L009
	getstatic	testIf/grade I
	bipush	80
	if_icmpge	L015
	iconst_0
	goto	L016
L015:
	iconst_1
L016:
	ifne	L010
	getstatic	testIf/grade I
	bipush	70
	if_icmpge	L017
	iconst_0
	goto	L018
L017:
	iconst_1
L018:
	ifne	L011
	getstatic	testIf/grade I
	bipush	60
	if_icmpge	L019
	iconst_0
	goto	L020
L019:
	iconst_1
L020:
	ifne	L012
;
; 021 ch:='F'
;
	bipush	70
	putstatic	testIf/ch C
	goto	L008
L009:
;
; 017 ch:='A'
;
	bipush	65
	putstatic	testIf/ch C
	goto	L008
L010:
;
; 018 ch:='B'
;
	bipush	66
	putstatic	testIf/ch C
	goto	L008
L011:
;
; 019 ch:='C'
;
	bipush	67
	putstatic	testIf/ch C
	goto	L008
L012:
;
; 020 ch:='D'
;
	bipush	68
	putstatic	testIf/ch C
	goto	L008
L008:
;
; 024 putline("Your grade is: ",ch)
;
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"%s%c\n"
	iconst_2
	anewarray	java/lang/Object
	dup
	iconst_0
	ldc	"Your grade is: "
	aastore
	dup
	iconst_1
	getstatic	testIf/ch C
	invokestatic	java/lang/Character/valueOf(C)Ljava/lang/Character;
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
