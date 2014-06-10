program HelloWorld;
type 
	int = integer;
	book = record 
		id1 : integer;
		id2 : integer;
		id3 : integer;
		name : integer;
	end;
var 
	b1,b2 : book;
	re : real;
	ar : array[1..10] of book;
	i : integer;
begin	
	b1.id1 := 1;
	ar[1]  := b1;
	re := 1.1;

	re := 2.2 * re;
	writeln(b1.id1);
	writeln(' ');
	writeln(re);
end.