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
<<<<<<< HEAD
	end;
begin
	a[0] := a[1];
	v.d := a[1];
=======
		end;
	d,b,c : integer;
begin	
	while d <= 1 do 
		while b <= 1 do
			begin
				c := c+1;
			end;
>>>>>>> e0dcad631a5dcf08dd7f1db52fd0a02a8e94a760
end.