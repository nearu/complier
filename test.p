program HelloWorld;
type 
	int = integer;
var 
	s : int;
	result:int;

procedure min(num1, num2:integer;var r:integer);
begin
	if (num1 < num2) then r := num1 else r:= num2;
end;

begin	
	s := 0;
	result := 0;
	for s:=0 to 100 do
	begin
		result := result + s;
	end;
	writeln(result);
end.