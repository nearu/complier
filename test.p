program HelloWorld;
var 
	i,j : integer;
begin
	i := 1;
	case i+1 of
		0: begin j:=0; end;
		1: begin j:=1; end;
		2: begin j:=2; end;
	end;

end.