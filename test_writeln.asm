.data
.text
add $fp,$sp,$zero
addi $sp,$sp,-8
addi $t0,$zero,0
sw $t0, 0($fp)
addi $t1,$zero,0
sw $t1, -4($fp)
addi $t2,$zero,0
sw $t2, 0($fp)
loop0:
lw $t4, 0($fp)
addi $t3,$zero,0
addi $t5,$zero,100
beq $t4,$t5,4
addi $t3,$zero,-1
addi $t3,$t3,1
bne $t3,$zero,break0
lw $t4, -4($fp)
lw $t5, 0($fp)
add $t6,$t4,$t5
sw $t6, -4($fp)
addi $t2,$t2,1
j loop0
break0:
lw $a0, -4($fp)
addi $v0, $zero, 1
syscall
addi $sp,$sp,8
j exit
exit:
