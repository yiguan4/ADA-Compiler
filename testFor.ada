procedure testFor is
   a: array(1..5) of Integer;   
   i,j: Integer;
   ch: character;
begin
 
   for i in 1..5 loop
      putLine("I = " , i);
   end loop;

   for j in reverse 1..5 loop
      putLine("j = " , j);
   end loop;

   for ch in 'a'..'m' loop
      putLine("ch = " , ch);
   end loop;
 
end testFor;