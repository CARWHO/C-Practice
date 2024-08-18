#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

void qsort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

int compareArguments(const void* arg1, const void* arg2)
{
    if (*(uint64_t*) arg1 > *(uint64_t*) arg2) {
        return 1;
    } else if (*(uint64_t*) arg2 > *(uint64_t*) arg1) {
        return -1;
    } else {
        return 0;
    }
}

int main(void)
{
    uint64_t array[10];
    for (uint64_t i = 0; i < 10; i++) {
        scanf("%lu", &array[i]);
    }
    qsort(array, 10, sizeof(uint64_t), &compareArguments);
    for (uint64_t i = 0; i < 10; i++) {
        printf("%lu\n", array[i]);
    }
    
}

// #include <stdio.h>
// #include <stdint.h>
// #include <stdlib.h>

// int compar(const void *a, const void *b)

// {
//     uint64_t val1  = *(const uint64_t *)a; 
//     uint64_t val2  = *(const uint64_t *)b; 

//     if (val1 > val2) {
//         return 1;
//     }

//     else if (val1 < val2) {
//         return -1;
//     }

//     else if (val1 == val2) {
//         return 0;
//     }
// }

// int main()

// {
//     uint64_t array[10];

//     size_t count1 = 1; 
//     while (count1 < 10); {
//         scanf("%lu", &array[count1]);
//     }
//     qsort() 

// }

// Int compar()
// {
// 	Int* arrayLength

// 	While count2 < arrayLength
		
		
// }


// Int main() 
// {
// 	Int* int64; 
	
// 	While count < 10 
// 		scanf("%d", &int64);
// 		Add *int64 to array
// 		count++;
// 	Qsort(array)
// }