.data
# variables
A: .word 6
B: .float 4.500000
C: .word 10
D: .float 4.500000
letra: .byte 'e'
# messages
msg1: .asciiz "HOLA MUNDO"

.text
main:
ADDI $s0, $s0, 10
MOVE $s0, $s0
li $v0, 1
add $a0, $zero, $s0
syscall
DIV $s1, $s0, 5
MOVE $s0, $s1
li $v0, 1
add $a0, $zero, $s0
syscall
add.s $f4, $f0 $f0 
mov.s $f0, $f4
li $v0, 2
add.s $f12, $f30, $f0
syscall
