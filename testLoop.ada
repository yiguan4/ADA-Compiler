Procedure testLoop is
	I,x: integer;

Begin
	I:=1;
	
	loop
		putline("This loop will end when I=5, because now I=", I);
		I:= I+1;
		exit when I>5;
		putline("Loop continues");
	End loop;
	putline("Loop Ends");

End testLoop;