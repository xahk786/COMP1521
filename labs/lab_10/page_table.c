// Simulate LRU replacement of page frames

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


// represent an entry in a simple inverted page table

typedef struct ipt_entry {
    int virtual_page;        // == -1 if physical page free
    int last_access_time;
} ipt_entry_t;


void lru(int n_physical_pages, int n_virtual_pages);
//void access_page(int virtual_page, int access_time, int n_physical_pages, struct ipt_entry *ipt);

void access_page(char action, int virtual_page, int access_time, int n_physical_pages, struct ipt_entry *ipt, int read_virtual_check[], int write_virtual_check[]);
int find(int virtual_page, int n_physical_pages, struct ipt_entry *ipt);
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <n-physical-pages> <n-virtual-pages>\n", argv[0]);
        return 1;
    }
    lru(atoi(argv[1]), atoi(argv[2]));
    return 0;
}


void lru(int n_physical_pages, int n_virtual_pages) {
    printf("Simulating %d pages of physical memory, %d pages of virtual memory\n",
          n_physical_pages, n_virtual_pages);
    struct ipt_entry *ipt = malloc(n_physical_pages * sizeof *ipt);
    assert(ipt);

    for (int i = 0; i < n_physical_pages; i++) {
        ipt[i].virtual_page = -1;
        ipt[i].last_access_time = -1;

    }

    int read_virtual_check[n_virtual_pages];
    int write_virtual_check[n_virtual_pages];

    for (int j = 0; j < n_virtual_pages; j++){
        read_virtual_check[j] = -1;
    }

    for (int j = 0; j < n_virtual_pages; j++){
        write_virtual_check[j] = -1;
    }

    int virtual_page;
    char action;
    int scan_check = scanf("%c %d", &action, &virtual_page);

    /*
    for (int access_time = 0; scan_check != EOF; access_time++) {
        if (scan_check == 2){
            //assert(action == 'r' || action == 'R' || action == 'w' || action == 'W' || action == 'U');
            //assert(action == 'r' || action == 'R' || action == 'w' || action == 'W' || action == 'U');
            access_page(action, virtual_page, access_time, n_physical_pages, ipt, read_virtual_check, write_virtual_check); 
        }
        scan_check = scanf("%c %d", &action, &virtual_page);  
    }
    */

    int access_time = 0;
    while (scan_check != EOF){
        if (scan_check == 2){
            //assert(action == 'r' || action == 'R' || action == 'w' || action == 'W' || action == 'U');
            //assert(action == 'r' || action == 'R' || action == 'w' || action == 'W' || action == 'U');
            access_page(action, virtual_page, access_time, n_physical_pages, ipt, read_virtual_check, write_virtual_check); 
            access_time++;
        }
    scan_check = scanf("%c %d", &action, &virtual_page); 
    }
}


// if virtual_page is not in ipt, the first free page is used
// if there is no free page, the least-recently-used page is evicted
//
// a single line of output describing the page access is always printed
// the last_access_time in ipt is always updated

void access_page(char action, int virtual_page, int access_time, int n_physical_pages, struct ipt_entry *ipt, int read_virtual_check[], int write_virtual_check[]) {

    // PUT YOUR CODE HERE TO HANDLE THE 3 cases
    //
    // 1) The virtual page is already in a physical page
    //
    // 2) The virtual page is not in a physical page,
    //    and there is free physical page
    //
    // 3) The virtual page is not in a physical page,
    //    and there is no free physical page
    //
    // don't forgot to update the last_access_time of the virtual_page
    
    //printf("HELOO????\n");
    //printf("Input was: %c %d\n", action, virtual_page);
    
    if (action == 'U'){ 
        //if already unmapped , then print & return 
        if (read_virtual_check[virtual_page] == -1 && write_virtual_check[virtual_page] == -1 ){
            printf("Time %d: virtual page %d not mapped\n", access_time, virtual_page);
            return;
        } else {
            //unmap virtual page 
            read_virtual_check[virtual_page] = -1;
            write_virtual_check[virtual_page] = -1; 
            
            //attempt to find the physical page that contains virtual page 
            //if found --> free the physical page and also unmap the virtual page 
            int try = find(virtual_page, n_physical_pages, ipt);
            //Debug purposes 
            //printf("Physical page found was %d\n", try);
            
            if (try != -1){
                ipt[try].virtual_page = -1;
                ipt[try].last_access_time = access_time; //unsure ?!?!?
                printf("Time %d: virtual page %d unmapped - physical page %d now free\n", access_time, virtual_page, try);
                return;
            } else { //print appropriately 
                printf("Time %d: virtual page %d unmapped\n", access_time, virtual_page); 
                return;
            }
        }
    }

    if (action == 'R'){
        read_virtual_check[virtual_page] = 1;
        printf("Time %d: virtual page %d mapped read-only\n", access_time, virtual_page);
        return; 
    }

    if (action == 'W'){
        write_virtual_check[virtual_page] = 1;
        read_virtual_check[virtual_page] = 1;
        printf("Time %d: virtual page %d mapped read-write\n", access_time, virtual_page);
        return; 
    } 
    
    for (int i = 0; i < n_physical_pages; i++){
        //if action = read and read access is available
        if (action == 'r' && read_virtual_check[virtual_page] == 1){
            //if already in page, return 
            if (ipt[i].virtual_page == virtual_page){
                ipt[i].last_access_time = access_time;
                printf("Time %d: virtual page %d  - read access - at physical page %d\n", access_time, virtual_page, i);
                return;
            }
            //if free page then load to page, return
            if (ipt[i].virtual_page == -1){
                ipt[i].virtual_page = virtual_page;
                ipt[i].last_access_time = access_time;
                printf("Time %d: virtual page %d  - read access - loaded to physical page %d\n", access_time, virtual_page, i);
                return;
            }
        } else if (action == 'r' && read_virtual_check[virtual_page] == -1) { //else read access illegal
            //ipt[i].last_access_time = access_time; //unsure ?!?!
            printf("Time %d: virtual page %d  - read access - illegal\n", access_time, virtual_page);
            return;
        }
        //if action = write and read access is available
        if (action == 'w' && write_virtual_check[virtual_page] == 1){
            //if already in page, return 
            if (ipt[i].virtual_page == virtual_page){
                ipt[i].last_access_time = access_time;
                printf("Time %d: virtual page %d  - write access - at physical page %d\n", access_time, virtual_page, i);
                return;
            }
            //if free page then load to page 
            if (ipt[i].virtual_page == -1){
                ipt[i].virtual_page = virtual_page;
                ipt[i].last_access_time = access_time;
                printf("Time %d: virtual page %d  - write access - loaded to physical page %d\n", access_time, virtual_page, i);
                return;
            }
       } else if (action == 'w' && write_virtual_check[virtual_page] == -1) {
                //ipt[i].last_access_time = access_time; //unsure ?!?!
                printf("Time %d: virtual page %d  - write access - illegal\n", access_time, virtual_page);
                return;
        }
    }


    //if code reached this point then it means we need to evict a virtual page 
    //we will evict the least recently used virtual page 
    
    int j = 0;
    int min = ipt[j].last_access_time;
    int k = 0;
    int to_evict = ipt[j].virtual_page;

    while (j < n_physical_pages){
        if (ipt[j].last_access_time < min){
            min = ipt[j].last_access_time;
            k = j; //saving the index of the miniumum
            to_evict = ipt[k].virtual_page; //saving the virtual page we want to evict 
        }
        j++;
    }

    if (action == 'r'){
        ipt[k].virtual_page = virtual_page; 
        ipt[k].last_access_time = access_time;
        printf("Time %d: virtual page %d  - read access -  virtual page %d evicted - loaded to physical page %d\n",
            access_time, virtual_page, to_evict, k);
        return;
    } else if (action == 'w'){
        ipt[k].virtual_page = virtual_page; 
        ipt[k].last_access_time = access_time;
        printf("Time %d: virtual page %d  - write access -  virtual page %d evicted - loaded to physical page %d\n",
            access_time, virtual_page, to_evict, k);
        return;
    }




    return;

}

//
//function that find the (index of) physical page that contains the specified virtual page
//returns the physical page # that holds the virtual page 
//  
int find(int virtual_page, int n_physical_pages, struct ipt_entry *ipt){
    int check = -1;

    for (int i = 0; i < n_physical_pages; i++){
        if (ipt[i].virtual_page == virtual_page){
            check = i;
            break;
        }
    }

    return check;


}