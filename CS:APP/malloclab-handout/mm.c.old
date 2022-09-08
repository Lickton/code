/*
 * mm-naive.c - The fastest, least memory-efficient malloc package.
 * 
 * In this naive approach, a block is allocated by simply incrementing
 * the brk pointer.  A block is pure payload. There are no headers or
 * footers.  Blocks are never coalesced or reused. Realloc is
 * implemented directly using mm_malloc and mm_free.
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
    /* Team name */
    "ateam",
    /* First member's full name */
    "Harry Bovik",
    /* First member's email address */
    "bovik@cs.cmu.edu",
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's email address (leave blank if none) */
    ""
};

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8
#define WSIZE 4
#define DSIZE 8
#define CHUNKSIZE (1 << 12) 
/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size)			(((size) + (ALIGNMENT-1)) & ~0x7)

#define SIZE_T_SIZE			(ALIGN(sizeof(size_t)))

/* Pack a size and allocated bit into a word */
#define PACK(size, alloc)	((size) | (alloc))

/* Read and write a word at adress*/
#define GET(p)				(*(unsigned int *)(p))
#define PUT(p, val)			(*(unsigned int *)(p) = (val))

/* Read the size and allocated fields from adress */
#define GET_SIZE(p)			(GET(p) & ~0x7)
#define GET_ALLOC(p)		(GET(p) & 0x1)

/* Given block ptr bp, compute address of its header and footer */
#define HDRP(bp)			((char *)(bp) - WSIZE)
#define FTRP(bp)			((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)

/* Given block ptr bp, compute address of its header and footer */
#define NEXT_BLKP(bp)		((char *)(bp) + GET_SIZE(((char *)(bp) - WSIZE)))
#define PREV_BLKP(bp)		((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE)))

/* Given block ptr bp, compute address of its prev and next block */
#define NEXT_NODE(bp)		((char *)(bp))
#define PREV_NODE(bp)		((char *)(bp) + WSIZE)

#define MAX(m, n)			((m) > (n) ? (m) : (n))

/* Private global variables */
static char* heap_listp;
static char* block_listp;

/* Privete function */

/* find_fit_class - find the class suits */
static char* find_fit_class(size_t size)
{
	int i = 0;
	
	if (size <= 8) i = 0;
	else if (size <= 16) i = 1;
	else if (size <= 32) i = 2;
	else if (size <= 64) i = 3;
	else if (size <= 128) i = 4;
	else if (size <= 256) i = 5;
	else if (size <= 512) i = 6;
	else if (size <= 2048) i = 7;
	else if (size <= 4096) i = 8;
	else i = 9;

	return block_listp + (i * WSIZE);
}

/* insert_to_sizelist - insert to the size's list'*/
static void insert_to_sizelist(char* bp)
{
	char* start = find_fit_class(GET_SIZE(HDRP(bp)));
	char* prev = start;
	char* next = GET(start);

	while (next != NULL) {
		if (GET_SIZE(HDRP(next)) >= GET_SIZE(HDRP(bp)))
			break;
		prev = next;
		next = GET(NEXT_NODE(next));
	}
	if (prev == start) { // start from head
		PUT(start, bp);
		PUT(NEXT_NODE(bp), next);
		PUT(PREV_NODE(bp), NULL);
		if (next != NULL) PUT(PREV_NODE(next), bp);
	} else { // normal
		PUT(NEXT_NODE(prev), bp);
		PUT(PREV_NODE(bp), prev);
		PUT(NEXT_NODE(bp), next);
		if (next != NULL) PUT(PREV_NODE(next), bp);
	}
}

/* fix_linklist - delete the bp node */
static void fix_linklist(char *bp)
{
	char* start = find_fit_class(GET_SIZE(HDRP(bp)));
	char* prev = GET(PREV_NODE(bp));
	char* next = GET(NEXT_NODE(bp));
	
	if (prev == NULL) {
		if (next != NULL)
			PUT(PREV_NODE(next), NULL);
		PUT(start, next);
	} else {
		if (next != NULL)
			PUT(PREV_NODE(next), prev);
		PUT(NEXT_NODE(bp), next);
	}

	PUT(PREV_NODE(bp), NULL);
	PUT(NEXT_NODE(bp), NULL);
}

/* coalesce - 1. apply extend space
 *			  2. initializing
 */
static void* coalesce(void *bp)
{
	size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
	size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
	size_t size = GET_SIZE(HDRP(bp));

	if (prev_alloc && next_alloc) {

	} else if (prev_alloc && !next_alloc) { // merge next
		size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
		fix_linklist(NEXT_BLKP(bp));
		PUT(HDRP(bp), PACK(size, 0));
		PUT(FTRP(bp), PACK(size, 0));
	} else if (!prev_alloc && next_alloc) { // merge front
		size += GET_SIZE(HDRP(PREV_BLKP(bp)));
		fix_linklist(PREV_BLKP(bp));
		PUT(FTRP(bp), PACK(size, 0));
		PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
		bp = PREV_BLKP(bp);
	} else {
		size += GET_SIZE(FTRP(NEXT_BLKP(bp))) + GET_SIZE(FTRP(PREV_BLKP(bp)));
		fix_linklist(PREV_BLKP(bp));
		fix_linklist(NEXT_BLKP(bp));
		PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0));
		PUT(HDRP(PREV_NODE(bp)), PACK(size, 0));
		bp = PREV_BLKP(bp);
	}
	insert_to_sizelist(bp);
	return bp;
}

/* extend_heap - 1. when the heap is initialized 
 *				 2. mm_malloc can't find a suitable block 
 *	using mem_sbrk to apply space
 */
static void* extend_heap(size_t words)
{
	char* bp;
	size_t size;

	size = (words % 2) ? (words + 1) * DSIZE : words * DSIZE;
	if (bp = mem_sbrk(size), bp == -1)
		return NULL;

	PUT(HDRP(bp), PACK(size, 0));
	PUT(FTRP(bp), PACK(size, 0));
	PUT(NEXT_NODE(bp), NULL);
	PUT(PREV_NODE(bp), NULL);
	PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));
	
	return coalesce(bp);
}

/* 
 * mm_init - initialize the malloc package.
 */
int mm_init(void)
{
	/* Create the initial empty heap */
	if (heap_listp = mem_sbrk(14*WSIZE), heap_listp == (void*)-1)
		return -1;

	PUT(heap_listp, 0);				// size <= 8
	PUT(heap_listp + WSIZE, 0);		// 8 < size <= 16
	PUT(heap_listp + (2  * WSIZE), 0); // 16 < size <= 32
	PUT(heap_listp + (3  * WSIZE), 0); // 32 < size <= 64
	PUT(heap_listp + (4  * WSIZE), 0); // 64 < size <= 128
	PUT(heap_listp + (5  * WSIZE), 0); // 128 < size <= 256
	PUT(heap_listp + (6  * WSIZE), 0); // 256 < size <= 512
	PUT(heap_listp + (7  * WSIZE), 0); // 512 < size <= 2048
	PUT(heap_listp + (8  * WSIZE), 0); // 1024 < size <= 2048
	PUT(heap_listp + (9  * WSIZE), 0); // 2048 < size <= 4096
	PUT(heap_listp + (10 * WSIZE), PACK(DSIZE, 1)); // size > 4096
	PUT(heap_listp + (11 * WSIZE), PACK(DSIZE, 1)); // Prologue header
	PUT(heap_listp + (12 * WSIZE), PACK(DSIZE, 1)); // Prologue footer
	PUT(heap_listp + (13 * WSIZE), PACK(0, 1));		// Epilogue header
	
	block_listp = heap_listp;
	heap_listp += (12 * WSIZE);

	if (extend_heap(CHUNKSIZE/WSIZE) == NULL)
		return -1;

	return 0;
}

/* find_fit - First Fit */
static void* find_fit(size_t asize)
{
	for (char* start = find_fit_class(asize); start != heap_listp - (2 * WSIZE); start += WSIZE) {
		char* cur = GET(start);
		while (cur != NULL) {
			if (GET_SIZE(HDRP(cur)) >= asize)
				return cur;
			cur = GET(NEXT_NODE(cur));
		}
	}
	return NULL;
}

/* place - change the size space block to 2 parts */
static void place(void* bp, size_t asize)
{
	size_t csize = GET_SIZE(HDRP(bp));
	fix_linklist(bp);

	if (csize-asize >= 2*DSIZE) {
		PUT(HDRP(bp), PACK(asize, 1));
        PUT(FTRP(bp), PACK(asize, 1));
        
        bp = NEXT_BLKP(bp);
        PUT(HDRP(bp), PACK(csize-asize, 0));
        PUT(FTRP(bp), PACK(csize-asize, 0));
        PUT(NEXT_NODE(bp), 0);
        PUT(PREV_NODE(bp), 0);
        coalesce(bp);
	} else {
		PUT(HDRP(bp), PACK(csize, 1));
		PUT(FTRP(bp), PACK(csize, 1));
	}
}

/* 
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size)
{
	size_t asize;
	size_t extendsize;
	char* bp;

	if (size == 0)
		return NULL;

	if (size <= DSIZE)
		asize = 2*DSIZE;
	else 
		asize = (DSIZE) * ((size + (DSIZE) + (DSIZE - 1)) / (DSIZE));

	if (bp = find_fit(asize), bp != NULL) {
		place(bp, asize);
		return bp;
	}
	extendsize = MAX(asize, CHUNKSIZE);
	if (bp = extend_heap(extendsize / DSIZE), bp == NULL)
		return NULL;

	place(bp, asize);
	return bp;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *ptr)
{
	if (ptr == 0)
		return;
	size_t size = GET_SIZE(HDRP(ptr));

	PUT(HDRP(ptr), PACK(size, 0));
	PUT(FTRP(ptr), PACK(size, 0));
	PUT(NEXT_NODE(ptr), 0);
	PUT(PREV_NODE(ptr), 0);

	coalesce(ptr);
}

/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size)
{
	size_t oldsize = GET_ALLOC(HDRP(ptr)) ;
	void *newptr;
	size_t asize;

	if (size == 0) {
		mm_free(ptr);
		return 0;
	}

	if (ptr == NULL) {
		return mm_malloc(size);
	}

	if (size <= DSIZE) {
		asize = 2*(DSIZE);
	} else {
		asize = (DSIZE) * ((size + (DSIZE) + (DSIZE - 1)) / (DSIZE));
	}
	if (oldsize == asize) return ptr;

	newptr = mm_malloc(size);

	if (!newptr) {
		return 0;
	}

	oldsize = GET_SIZE(HDRP(ptr));
	if (size < oldsize) oldsize = size;
	memcpy(newptr, ptr, oldsize);

	mm_free(ptr);
	return newptr;
}
