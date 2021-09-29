#  read numbers until a non-negative number entered
# x in $t0
main:
    la   $a0, str0       # printf("Enter a number: ");
    li   $v0, 4
    syscall

    li   $v0, 5          # scanf("%d", &x);
    syscall              #
    move $t0, $v0

    blt	$t0, $zero, retry	# if$ x < zero then retry
    
    #else do the following 
    la   $a0, str1       # printf("You entered: ");
    li   $v0, 4
    syscall
    move $a0, $t0        # printf("%d", x);
    li   $v0, 1
    syscall
    li   $a0, '\n'       # printf("%c", '\n');
    li   $v0, 11
    syscall
    li   $v0, 0          # return 0
    jr   $ra

retry:
    la   $a0, str_retry  # retry print
    li   $v0, 4
    syscall

    j main

.data
str0:
    .asciiz "Enter a number: "
str1:
    .asciiz "You entered: "
str_retry:
    .asciiz "Enter a positive number\n"
