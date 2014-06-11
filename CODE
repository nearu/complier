.data
.text
add $fp,$sp,$zero
addi $sp,$sp,-4
addi $sp,$sp,-16
sw $ra, 16($sp)
sw $v1, 12($sp)
sw $fp, 8($sp)
addi $t0,$fp,4
sw $t0, 4($sp)
addi $t0,$zero,4
sw $t0, 0($sp)
addi $fp,$sp,0
jal A1
lw $ra, 16($sp)
lw $v0, 12($sp)
lw $fp, 8($sp)
addi $sp,$sp,16
lw $a0, 0($fp)
addi $v0, $zero, 1
syscall
addi $sp,$sp,4
j exit
A2:
addi $sp,$sp,-8
addi $sp,$sp,-16
sw $ra, 16($sp)
sw $v1, 12($sp)
sw $fp, 8($sp)
addi $t0,$fp,4
sw $t0, 4($sp)
addi $t0,$zero,3
sw $t0, 0($sp)
addi $fp,$sp,0
jal B2
lw $ra, 16($sp)
lw $v0, 12($sp)
lw $fp, 8($sp)
addi $sp,$sp,16
lw $a0, -4($fp)
addi $v0, $zero, 1
syscall
addi $sp,$sp,8
jr $ra
B2:
addi $sp,$sp,-4
addi $t0,$zero,123
lw $t2, 4($fp)
lw $t2, 0($t2)
addi $t2,$t2,-4
sw $t0, 0($t2)
addi $t1,$zero,321
lw $t4, 4($fp)
addi $t4,$t4,-4
sw $t1, -4($t4)
addi $sp,$sp,4
jr $ra
A1:
addi $sp,$sp,-4
addi $sp,$sp,-16
sw $ra, 16($sp)
sw $v1, 12($sp)
sw $fp, 8($sp)
addi $t3,$fp,4
sw $t3, 4($sp)
addi $t3,$zero,3
sw $t3, 0($sp)
addi $fp,$sp,0
jal B1
lw $ra, 16($sp)
lw $v0, 12($sp)
lw $fp, 8($sp)
addi $sp,$sp,16
addi $sp,$sp,4
jr $ra
B1:
addi $sp,$sp,-4
addi $sp,$sp,-16
sw $ra, 16($sp)
sw $v1, 12($sp)
sw $fp, 8($sp)
lw $t3, 4($fp)
lw $t3, 0($t3)
sw $t3, 4($sp)
addi $t3,$zero,3
sw $t3, 0($sp)
addi $fp,$sp,0
jal A2
lw $ra, 16($sp)
lw $v0, 12($sp)
lw $fp, 8($sp)
addi $sp,$sp,16
addi $sp,$sp,4
jr $ra
exit:
