# read 10 numbers into an array
# swap any pairs of of number which are out of order
# then print the 10 numbers

# i in register $t0,
# registers $t1 - $t3 used to hold temporary results

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
    li   $t0, 1         # i = 1
    j		loop_todo			# branch to loop_todo
    
    # PUT YOUR CODE HERE
loop_todo:
  
    #The breaking condition
    bge		$t0, 10, execute	# if $t0 >= 10 then execute  

    #let t4 be x, t5 be y
    #x = numbers[i]
    mul  $t1, $t0, 4    #   calculate &numbers[i]
    la   $t2, numbers   #
    add  $t3, $t1, $t2  #
    lw   $t4, ($t3)     #   load numbers[i] into $at4

    #y = numbers[i-1]
    sub  $t3, $t3, 4    #   calculate &numbers[i]
    lw   $t5, ($t3)     #   load numbers[i] into $a0

    #if x < y --> go to branch (in branch do stuff then i++, then jump to loop_todo)
    blt		$t4, $t5, do_stuff	# if $t4 < $51 do_stuffarget
        

    addi $t0, $t0, 1    #   i++;
    j    loop_todo          

do_stuff:
    #!!!! HERE t3 IS INITIALLY = SMALL ADDRESS

    #numbers[i] = y (t3 = SMALL)
    sw   $t4, ($t3)     #   load numbers[i] into $a0
   
    #numbers[i - 1] = x 
    #(t3 = SMALL)
    add  $t3, $t3, 4
    #(t3 = NORMAL) 
    sw   $t5, ($t3)
    
    addi $t0, $t0, 1
    j		loop_todo				
    

execute:
    li   $t0, 0         # i = 0
    b		loop1			# branch to loop1
    
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
    li   $v0, 0
    jr   $ra            # return 0

.data

numbers:
    .word 0 0 0 0 0 0 0 0 0 0  # int numbers[10] = {0};

