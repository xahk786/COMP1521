main:
    li   $v0, 5         #   scanf("%d", &x);
    syscall             #
    move $t0, $v0

    li		$t1, 0 		# $t0  = 0 (i = 0)

    j		loop				# jump to loop
    
    b		end			# branch to end
    

loop:
    #state the break statement 
    bge		$t1, $t0, end	# if $t1 >= t0 then end (while i < x ) 

    li		$t2, 0 		# $t2  = 0 (j = 0)

    j		loop_2				# jump to loop_2


loop_2:

    bge		$t2, $t0, finalise	# if $t2 >= t1 then finalise (while j < x)
    
    la		$a0, output
    li      $v0, 4
    syscall
    
    addi	$t2, $t2, 1	
    
    j loop_2

finalise:

    addi	$t1, $t1, 1 #(i = i + 1)

     la		$a0, new_line
     li      $v0, 4
     syscall

    j		loop				# jump to loop
    

end:

    li   $v0, 0         # return 0
    jr   $ra

    
    .data

new_line:
    .asciiz "\n"

output:
    .asciiz "*"