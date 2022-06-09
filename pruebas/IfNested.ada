procedure Main is
   int1: Integer;
   int2: Integer;
begin
   int1:=5;
   int2:=8;
   if int1<int2 then
	   int1:= 5 + 5;
   elsif int1 = int2 then
      int1:= 10 + 5;
   else
      int1:= 7;
   end if;
end Main;