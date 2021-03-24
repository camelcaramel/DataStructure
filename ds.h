#ifndef DS_H
#define DS_H

#include <stdlib.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define MALLOC(p, s) \
if (!(p = malloc(s)))\
{ \
	fprintf(stderr, "Insufficient memory");\
	exit(1);\
}
#endif