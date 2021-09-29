# Read 10 numbers into an array
# print 0 if they are in non-decreasing order
# print 1 otherwise

# i in register $t0

main:

    li   $t0, 0         # i = 0
loop0:
    bge  $t0, 10, end0  # while (i < 10) {

    li   $v0, 5         #   scanf("%d", &numbers[i]);
    syscall             #

    mul  $t1, $t0, 4    #   calculate &numbers[i]
    la   $t2, numbers   #
    add  $t3, $t1, $t2  #
    sw   $v0, ($t3)     #   store entered number in array

    addi $t0, $t0, 1    #   i++;
    j    loop0          # }
end0:


    # PUT YOUR CODE HERE
    #return = 0 
    li   $t4, 0         # i = 0
    li   $t0, 1         # i = 1
    
    j		loop1				# jump to loop1
    

loop1:
    #while i < 10
    bge		$t0, 10, execute	# if $t0 >= $t1 then execute

    #let t4 be x, t5 be y
    #x = numbers[i]
    mul  $t1, $t0, 4    #   calculate &numbers[i]
    la   $t2, numbers   #
    add  $t3, $t1, $t2  #
    lw   $t4, ($t3)     #   load numbers[i] into $at4

    #y = numbers[i-1]
    sub  $t3, $t3, 4    #   calculate &numbers[i]
    lw   $t5, ($t3)     #   load numbers[i] into $a0

    blt		$t4, $t5, execute_2	# if $t4 < $5 do_stuffarget

    addi $t0, $t0, 1    #   i++;
    j    loop1 

execute_2:
    
    li   $a0, 1        # printf("%d", 42)
    li   $v0, 1         #
    syscall

    li   $a0, '\n'      # printf("%c", '\n');
    li   $v0, 11
    syscall

    jr   $ra

execute:
    
    li   $a0, 0        # printf("%d", 42)
    li   $v0, 1         #
    syscall

    li   $a0, '\n'      # printf("%c", '\n');
    li   $v0, 11
    syscall

    jr   $ra

.data

numbers:
    .word 0 0 0 0 0 0 0 0 0 0  # int numbers[10] = {0};


