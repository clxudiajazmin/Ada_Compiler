procedure Numbers is
   Mike, Alice: Integer;
   John_Smith: Integer;
   terra: Float;
begin
   terra := 1.0;
   Mike := 5;
   Alice := 6;
   John_Smith := 3*Mike + 2*Alice + terra;
   Put_Line("3*Mike + 2*Alice + 11 is ");
   Put_Line(John_Smith);
   New_Line;

   John_Smith := Mike + Alice + 1000000;
   Put_Line("A million more than Mike and Alice ");
   Put_Line(John_Smith);
   New_Line;

   F := F + Mike + 3.14159265;
   Put_Line("And F as an integer is ");
   New_Line;
end Numbers;