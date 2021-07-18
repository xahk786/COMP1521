# COMP1521 Course Notes 

#  Revision 

##  Pointers 
- **Pointers** are variables that hold the memory address of a given variable.
- **Dereferencing a pointer** means to access the item that is at the address being held be a given pointer. 
- **Incrementing a pointer** increases the address by however much the size is of the item that the pointer points to.

*Example:* We can overwrite an address and overwrite the data stored at a given address
```c
int x = 5; 
int y = 10;
int *p; //declaring that p points to a variable of type int 
p = &x; //p hold the memory address of x
p++; // p now holds the memory address of y 
int temp = *p; //temp = 10
*p = 0; //y = 0
```

## Dynamic Memory Allocation
- **Malloc** and **Calloc** are functions that allocate a certain amount of memory (in the heap) and return the base address. 
- Data needs to be free'd manually

*Example:* Allocating 16 bytes to hold 4 integers on the heap
``` c
int *p = malloc(4 * sizeof(int)) //4 blocks of data, each 4 bytes long
//OR
int *p = calloc(4,4) //4 blocks of data, 4 bytes long, init all values to 0
*p = 0;
p++;
*p = 1;
p++;
*p = 2;
p++;
*p = 3;
```
| Adress | Value | 
|--------|-------|
| 1000   | 0     |
| 1004   | 1     |
| 1008   | 2     |
| 1012   | 3     |


## Structs

- Structs are formed from multiple data types
- The data in the struct is accessed by name

*Example:*
``` c
struct s {
    int age;
    char* name;
};
```
- Think of the whole struct variable as a type
``` c 
struct s person_1; //person_1 is a struct with members int age and char* name
person_1.name = "dan" //name of person_1 is dan
person.age = 10; //age of person_1 = 10
```

### Pointers to structs
```c
struct s p*; //declaring p will be a pointer to a struct s
p = &person_1; //p will hold address of person_1;
``` 
The syntax to access a member of the struct is as follows:\
`(*p).age` = `person_1.age` = `p->age`


# Part 1 : Bits, integers, floating points

## Integers
- 1 byte = 8 bits 

| Prefix | Representation| Base|
|--------|---------------|------------  |
| 0b     | binary             |2            |  
| 0      | octal             |8             | 
| 0x     | hexadecimal             |16             |

- In hexadecimal each digit represents 4 bits 
- To convert from binary to hexadecimal, group bits of 4 together and calculate. Each group represents a digit. 

### **2-s complement**
- We can use 2-s complement to represent integers, whether positive or negative 
- If the **leftmost** bit is **0**, then the integer is **positive** and is already in binary representation
- If the **leftmost** bit is **1**, then the integer is **negative**. 
- To convert 2-s complement representation into binary representation do the following:
    1. Flip the bits (0's become 1's, 1's becomes 0's) 
    2. Add 1  
    3. Can do binary -> decimal conversion to find number
- To convert negative integer to 2-s complement representation flip bits and add 1 

## Bitwise Operations

| Sybmol | Action| 
|--------|-------|
|   <<   | left shift     |
| >>     | right shft     |
| &   | And     |
| \|   | OR     |

- Left shifting increases number of bits 
- Right shifting decreases number of bits 

## Floats

- A binary string fraction  *example:*
    -  ` .101 = 1(2^-1) + 0(2^-2) + 1(2^-3)`\
    `= 0.625 `
      

- Floats in c use IEEE 754 standard encoded bit strings
- A C float is made up of 32 bits 
    - Bit **1** represents **sign** (1 for negative, 0 for positive)
    - Next **8** bits represents **raw exponent** (Exponent = raw exponent - 127)
    - Next **23** bits represents **fraction**
- `Value = sign * (1 + frac) * 2^(raw_exponent - 127)`

- **Converting float to binary string**
    - To work out fraction divide value by largest 2^(n) that is smaller than value 



##

# Part 2 : MIPS Assembly 

## Syscalls:
-   Print string
    ```MIPS
    #Load string address into $a0
    #Load 4 into $v0
    la   $a0, string_1 
    li   $v0, 4 
    syscall
    ```

-   Print integer
    ```MIPS
    #Load integer value in $a0
    #load 1 into $v0
    li   $a0, 42 
    li   $v0, 1 
    syscall
    ```
-   Scanf integer
    ```MIPS
    #load 5 into $v0. Fetch scanned integer from $v0
    li   $v0, 5        
    syscall
    ```
-   fgets(str,128, stdin)
    ```MIPS
    #load string address into $a0
    #load length into $a1
    #load 1 into $v0
    la		$a0, string_1		
    la		$a1, 128		
    li      $v0, 8   
    syscall
    ```
## Memory in MIPS

- **Word**: 1 word is 4 bytes long. Thus word can be used to represent a global variable or an array \
*Example:*
    ```MIPS
    .data
    global_var: 
        .word 7 
    numbers_array:
        .word 0 1 2 3 4 5 
    ```
    - Accessing word variables:
        - ``` MIPS
          sw  $t0, global_var #global_var = $t0
          lw  $t0, global_var #$t0 = global_var
          
          li  $t0, 8 #index = $t0 / 4 = 2     
          sw  $t1, array($t0) # array[2] = $t1
          lb  $t1, array($t0) # $t1 = array[2]
          ```
        - Address is indexed by increments of 4 
- **Byte**: \
*Example:*
    ```MIPS
    .data
    char_x: #char x = 'a';
        .byte 'a'
    char_array: #char array[5] = {'a' ,'b' ...}
        .byte 'a' 'b' 'c' 'd' 'e' 
    ```
    - Address is indexed bt increments of 1

- **Space**: When unsure of the contents of a variable, use space to allocate how many bytes the variable will hold \
*Example:*
    ```MIPS
    .data
    int_x:
        .space 4 #int holds 4 bytes 
    char_x:
        .space 1 #char holds 1 byte
    array_x:
        .space 20 #array with 5 elements uses 20 bytes 
    ```
    - Access space variables using sb (save byte) and lb(load byte). Can also use sw and lw if dealing with word
    - Address is generally indexed by increments of 1, but if storing words in space, then indexed by 4
        

# Part 3 : System Programming






