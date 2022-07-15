.data
# variables
int1: .word 0
int2: .word 0
# messages

.text
main:
LI $s0, 5
LI $s1, 8
BLT $s0, $s1, Temp_Label
li $v0, 10
syscall
Temp_Label: 
ADDI $s2, $s0, 2
MOVE $s0, $s2
li $v0, 1
add $a0, $zero, $s0
syscall
