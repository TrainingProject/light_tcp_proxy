/*
 * =====================================================================================
 *
 *       Filename:  ltp_mem.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/31/2012 10:09:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bin Lee
 *                  Feng Gao
 *          Email:  gfree.wind@gmail.com  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include "ltp_base_type.h"

void *ltp_alloc_mem(u32 size)
{
    return malloc(size);
}

void ltp_free_mem(void *ptr)
{
    free(ptr);
}

