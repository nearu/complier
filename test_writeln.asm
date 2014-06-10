.data
string0: .asciiz "a"
.text
add $fp,$sp,$zero
addi $sp,$sp,-20
la $t0 string0
lb $t1, 0($t0)
sb $t1, -19($fp)
lb $a0, -19($fp)
addi $v0, $zero, 11
syscall
addi $sp,$sp,20
j exit
exit:
