# Read numbers into an array until a negative number is entered
# then print the numbers in reverse order

# i in register $t0
# registers $t1, $t2 & $t3 used to hold temporary results

main:
    li   $t0, 0          # i = 0

loop0:
    bge  $t0, 1000, end0 # while (i < 1000) {

    li   $v0, 5          #   scanf("%d", &numbers[i]);
    syscall              #

    mul  $t1, $t0, 4     #   calculate &numbers[i]
    la   $t2, numbers    #
    add  $t3, $t1, $t2   #
    #sw   $v0, ($t3)      #   store entered number in array

    blt	$v0, $zero, while_final	#if x < 0 go to while_final

    #else do the following 
    sw   $v0, ($t3)
    
   
    addi $t0, $t0, 1     #   i++;
    j    loop0           # }

while_final:
    ble	$t0, $zero, end0	# if i <= 0 END 
    addi $t0, $t0, -1		# i--

    mul  $t1, $t0, 4     #   calculate &numbers[i]
    la   $t2, numbers    #
    add  $t3, $t1, $t2   # 
    lw   $t3, ($t3) # t3 = numbers[i]

    #need to print t3
    move $a0, $t3        # printf("%d", x);
    li   $v0, 1
    syscall

    li   $a0, '\n'       # printf("%c", '\n');
    li   $v0, 11
    syscall

    j while_final

end0:

    li   $v0, 0          # return 0
    jr   $ra              #

.data
numbers:
    .space 4000
