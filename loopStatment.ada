procedure factorial is

begin
   fact := 1;
   for i in 2..10 loop
      fact := fact * i;
      put_line(integer'image(i) & "! = " & integer'image(fact));
   end loop;
end factorial;