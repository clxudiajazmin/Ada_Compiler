procedure Main is
   int1: Integer;
   int2: Integer;
begin
   int1:= 5;
   int2:= 8;
   if int1 > int2 then
	   int1 := int1 + 5;
      Put_Line(int1);
   end if;
end Main;