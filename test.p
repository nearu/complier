program checkCase;
const 
	c = 'B';
var
   grade: char;
   aa : array [0..4] of char;
begin
   grade := 'A';
   aa[0] := 'B';
   case (a[0]) of
      'A' : writeln('Excellent!' );
      'B' : writeln('Well done' );
      'D' : writeln('You passed' );
      'F' : writeln('Better try again' );
   end;     
   
end.