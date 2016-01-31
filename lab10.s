#This is a program that adds up an array
	.data
Z:	 .word -4,60,-12,45,-2,-10,5,0
sumZ:	 .word 0

	.text
	.globl main
main:

	la $t0, Z
keepo:
	lw $t1, 0($t0)
	beq $t1, $0, end
	#code that gets absolute value
	move $t2, $t1		#copy t1 into t2
	slt $t3, $t1, $zero		#is it >0
	beq $t3, $zero, kappa		#if >0 then it skips
	sub $t2, $zero, $t1		#t2 = 0 - t1
kappa:	 add $t4, $t2, $t1	#get the total
	addi $t0, $t0, 1	#get the next memory address
	j keepo	#jump bnack to the start and get next word
end:
	sw $t4, sumZ	#store the sum into the data for the system to use
	syscall