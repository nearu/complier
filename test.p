program HelloWorld;
type 
	int = integer;
var 
	result:int;

procedure min(num1, num2:integer;var r:integer);
begin
	if (num1 < num2) then r := num1 else r:= num2;
end;

begin	
	min(1,2);
	writeln(result);
end.