/////////////////////
test expression
/////////////////////
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


/////////////////////
test if then else + function call + nested function
/////////////////////
program HelloWorld;
type 
	int = integer;
var 
	outReal : real;
	result : int;
function max(num1, num2 :integer) :integer;

function min(num1, num2:integer):integer;
var 
	r : int;
	begin
		outReal := 10.0;
		if (num1 < num2) then min := num1
		else min := num2;
	end;
begin
	result := min(2,1);
	
end;
begin	
	max(1,2);
	writeln(outReal);
	writeln(result);
end.

/////////////////////
test while
/////////////////////
program HelloWorld;
type 
	int = integer;
var 
	s : int;
	result:int;
begin	
	s := 0;
	result := 0;
	while s < 100 do
	begin 
		result := result + s;
		s := s + 1;
	end;
	writeln(result);
end.

/////////////////////
test repeat
/////////////////////

program HelloWorld;
type 
	int = integer;
var 
	s : int;
	result:int;
begin	
	s := 0;
	result := 0;
	repeat
		result := result + s;
		s := s + 1;
	until s >= 100;
	writeln(result);
end.

/////////////////////
test for
/////////////////////
program HelloWorld;
type 
	int = integer;
var 
	s : int;
	result:int;
begin	
	s := 0;
	result := 0;
	for s:=0 to 100 do
	begin
		result := result + s;
	end;
	writeln(result);
end.

/////////////////////
test switch
/////////////////////
program checkCase;
var
   grade: char;
begin
   grade := 'A';

   case (grade) of
      'A' : writeln('Excellent!' );
      'B' : writeln('Well done' );
      'D' : writeln('You passed' );
      'F' : writeln('Better try again' );
   end;     
   
end.
/////////////////////
test copy record
/////////////////////
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
	ar[1] := b1;
	re := 1.1;

	re := 2.2 * re;
	writeln(b1.id1);
	writeln(' ');
	writeln(re);
end.
/////////////////////
test recursive
/////////////////////

program HelloWorld;
procedure outbinary(n : integer);
begin
	if (n / 2 > 0) then outbinary(n/2);
	writeln(n % 2);
end;
begin
	outbinary(100);
end.

/////////////////////
test type check
/////////////////////
program HelloWorld;
var 
	i : integer;
	j : char;
	k : array[1..20] of char;
function ff(h : real) : char;
begin
end;
begin
	
	i := ff(i);
	cc;
	k[i] := k;
	i := j;
end.