#include <stdio.h>

#include "htable.h"

int main(int argc, char *argv[])
{
    htable_t *ht = htable_new(10);

    for(int i = 0; i < 50; i++) {
       htable_insert(ht, i, i); 
    }

    htable_print(ht);

    bucket_t *b;
    if((b = htable_lookup(ht, 20)) != NULL) {
        printf("20 is in the table!\n");
    } else {
        printf("20 is not in the table!\n");
    }

    if(!htable_delete(ht, 40)) {
        printf("Unable to delete 40!\n");
    }

    htable_print(ht);

    htable_free(ht);

    return 0;
}
