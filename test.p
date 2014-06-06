program HelloWorld;
type 
	re = record 
			c : char;
			d : integer;
		end;
var 
	t : re;
begin	
	t.c := t.d + t.c + 1; 
end.