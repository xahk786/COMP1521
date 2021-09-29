# read a line and print its length

main:
    la   $a0, str0       # printf("Enter a line of input: ");
    li   $v0, 4
    syscall

    la   $a0, line
    la   $a1, 256
    li   $v0, 8          # fgets(buffer, 256, stdin)
    syscall              #

    #let $t0 = i
    li	$t0, 0		# $t0 =0 
    j loop
    
loop:
    lb	$t1, line($t0)	#t1 = line[i]
    beq	$t1, 0, end	# if line[i] == 0 then end
    addi $t0, $t0, 1			# i++
    j loop 
        
end:
    la   $a0, str1       # printf("Line length: ");
    li   $v0, 4
    syscall

    #li   $a0, 42         # printf("%d", i);
    move $a0, $t0		# 
    li   $v0, 1
    syscall

    li   $a0, '\n'       # printf("%c", '\n');
    li   $v0, 11
    syscall

    li   $v0, 0          # return 0
    jr   $ra


.data
str0:
    .asciiz "Enter a line of input: "
str1:
    .asciiz "Line length: "


# line of input stored here
line:
    .space 256

