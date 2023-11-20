  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #
  # timetemplate.asm
  # Written 2015 by F Lundevall
  # Copyright abandonded - this file is in the public domain.
 
	.data
	.align 2
mytime:	.word 0x5957
timstr:	.ascii "text more text lots of text\0"
	.text
main:
	# print timstr
	la	$a0,timstr
	li	$v0,4
	syscall
	nop
	# wait a little
	li	$a0,3
	jal	delay
	nop
	# call tick
	la	$a0,mytime
	jal	tick
	nop
	# call your function time2string
	la	$a0,timstr
	la	$t0,mytime
	lw	$a1,0($t0)
	jal	time2string
	nop
	# print a newline
	li	$a0,10
	li	$v0,11
	syscall
	nop
	# go back and do it all again
	j	main
	nop
# tick: update time pointed to by $a0
tick:	lw	$t0,0($a0)	# get time
	addiu	$t0,$t0,1	# increase
	andi	$t1,$t0,0xf	# check lowest digit
	sltiu	$t2,$t1,0xa	# if digit < a, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0x6	# adjust lowest digit
	andi	$t1,$t0,0xf0	# check next digit
	sltiu	$t2,$t1,0x60	# if digit < 6, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0xa0	# adjust digit
	andi	$t1,$t0,0xf00	# check minute digit
	sltiu	$t2,$t1,0xa00	# if digit < a, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0x600	# adjust digit
	andi	$t1,$t0,0xf000	# check last digit
	sltiu	$t2,$t1,0x6000	# if digit < 6, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0xa000	# adjust last digit
tiend:	sw	$t0,0($a0)	# save updated result
	jr	$ra		# return
	nop

  # you can write your code for subroutine "hexasc" below this line
  #

hexasc:	

	slti 	$t0,$a0,10	# check if value is greater than 10 or not
	
	beq	$t0,0,letters	# branches to letters if the given value is >10
	nop			# delay slot filler
	
	addi	$v0,$a0,0x30	# adds 0x30 to given value to match correct ascii character for 1-9

	jr 	$ra		# return
	nop			# delay slot filler
	
letters:
	addi	$v0,$a0,0x37	# adds 0x37 to given value to match correct ascii character for 10-15
	
	jr 	$ra		# return
	nop			# delay slot filler
	



.globl time2string
time2string:
	PUSH	$s0
	PUSH	$s1
	PUSH	$s2
	PUSH	$s3
	PUSH	$gp
	PUSH	$sp
	PUSH	$fp
	PUSH	$ra
	
	addi 	$t0, $0, 0x3a	# sets $t0 to contain a ":" in ascii
	sb 	$t0, 2($a0)	# stores the ":" in the array on the third position, between minutes and seconds 
	sb 	$0, 5($a0)	# stores null byte in 6th position of the array, ending the string

	add	$s3, $0, $0	# sets $s3 to contain 0, this is later set to 1 in order to exit function
	add	$s2, $a0, $0	# saves base adress of the array to $s2 
	
	srl	$s0, $a1, 8	# saves minutes byte to $s0
	add 	$s1, $a1, $0	# saves seconds byte to $s1

	j 	time2repeat
	nop

prepare2repeat:
	add	$s0, $s1, $0	# switch to placing seconds into arrray
	
	andi	$s0, $s0, 0x000000FF	# clean bits for DING comparison
	beq	$s0, $0, dingdong 	# checks if it is time to DING
	nop				# delay slot filler
	
	addi	$s2, $s2, 3	# add 3 to base adress to place seconds in appropriate place
	addi	$s3, $0, 1	# will exit on next run
	j	time2repeat
	nop			# delay slot filler
	
dingdong: 
	addi	$t0, $0, 0x44	# code here places the word DING into array instead of digits
	sb	$t0, ($s2)
	addi	$t0, $0, 0x49
	sb	$t0, 1($s2)		
	addi	$t0, $0, 0x4e
	sb	$t0, 2($s2)
	addi	$t0, $0, 0x47
	sb	$t0, 3($s2)
	sb	$0, 4($s2)	# Stores null
	j	dingexit
	nop			# delay slot filler
												
time2repeat:	
	srl 	$a0, $s0, 4	# shift leftmost nibble to LSB
	andi	$a0, $a0, 0xf	# mask before sending byte to be converted to character
	jal 	hexasc
	nop			# delay slot filler
		
	sb	$v0, ($s2)	# places leftmost nibble to appropriate place in array
	
	andi	$a0, $s0, 0xf	# mask to keep rightmost nibble
	jal	hexasc
	nop			# delay slot filler
	
	sb	$v0, 1($s2)	# places rightmost nibble to appropriate place in array

	bne	$s3, 1, prepare2repeat
	nop	
	
dingexit:	

	POP	$ra	
	POP	$fp
	POP	$sp
	POP	$gp
	POP	$s3
	POP	$s2
	POP	$s1
	POP	$s0
	
	jr	$ra		#exit time2string function
	nop
	
	
.globl delay
delay:
	#a0 = int ms
	addi $t1, $0, 4711		# 4711, forLoop. CHANGE THIS REGISTER
	
	whileLoop:
	sgt $t0, $a0, $0
	beq $t0, $0, doneWhileLoop	# om $a0 < 0, break
	nop
	addi $a0, $a0, -1		# ms = ms - 1

	add $t2, $0, $0		# i = 0
		forLoop:
			slt $t3, $t2, $t1
			beq $t3, $0, doneForLoop	# if (i > 4711), break
			nop
			addi $t2, $t2, 1		# i = i + 1
			j forLoop
			nop
			
	doneForLoop:
		j whileLoop		# Iterate whileLoop again
		nop
	doneWhileLoop:
		jr $ra			# return to caller	
		nop
		
.global enable_interrupt	
enable_interrupt:
		ei		# enables global interrupts
		jr $ra
		nop
		