.data
# variables
A: .word 0
B: .word 0
# messages

.text
main:
LI $s0, 5
LI $s1, 20
DIV $s2, $s1, 2
MOVE $s1, $s2
li $v0, 1
add $a0, $zero, $s1
syscall
while:
BGE $s0, $s1, Temp_Label
ADDI $s3, $s0, 2
MOVE $s0, $s3
li $v0, 1
add $a0, $zero, $s0
syscall
j while
Temp_Label: 
li $v0, 10
syscall
