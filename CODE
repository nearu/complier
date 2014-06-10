.data
.text
add $fp,$sp,$zero
addi $sp,$sp,-4
addi $sp,$sp,-16
sw $ra, 16($sp)
sw $v0, 12($sp)
sw $fp, 8($sp)
addi $t0,$fp,-4
sw $t0, 4($sp)
addi $t0,$zero,1
sw $t0, 0($sp)
addi $t0,$zero,2
sw $t0, -4($sp)
addi $fp,$sp,0
jal min
lw $ra, 16($sp)
lw $v0, 12($sp)
lw $fp, 8($sp)
addi $sp,$sp,16
lw $a0, 0($fp)
addi $v0, $zero, 1
syscall
addi $sp,$sp,4
j exit
min:
addi $sp,$sp,-12
lw $t0, 0($fp)
lw $t1, -4($fp)
slt $t2,$t0,$t1
beq $t2,$zero,endif0
lw $t1, 0($fp)
lw $t4, 8($fp)
sw $t1, 0($t4)
endif0:
addi $sp,$sp,12
jr $ra
exit:
