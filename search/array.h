/* Dynamic arrays. The array type is defined as: */
#ifndef __ARRAY_H__
#define __ARRAY_H__

@ @<Type def...@>=
  typedef struct array {
    void *array; /* variable pointing to the beginning of array */
    long len; /* array length */
    long cap; /* array capacity */
    long size; /* size of each element */
  } Array;

@ @<Proto...@>=
  extern  Array *array_new(long capacity, long size);
  extern __inline long array_length(struct array*);
  extern __inline long array_size(struct array*);
  extern __inline long array_capacity(struct array*);
  extern void *array_put(Array*, const void *elem, long index);
  extern void *array_get(Array*, long index);
  extern void *array_push(Array*, const void *elem);
  extern void array_free(Array*);

#endif

