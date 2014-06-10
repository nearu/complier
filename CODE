.data
string1: .asciiz " "
real1: .float  1.0
real3: .float  10.0
real4: .float  2.0
.text
add $fp,$sp,$zero
addi $sp,$sp,-17
addi $t0,$zero,1
sw $t0, 0($fp)
addi $t1,$zero,4
sw $t1, -4($fp)
la $t2 real1
l.s $f6, 0($t2)
s.s $f6, -8($fp)
la $t2 real1
l.s $f6, 0($t2)
s.s $f6, -12($fp)
lw $t3, -4($fp)
addi $t2,$t3,-1
addi $t5,$zero,2
mul $t3,$t2,$t5
addi $t5,$zero,2
div $t2,$t3,$t5
lw $t4, 0($fp)
addi $t3,$t4,1
add $t4,$t2,$t3
sw $t4, 0($fp)
la $t2 real4
l.s $f6, 0($t2)
l.s $f8, -8($fp)
mul.s $f9,$f8,$f6
la $t2 real3
l.s $f6, 0($t2)
la $t2 real4
l.s $f8, 0($t2)
l.s $f10, -12($fp)
div.s $f11,$f10,$f8
l.s $f8, -8($fp)
sub.s $f10,$f8,$f11
add.s $f8,$f6,$f10
add.s $f6,$f9,$f8
s.s $f6, -12($fp)
lw $a0, 0($fp)
addi $v0, $zero, 1
syscall
la $t2 string1
add $a0,$t2,$zero
addi $v0, $zero, 4
syscall
l.s $f12, -12($fp)
addi $v0, $zero, 2
syscall
lw $t2, -4($fp)
sub $t2,$zero,$t2
addi $t3,$t2,1
sw $t3, -4($fp)
la $t2 string1
add $a0,$t2,$zero
addi $v0, $zero, 4
syscall
lw $a0, -4($fp)
addi $v0, $zero, 1
syscall
addi $sp,$sp,17
j exit
exit:
