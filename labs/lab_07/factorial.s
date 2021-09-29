# Recursive factorial function
# n < 1 yields n! = 1
# $s0 is used for n
# we use an s register because the convention is their value
# is preserved across function calls
# f is in $t0

# DO NOT CHANGE THE CODE IN MAIN

main:
    addi $sp, $sp, -8  # create stack frame
    sw   $ra, 4($sp)   # save return address
    sw   $s0, 0($sp)   # save $s0

    li   $s0, 0
    la   $a0, msg1
    li   $v0, 4
    syscall            # printf(Enter n: ")

    li    $v0, 5
    syscall            # scanf("%d", &n)
    move  $s0, $v0

    move  $a0, $s0     # factorial(n)
    jal   factorial    #
    move  $t0, $v0     #

    move  $a0, $s0
    li    $v0, 1
    syscall            # printf ("%d", n)

    la    $a0, msg2
    li    $v0, 4
    syscall            # printf("! = ")

    move  $a0, $t0
    li    $v0, 1
    syscall            # printf ("%d", f)

    li   $a0, '\n'     # printf("%c", '\n');
    li   $v0, 11
    syscall

                       # clean up stack frame
    lw   $s0, 0($sp)   # restore $s0
    lw   $ra, 4($sp)   # restore $ra
    addi $sp, $sp, 8   # restore sp

    li  $v0, 0         # return 0
    jr  $ra

    .data
msg1:   .asciiz "Enter n: "
msg2:   .asciiz "! = "


# DO NOT CHANGE CODE ABOVE HERE

    .text
factorial:
    #  ADD CODE TO CREATE STACK FRAME
	addiu	$sp, $sp, -8
	sw	$ra, ($sp)
	sw  $a0, 4($sp) # 
    # ADD CODE FORFUNCTION HERE

    bgt	$a0, 1, do_1	# if n>1 do_1 
    #else end 
    j end 

    do_1:
        addi $a0, $a0, -1 #n = (n-1)
        jal	 factorial				# jump to factorial and save position to $ra
        mul $v0, $v0, $a0
   
    # ADD CODE TO REMOVE STACK FRAME
    end:
        lw	$ra, ($sp)
        lw  $a0, 4($sp) 
        addiu	$sp, $sp, 8
        #lw $s1, 8($sp)
        #v0 = result 
        jr  $ra
