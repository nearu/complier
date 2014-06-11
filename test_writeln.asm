.data
.text
add $fp,$sp,$zero
addi $sp,$sp,-16
sw $ra, 16($sp)
sw $v1, 12($sp)
sw $fp, 8($sp)
addi $t0,$fp,4
sw $t0, 4($sp)
addi $t0,$zero,100
sw $t0, 0($sp)
addi $fp,$sp,0
jal outbinary
lw $ra, 16($sp)
lw $v0, 12($sp)
lw $fp, 8($sp)
addi $sp,$sp,16
j exit
outbinary:
addi $sp,$sp,-4
lw $t1, 0($fp)
addi $t2,$zero,2
div $t0,$t1,$t2
addi $t3,$zero,0
slt $t1,$t3,$t0
beq $t1,$zero,endif0
addi $sp,$sp,-16
sw $ra, 16($sp)
sw $v1, 12($sp)
sw $fp, 8($sp)
addi $t0,$fp,4
sw $t0, 4($sp)
lw $t3, 0($fp)
addi $t4,$zero,2
div $t2,$t3,$t4
sw $t2, 0($sp)
addi $fp,$sp,0
jal outbinary
lw $ra, 16($sp)
lw $v0, 12($sp)
lw $fp, 8($sp)
addi $sp,$sp,16
endif0:
lw $t1, 0($fp)
addi $t3,$zero,2
rem $t0,$t1,$t3
add $a0,$t0,$zero
addi $v0, $zero, 1
syscall
addi $sp,$sp,4
jr $ra
exit:
