.data
# variables
int1: .word 0
# messages

.text
main:
LI $s0, 5
BLT $s0, 8, Temp_Label
li $v0, 10
syscall
Temp_Label: 
ADDI $s1, $s0, 5
MOVE $s0, $s1
li $v0, 1
add $a0, $zero, $s1
syscall