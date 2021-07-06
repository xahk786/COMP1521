# Read a number n and print the first n tetrahedral numbers
# https://en.wikipedia.org/wiki/Tetrahedral_number

main:                  # int main(void) {

    la   $a0, prompt   # printf("Enter how many: ");
    li   $v0, 4
    syscall

    li   $v0, 5         # scanf("%d", number);
    syscall

    move 	$t0, $v0		# $t0 (how many) = v01
    li		$t1, 1		# $t1 (n) =1 
    

loop:
    bgt		$t1, $t0, end	# if $t1 > $01 then target
    
    li		$t2, 0		# $t2 (total) = 0 
    li		$t3, 1		# $t3 (j) =1
    
    b		loop_2			# branch to loop_2
    #addi	$t1, $t1, 1
    #j		loop				# jump to loop
    

loop_2:
    bgt		$t3, $t1, output	# if $t3 > $t1 then target
    
    li		$t4, 1 		# $t4 (i) = 1
    
    b		loop_3			# branch to loop_3
    
    #addi	$t3, $t3, 1

    #j		loop_2				# jump to loop_2
    
loop_3:
    bgt		$t4, $t3, exit_leave	# if $t4 > $31 then target
    
    add 	$t2, $t2, $t4			# 2t0 =2$t1 + 0
    addi	$t4, $t4, 1
    
    j		loop_3				# jump to loop_3
    

exit_leave:
    addi	$t3, $t3, 1
    j loop_2

output:
    move $a0, $t2     #   printf("%d" total);
    li   $v0, 1
    syscall

    li   $a0, '\n'    # printf("%c", '\n');
    li   $v0, 11
    syscall
    
    addi	$t1, $t1, 1
    j loop

end:
    jr   $ra           # return

    .data
prompt:
    .asciiz "Enter how many: "
