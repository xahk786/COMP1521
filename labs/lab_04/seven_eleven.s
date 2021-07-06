# Read a number and print positive multiples of 7 or 11 < n

main:                  # int main(void) {

    la   $a0, prompt   # printf("Enter a number: ");
    li   $v0, 4
    syscall

    li   $v0, 5         # scanf("%d", number);
    syscall

    move 	$t0, $v0		# $t0 = v01
    li		$t1, 1		# $t1 = 1
    li		$t2, 7		# $t2 =7 
    li		$t3, 11
    

loop:
    bge		$t1, $t0, end	# if $t1 > t01 endarget

    

    div		$t1, $t2			# $t1 / 7
    mfhi	$t4					# $t4 = $t1 mot2$t1 

    beq		$t4, $zero, print_curr	# if t4 == 0 --> print_curr

    div		$t1, $t3			# $t1 / 11
    mfhi	$t4					# $t4 = $t1 mot2$t1 

    beq		$t4, $zero, print_curr	# if t4 == 0 --> print_curr
    
    addi $t1, $t1, 1
    j		loop				# jump to loop
    
    
print_curr:
    move $a0, $t1     #   printf("%d" i);
    li   $v0, 1
    syscall

    li   $a0, '\n'    # printf("%c", '\n');
    li   $v0, 11
    syscall

    addi $t1, $t1, 1
    b		loop			# branch to loop
    

end:
    jr   $ra           # return

    .data
prompt:
    .asciiz "Enter a number: "
