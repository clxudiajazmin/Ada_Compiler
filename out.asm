.data
# variables
A: .word 6
B: .float 4.500000
C: .word 9
D: .float 5.600000
letra: .byte 'e'
# messages
msg1: .asciiz "Compiladores"

.text
main:
LW $s0, A($0)
ADDI $s0, $s0, 2
MOVE $s0, $s0
lwc1 $f0, B
lwc1 $f0, D
add.s $f2, $f0 $f0 
mov.s $f0, $f2
