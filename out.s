.data
# variables
A: .word 7
B: .float 4.500000
C: .word 9
D: .float 5.600000
# messages

.text
main:
LW $s0, A($0)
ADDI $s0, $s0, 2
MOVE $s0, $s0
L.D $f0, B
L.D $f0, D
ADD.D $f2, $f0 $f0 
MOV.D $f0, $f2
