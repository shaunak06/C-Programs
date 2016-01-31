#This is a program that looks at numbers and sees if they are divisible by 4
	.data
num:	 .word 5,4,8,12,13,16,18,20,24,23,0	#data set
print1:	 .asciiz "\nThe number of values that are divisible by 4 = "	#first line with the number of factoirs of 4 displayed
print2:	 .asciiz "\nThe number of 1's in the binary number = "		#second line with the binary number

	.text
	.globl main
main:
	la $t0, num	#load the address of the array
	move $t2,$0	#make contents 0
kappa:
	lw $t1, ($t0)	#load the number from the array
	beq $t1, $0, keepo	#if the number is zero it exits the loop
	andi $t3, $t1, 3	#get only the last 3 bits of the number
	ori $t4, $t3, 3	#see if the number is divisble by 4
	bne $t4, $0, kappapride	#if the result of the or is not 0 it jumps to the
	addi $t2,$t2,1	#increment next element
kappapride:
	addi $t0, $t0, 4	#advance array pointer

	j kappa	#go back to the top of the array

keepo:
	#code that prints out the first line
	li $v0, 4
	la $a0, print1
	syscall
	#code that prints the number of numbers divisible by 4
	li $v0, 1
	move $a0, $t2
	syscall
	#prints the second print statement
	li $v0, 4
	la $a0, print2
	syscall
	#code that prints out the number of 1s in the binary number

	#
	li $v0, 10
	syscall
	