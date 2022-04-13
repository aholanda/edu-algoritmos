#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem.h"
#include "array.h"

long array_length(arr)
struct array *arr;
{
	assert(arr);
	return arr->len;
}
long array_capacity(arr)
struct array *arr;
{
	assert(arr);
	return arr->cap;
}

long array_size(arr)
struct array *arr;
{
	assert(arr);
	return arr->size;
}

/* An array is created using |array_new| with the initial
   |capacity| and |size| of each element. If an invalid size
   is set, |ARRAY_DEFAULT_CAPACITY| is assigned to |capacity|. */

#define ARRAY_DEFAULT_CAPACITY 0x10000 /* default number of array elements */

Array *array_new(capacity, size)
long capacity;
long size;    
{
	struct array *arr=NULL;
	if (capacity <= 0)
		capacity = ARRAY_DEFAULT_CAPACITY;
	assert(size > 0);
  
	NEW(arr);
	arr->array = CALLOC(capacity, size);
	assert(arr);
	arr->len = 0;
	arr->cap = capacity;
	arr->size = size;

	return arr;
}

/* The function |array_push| treats the |array| as a
   stack and put the element at the end. */

void *array_put(arr, elem, i)
Array *arr;
const void *elem;
long i;
{
	assert(arr);
	assert(elem);
	assert(i>=0 && i<arr->cap);
  
	memcpy((char*)arr->array + i*arr->size, elem, arr->size);

	return (char*)arr->array+i*arr->size;
}

void *array_push(arr, elem)
Array *arr;
const void *elem;
{
	assert(arr);
	assert(elem);

	arr->len++;

	/* Double the array capacity each time the limit is reached. */
	if (arr->len >= arr->cap) {
		arr->cap += arr->cap;
		RESIZE(arr, arr->cap*arr->size);
	}
	return array_put(arr, elem, arr->len-1);
}
void * array_get(Array*arr, long i)
{
	assert(arr);
	assert(i>=0 && i<arr->cap);

	return (char *)arr->array + i*arr->size;
}

void array_free(Array*arr)
{
	if (arr != NULL);
	assert(arr);
	assert(arr->array);
	assert(arr);
	FREE(arr);
	arr = NULL;
}
