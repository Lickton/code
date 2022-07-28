#include "cachelab.h"

#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef unsigned long long ULL;
typedef struct {
    int valid;
    ULL tag;
    int size;
    int age;
} cache_line;

int power2(int x)
{
    int res = 1;
    for (int i = 0; i < x; i++)
        res *= 2;

    return res;
}

int main(int argc, char **argv)
{
    FILE *fptr;

    int hit_count, miss_count, eviction_count;
    int set_size, elem_size, block_size, offt;
    int c, hit_flag, set_full_flag;
    ULL addr, set, tag_cache;
    char *trace_files;
    char op;
    cache_line *cache;

    hit_count = miss_count = eviction_count = 0;

    while ((c = getopt(argc, argv, "s:E:b:t:")) != -1) {
        switch (c) {
            case 's':
                set_size = atoi(optarg);
                break;
            case 'E':
                elem_size = atoi(optarg);
                break;
            case 'b':
                block_size = atoi(optarg);
                break;
            case 't':
                trace_files = optarg;
                break;
            default:
                break;
        }
    }

    fptr = fopen(trace_files, "r");

    cache = (cache_line*)malloc((power2(set_size) * elem_size) * sizeof(cache_line));
    memset(cache, 0, (power2(set_size) * elem_size) * sizeof(cache_line));

    while (fscanf(fptr, " %c %llx,%d", &op, &addr, &offt) != -1) {
        // ignore the 'I' instruction
        if (op == 'I') continue;

        hit_flag = set_full_flag = 0;
        set = (addr << (64 - set_size - block_size)) >> (64 - set_size); // get the bit size of count
        tag_cache = addr >> (set_size + block_size);                     // get the bit size of tag
        // the address is 64-bits, using usinged long long
        ULL base_index = set*elem_size;
        // keep the index of max age, make it easy to evicte it. LRU
        ULL max_age_index = 0, max_age = 0;

        printf("%c %llx,%d ", op, addr, offt);

        for (ULL i = 0; i < elem_size; i++) {
            if (!cache[base_index + i].valid) break;        // if the set is full, all valid is true
            cache[base_index + i].age++;                    // LRU, each time, age += 1 if doesnt hit
            if (cache[base_index + i].tag == tag_cache) {   // hit, age = 0
                cache[base_index+i].age = 0;
                hit_flag = 1;
                hit_count++;
            }

            if (max_age < cache[base_index + i].age) {      // update the max age and the index
                max_age_index = base_index + i;
                max_age = cache[base_index + i].age;
            }

            set_full_flag++;
        }

        if (hit_flag) printf("hit\n");
        if (hit_flag) {
            if (op == 'M') hit_count++;
            continue;
        }

        if (set_full_flag < elem_size) {    // miss but the set isnt full, simply add in
            printf("miss");
            miss_count++;
            cache[base_index+set_full_flag].valid = 1;
            cache[base_index+set_full_flag].age = 0;
            cache[base_index+set_full_flag].tag = tag_cache;
        } else {    // evivtion miss and the set is full
            printf("miss evivtion");
            miss_count++;
            eviction_count++;
            cache[max_age_index].tag = tag_cache;
            cache[max_age_index].age = 0;
        }
        
        if (op == 'M') printf("hit");   // if one operation is 'M', it must be end up with 'hit'
        puts("");
        if (op == 'M') hit_count++;
    }


    free(cache);
    fclose(fptr);
    printSummary(hit_count, miss_count, eviction_count);
    return 0;
}
