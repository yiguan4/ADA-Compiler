procedure testWhile is
   I : Integer;
begin
   I := 1;
   while I <= 5 loop
      PutLine ("Hello, World! ", I);
      I := I + 1;
   end loop;

end testWhile;