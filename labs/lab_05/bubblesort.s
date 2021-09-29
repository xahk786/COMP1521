# read 10 numbers into an array
# bubblesort them
# then print the 10 numbers

# i in register $t0
# registers $t1, $t2 & $t3 used to hold temporary results

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
    li   $t4, 0         # swap = 0   
    li   $t0, 1         # i = 1
    j		loop_todo				# jump to loop_todo

check:
    #if swap is 0 then enter print loop 
    beq		$t4, 0, finalise	# if $t4 == 0 then target

    j		end0				# jump to end0
    
finalise:
    li   $t0, 0         # i = 1
    j loop1

loop_todo:
    #let t5, t6 be x and y respectively 
    #while (i < 10) {
    bge		$t0, 10, check # if $t0 >= 10 then target
    
    #x = num[i]
    mul  $t1, $t0, 4    #   calculate &numbers[i]
    la   $t2, numbers   #
    add  $t3, $t1, $t2  #
    lw   $t5, ($t3)     #   load numbers[i] into $at4
    
    #y = num[i-1]
    sub  $t3, $t3, 4    #   calculate &numbers[i]
    lw   $t6, ($t3)     #   load numbers[i] into $a0
    
    blt		$t5, $t6, do_stuff	# if $t5 < $t6 do_stuffarget

    addi $t0, $t0, 1    #   i++;
    j loop_todo

do_stuff:
    #!!!! HERE t3 IS INITIALLY = SMALL ADDRESS

    #numbers[i] = y (t3 = SMALL)
    sw   $t5, ($t3)     #   load numbers[i] into $a0
   
    #numbers[i - 1] = x 
    #(t3 = SMALL)
    add  $t3, $t3, 4
    #(t3 = NORMAL) 
    sw   $t6, ($t3)

    li   $t4, 1 #swapped is 1
    
    addi $t0, $t0, 1
    j		loop_todo	


loop1:
    bge  $t0, 10, end1  # while (i < 10) {

    mul  $t1, $t0, 4    #   calculate &numbers[i]
    la   $t2, numbers   #
    add  $t3, $t1, $t2  #
    lw   $a0, ($t3)     #   load numbers[i] into $a0
    li   $v0, 1         #   printf("%d", numbers[i])
    syscall

    li   $a0, '\n'      #   printf("%c", '\n');
    li   $v0, 11
    syscall

    addi $t0, $t0, 1    #   i++
    j    loop1          # }
end1:

    jr   $ra            # return

.data

numbers:
    .word 0 0 0 0 0 0 0 0 0 0  # int numbers[10] = {0};

