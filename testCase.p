////////////////////////////////////////////////////
test function
////////////////////////////////////////////////////
program HelloWorld;
type 
	int = integer;
function max(num1, num2 :integer; var xx:char) :integer;
var
	result:int;
function min(num1, num2:integer):integer;
var 
	r : int;
	begin
		min := num2;
	end;
begin
	max := num1;
end;
begin	

end.


program HelloWorld;
type 
	int = integer;
var 
	n1 : int;
	n2 : int;
	n3 : int;
procedure max(num1, num2 :integer);
var
	result:int;
begin
	result := num1;
end;
begin	
	max(n1,n2);
end.


program HelloWorld;
type 
	int = integer;
var 
	n1 : int;
	n2 : int;
	n3 : int;
procedure max(num1, num2 :integer; var n :integer);
var
	result:int;
begin
	n := 1;
end;
begin	
	n1 := -1;
	n2 := -n1+n2;
	max(n1,n2,n3);
end.

////////////////////////////////////////////////////
test binary expr
////////////////////////////////////////////////////


////////////////////////////////////////////////////
test unary expr
////////////////////////////////////////////////////



////////////////////////////////////////////////////
test if stmt
////////////////////////////////////////////////////



////////////////////////////////////////////////////
test while stmt
////////////////////////////////////////////////////
program whileLoop;
var
   a: integer;
begin
   a := 10;
   while  a < 20  do
   begin
      
      a := a + 1;
   end;
end.


////////////////////////////////////////////////////
test for stmt
////////////////////////////////////////////////////
program forLoop;
var
   a: integer;
begin
   for a := 10  to 20 do
   begin
      writeln('value of a: ', a);
   end;
end.


////////////////////////////////////////////////////
test repeat stmt
////////////////////////////////////////////////////




program HelloWorld;
const 
	ccc = 1;
	sub = 'a';
type 
	int = integer;
	book = record 
		id : integer;
		name : char;
	end;

var 
	n1 : int;
	n2 : int;
	n3 : int;
	b : book;
	ar : array[char] of book;
procedure max(num1, num2 :integer; var n :integer);
var
	result:int;
begin
	n := 1;
end;
begin	
	n1 := -1;
	n2 := -n1+n2;
	max(n1,n2,n3);
	b.id := n1;
	ar[0] := b;
end.


////test copy record

program HelloWorld;
const 
	ccc = 1;
	sub = 'a';
type 
	int = integer;
	book = record 
		id : integer;
		id : integer;
		id : integer;
		name : char;
	end;
var 
	b : book;
	ar : array[char] of book;
begin	
	ar[0] := b;
end.
