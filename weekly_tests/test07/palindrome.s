# read a line and print whether it is a palindrom

main:
    la   $a0, str0              # printf("Enter a line of input: ");
    li   $v0, 4
    syscall

    la   $a0, line
    la   $a1, 256
    li   $v0, 8                 # fgets(buffer, 256, stdin)
    syscall                     #

    #let i = 0
    li $t0, 0                   # int i = 0;
    j loop

loop:
    lb $t3, line($t0)
    beq $t3, 0, next            # while (line[i] != 0) {
    add $t0, $t0, 1             #   i++;
    j loop                      # }
    
next:
    #let $t4 = j, $t5 = k
    li $t4, 0                   # int j = 0;
    addi $t5, $t0, -2           # int k = i - 2;
    j loop_next

loop_next:
    bge $t4, $t5, yes         # if j>=k then break loop
    
    lb	$t3, line($t4)		# 
    
    lb	$t6, line($t5)		# 
    
    bne	$t3, $t6, no	# if (line[j] != line[k]) then no

    #else 
    addi $t4, $t4, 1             #   j++
    addi $t5, $t5, -1             #   k--
    j loop_next                    
    
yes: 

    la   $a0, palindrome        # printf("palindrome\n");
    li   $v0, 4
    syscall
    
    li   $v0, 0                 # return 0
    jr   $31

no:
    la   $a0, not_palindrome        # printf("palindrome\n");
    li   $v0, 4
    syscall
    
    li   $v0, 0                 # return 0
    jr   $31


.data
str0:
    .asciiz "Enter a line of input: "
palindrome:
    .asciiz "palindrome\n"
not_palindrome:
    .asciiz "not palindrome\n"


# line of input stored here
line:
    .space 256
