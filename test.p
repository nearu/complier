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
	i := 1;
	b1.id1 := 1;
	ar[i] := b1;
	b2 := ar[i];
	writeln(b2.id1);
	writeln(' ');
	re := re + re - re * re;
end.