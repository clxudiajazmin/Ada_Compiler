procedure Main is
   A : Integer;
   B: Integer;
begin
   A := 5;
   B := 20;
   while A <= 10 loop
      A := A + 2;
      Put_Line(A);
      B := B - 2;
      Put_Line(B);
   end loop;
end Main;