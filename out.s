.data
# variables
a: .byte 'c'
b: .float 2.500000
c: .float 7.200000
# messages

.text
main:
LW $s0, a($0)
BNE $s0, 99, Temp_Label
L.D $f0, c
L.D $f0, b
ADD.D $f0, $f0 $f0 
MOV.D $f0, $f0
L.D $f0, b
L.D $f0, c
ADD.D $f2, $f0 $f0 
MOV.D $f0, $f2
