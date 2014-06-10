.data
real0: .float  10.0
.text
add $fp,$sp,$zero
addi $sp,$sp,-8
addi $sp,$sp,-16
sw $ra, 16($sp)
sw $v1, 12($sp)
sw $fp, 8($sp)
addi $t0,$fp,4
sw $t0, 4($sp)
addi $t0,$zero,1
sw $t0, 0($sp)
addi $t0,$zero,2
sw $t0, -4($sp)
addi $fp,$sp,0
jal max
lw $ra, 16($sp)
lw $v0, 12($sp)
lw $fp, 8($sp)
addi $sp,$sp,16
l.s $f12, 0($fp)
addi $v0, $zero, 2
syscall
lw $a0, -4($fp)
addi $v0, $zero, 1
syscall
addi $sp,$sp,8
j exit
max:
addi $sp,$sp,-8
addi $sp,$sp,-16
sw $ra, 16($sp)
sw $v1, 12($sp)
sw $fp, 8($sp)
addi $t0,$fp,4
sw $t0, 4($sp)
addi $t0,$zero,2
sw $t0, 0($sp)
addi $t0,$zero,1
sw $t0, -4($sp)
addi $fp,$sp,0
jal min
add $t0,$v1,$zero
lw $ra, 16($sp)
lw $v0, 12($sp)
lw $fp, 8($sp)
addi $sp,$sp,16
lw $t1, 4($fp)
addi $t1,$t1,-4
sw $t0, -4($t1)
addi $sp,$sp,8
jr $ra
min:
addi $sp,$sp,-12
la $t0 real0
l.s $f6, 0($t0)
lw $t0, 4($fp)
lw $t0, 0($t0)
addi $t0,$t0,-4
s.s $f6, 0($t0)
lw $t2, 0($fp)
lw $t3, -4($fp)
slt $t4,$t2,$t3
beq $t4,$zero,endif0
lw $t2, 0($fp)
add $v1,$t2,$zero
j endelse0
endif0:
lw $t2, -4($fp)
add $v1,$t2,$zero
endelse0:
addi $sp,$sp,12
jr $ra
exit:
