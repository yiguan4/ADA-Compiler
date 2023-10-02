procedure testProcedure is

   procedure Swap (A, B : in out Integer) is
      Tmp : Integer;
   begin
      Tmp := A;
      A := B;
      B := Tmp;
      PutLine (A);
      PutLine (B);
   end Swap;

   A : Integer;
   B : Integer;

begin
    A:=12;
    B:=44;
    PutLine("Before swap: ");
    PutLine (A);
    PutLine (B);
    PutLine("After swap: ");
    Swap (A, B);
    

end testProcedure;

