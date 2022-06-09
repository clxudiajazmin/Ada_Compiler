procedure Main is
   a : Character;
   b : Float := 2.5;
   c : Float := 7.2;
   texto : String;
   begin
    while b < 5.0 loop
        if a = 'c' then
            c := c + 1.0;
            texto := "Adios";
        end if;
        b := b + 0.5;
    end loop;
end Main;