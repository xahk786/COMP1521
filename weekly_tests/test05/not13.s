main:
    li   $v0, 5         #   scanf("%d", &x);
    syscall             #
    move $t0, $v0

    li   $v0, 5         #   scanf("%d", &y);
    syscall             #
    move $t1, $v0

    addi	$t0, $t0, 1			# $t0 = $t1 + 1
    
    b		loop			# branch to loop
    
    b		end			# branch to end


loop:
    bge		$t0, $t1, end	# if $t0 >= $t1endtarget

    beq		$t0, 13, check	# if $t0 =13t1checktarget
    
    move 	$a0, $t0		
    li      $v0, 1
    syscall
    
    la		$a0, new_line
    li      $v0, 4
    syscall
    
    addi	$t0, $t0, 1	

    j		loop				# jump to loop
    
check:
    addi	$t0, $t0, 1
    j		loop

end:

    li   $v0, 0         # return 0
    jr   $ra

    .data

new_line:
    .asciiz "\n"