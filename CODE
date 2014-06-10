.data
.text
add $fp,$sp,$zero
addi $sp,$sp,-8
addi $t0,$zero,0
sw $t0, 0($fp)
addi $t1,$zero,0
sw $t1, -4($fp)
do0:
lw $t2, -4($fp)
lw $t3, 0($fp)
add $t4,$t2,$t3
sw $t4, -4($fp)
lw $t3, 0($fp)
addi $t2,$t3,1
sw $t2, 0($fp)
lw $t3, 0($fp)
slti $t4,$t3,100
xori $t2,$t4,1
beq $t2,$zero,do0
lw $a0, -4($fp)
addi $v0, $zero, 1
syscall
addi $sp,$sp,8
j exit
exit:
