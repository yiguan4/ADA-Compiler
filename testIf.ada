Procedure testIf is
	i,j,x,grade:Integer;
	ch: character;
begin
	i:=1;
	j:=2;
	grade := 75;

	if i<j then x:=-3;
	elsif i>j then x:=10;
	else x:=0;
	end if;

	putline("x = ",x);
	

	if grade >= 90 then ch:= 'A';
	elsif grade >= 80 then ch:= 'B';
	elsif grade >= 70 then ch:= 'C';
	elsif grade >= 60 then ch:= 'D';
	else ch:='F';
	end if;

	putline("Your grade is: ", ch);
	
End testIf;