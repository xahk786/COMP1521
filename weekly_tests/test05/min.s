#  print the minimum of two integers
main:
    li   $v0, 5         #   scanf("%d", &x);
    syscall             #
    move $t0, $v0

    li   $v0, 5         #   scanf("%d", &y);
    syscall             #
    move $t1, $v0


    blt		$t0, $t1, goto	# if $t0 < $t1 gotoarget
    
    move 	$a0, $t1		
    li      $v0, 1
    syscall

    b end

goto:

    move 	$a0, $t0		
    li      $v0, 1
    syscall

    b end

end:

    la		$a0, new_line
    li      $v0, 4
    syscall
    
    li   $v0, 0         # return 0
    jr   $ra

    .data

new_line:
    .asciiz "\n"