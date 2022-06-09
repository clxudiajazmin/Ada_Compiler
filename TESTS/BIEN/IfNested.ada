procedure test is
   a, b : Integer;      
   c : Float := 2.3;     

begin
   if a = b then
      a := 2;
      c := 9.3;
   elsif c = 5.2 then
      a := b;
   elsif b < a then
      b := 6;
   else
      b := 8;
   end if;
end test;