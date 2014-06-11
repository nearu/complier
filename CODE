.data
string3: .asciiz "A"
string5: .asciiz "B"
string10: .asciiz "Better try again"
string7: .asciiz "D"
string4: .asciiz "Excellent!"
string9: .asciiz "F"
string6: .asciiz "Well done"
string8: .asciiz "You passed"
.text
add $fp,$sp,$zero
addi $sp,$sp,-9
la $t0 string5
sw $t0, 0($fp)
la $t0 string3
lb $t1, 0($t0)
sb $t1, -4($fp)
la $t0 string5
lb $t2, 0($t0)
sb $t2, -5($fp)
lb $t0, -5($fp)
la $t3 string3
lb $t3, 0($t3)
bne $t3,$t0,nextcase0
la $t3 string4
add $a0,$t3,$zero
addi $v0, $zero, 4
syscall
nextcase0:
la $t3 string5
lb $t3, 0($t3)
bne $t3,$t0,nextcase1
la $t3 string6
add $a0,$t3,$zero
addi $v0, $zero, 4
syscall
nextcase1:
la $t3 string7
lb $t3, 0($t3)
bne $t3,$t0,nextcase2
la $t3 string8
add $a0,$t3,$zero
addi $v0, $zero, 4
syscall
nextcase2:
la $t3 string9
lb $t3, 0($t3)
bne $t3,$t0,nextcase3
la $t3 string10
add $a0,$t3,$zero
addi $v0, $zero, 4
syscall
nextcase3:
addi $sp,$sp,9
j exit
exit:
