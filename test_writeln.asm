.data
string0: .asciiz " "
.text
add $fp,$sp,$zero
addi $sp,$sp,-184
addi $t0,$zero,1
sw $t0, -180($fp)
addi $t1,$zero,1
sw $t1, -12($fp)
lw $t2, -180($fp)
addi $t3,$zero,16
mul $t4,$t2,$t3
addi $t4,$t4,36
add $s0,$fp,$zero
add $s1,$fp,$zero
addi $s0,$s0,0
add $s1,$s1,$t4
add $t6,$zero,$zero
copy1:
lw $t7, 0($s0)
sw $t7, 0($s1)
addi $s0,$s0,-4
addi $s1,$s1,-4
addi $t6,$t6,1
slti $s2,$t6,4
bne $s2,$zero,copy1
lw $t2, -180($fp)
addi $t3,$zero,16
mul $t6,$t2,$t3
addi $t6,$t6,36
add $s2,$fp,$zero
add $s3,$fp,$zero
add $s2,$s2,$t6
addi $s3,$s3,-16
add $s0,$zero,$zero
copy2:
lw $s1, 0($s2)
sw $s1, 0($s3)
addi $s2,$s2,-4
addi $s3,$s3,-4
addi $s0,$s0,1
slti $s4,$s0,4
bne $s4,$zero,copy2
lw $a0, -28($fp)
addi $v0, $zero, 1
syscall
la $t2 string0
add $a0,$t2,$zero
addi $v0, $zero, 4
syscall
addi $sp,$sp,184
j exit
exit:
