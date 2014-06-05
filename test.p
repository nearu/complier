program HelloWorld;
type 
	r = record 
		f : char;
		end;
	ar = array [char] of char;
var 
	a : array [1..29] of char;
	v : record 
		d : integer;
	end;
begin
	a[0] := a[1];
	v.d := a[1];
end.