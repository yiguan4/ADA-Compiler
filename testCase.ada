procedure testCase is
   i,j: integer;
   Ch : character;
   Str: string;
             
begin
   i:=3;
   Ch:='b';
      case I+1 is
         when 1      	=> j:=i;
         when -8        => j:=8*i;
         when 5|7|4     => j:=574*i;
      end case;
   putline("j = ", j);

   case ch is
	when 'c'|'b' => str:="p";
	when 'a'     => str:="q";
   end case;
   putline("str = ", str);

end testCase;