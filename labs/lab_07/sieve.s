# Sieve of Eratosthenes
# https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
main:

    # PUT YOUR CODE

    #$t0 = i , $t1 = j 
    li		$t0, 0	#i = 0

    j while_1

    while_1:
        bge		$t0, 1000, go_next	# if i >= 1000 go next 
        
        la		$t2, prime 
        add		$t3, $t2, $t0		# final_add = (&prime + i)
        
        li		$t4, 1		# $t4 =1 
        
        sb		$t4, ($t3)	#prime[i] = 1
        addi	$t0, $t0, 1			# i++
        j while_1
    
    go_next:
        li		$t0, 2	    # i = 2
        j while_2
    
    while_2:
        bge		$t0, 1000, end	# if i >= 1000 end

        la		$t2, prime 
        add		$t3, $t2, $t0		# final_add = (&prime + i)

        lb		$t4, ($t3)		#t4 = prime[i] 
           
        bne		$t4, $zero, do_if	# if prime[i] != do_if 
        #else i++
        addi	$t0, $t0, 1			# i++
        j while_2
    
    do_if:
        move 	$a0, $t0	#print(i)
        li		$v0, 1
        syscall

        li   $a0, '\n'      # printf("%c", '\n');
        li   $v0, 11
        syscall
        
        mul	$t1, $t0, 2			# j = 2 * i

        j while_3
        
    while_3:
        bge		$t1, 1000, end_while_3 #if j >= 1000 end_while_3
        
        la		$t2, prime 
        add		$t3, $t2, $t1		# final_add = (&prime + j)

        sb		$zero, ($t3)		#prime[j] = 0

        add 	$t1, $t1, $t0			# j= j + i

        j while_3
        
    end_while_3:
        #else i++
        addi	$t0, $t0, 1			# i++
        j while_2


    end:
        li $v0, 0           # return 0
        jr $31     

.data
prime:
    .space 1000