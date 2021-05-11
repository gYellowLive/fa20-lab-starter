#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
   
    node* tor = head;
    node* hare = head;

    while(hare){
	 node* hare_next = hare->next;
	 if(hare_next == 0){
		 return 0;
	 }
	 node* hare_next_next = hare_next->next;
	 if (hare_next_next == 0){
		 return 0;
	 }
	 hare = hare_next_next;
	 if (tor == hare){
		 return 1;
	}
	 // now that within 2 away from hare isn't the end, and it's not quite a cycle
	 // need to update the tor and hare
	 tor = tor->next;
	 

    }

}
