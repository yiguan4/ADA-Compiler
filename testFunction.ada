procedure testFunction is

   function Sumsqr(X, Y: in out Integer) return Integer is
      A:Integer;
   begin
      X := X*X;
      A := X+Y*Y;
      Return A;
   end Sumsqr;


   Procedure print(N:integer) is
   begin
	putline("result is: ", n);
   end print;

   A: Integer;
   B: Integer;

begin
   A:= 2;
   B:=2;

   print(Sumsqr(A,B));

   NewLine;

end testFunction;