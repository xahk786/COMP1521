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





