program HelloWorld;
type 
	int = integer;
var 
	i : int;
	j : int;
	r : real;
	t : real;
	c : char;
begin	
	i := 1;
	j := 4;
	r := 1.0;
	t := 1.0;
	i := i + 1 + 2 * (j - 1) / 2;
	t := r - t/2.0 + 10.0 + r * 2.0;
	writeln(i);
	writeln(' ');
	writeln(t);
	j := -j + 1;
	writeln(' ');
	writeln(j);
end.