#ifndef _LINUX_TYPES_H
#define _LINUX_TYPES_H

//#include <asm/types.h>

#ifndef __ASSEMBLY__
#ifdef	__KERNEL__

#define DECLARE_BITMAP(name,bits) \
	unsigned long name[BITS_TO_LONGS(bits)]
#else
#ifndef __EXPORTED_HEADERS__
#warning "Attempt to use kernel headers from user space, see http://kernelnewbies.org/KernelHeaders"
#endif /* __EXPORTED_HEADERS__ */
#endif

//#include <linux/posix_types.h>

#ifdef __KERNEL__
/* bsd */
typedef unsigned char		u_char;
typedef unsigned short		u_short;
typedef unsigned int		u_int;
typedef unsigned long		u_long;

/* sysv */
typedef unsigned char		unchar;
typedef unsigned short		ushort;
typedef unsigned int		uint;
typedef unsigned long		ulong;

#ifndef __BIT_TYPES_DEFINED__
#define __BIT_TYPES_DEFINED__

typedef		u8		u_int8_t;
typedef		s8		int8_t;
typedef		u16		u_int16_t;
typedef		s16		int16_t;
typedef		u32		u_int32_t;
typedef		s32		int32_t;

#endif /* !(__BIT_TYPES_DEFINED__) */

typedef		u8		uint8_t;
typedef		u16		uint16_t;
typedef		u32		uint32_t;

#if defined(__GNUC__)
typedef		u64		uint64_t;
typedef		u64		u_int64_t;
typedef		s64		int64_t;
#endif

 
/**
 * The type used for indexing onto a disc or disc partition.
 *
 * Linux always considers sectors to be 512 bytes long independently
 * of the devices real block size.
 *
 * blkcnt_t is the type of the inode's block count.
 */
#ifdef CONFIG_LBDAF
typedef u64 sector_t;
typedef u64 blkcnt_t;
#else
typedef unsigned long sector_t;
typedef unsigned long blkcnt_t;
#endif

/*
 * The type of an index into the pagecache.  Use a #define so asm/types.h
 * can override it.
 */
#ifndef pgoff_t
#define pgoff_t unsigned long
#endif

#ifdef CONFIG_ARCH_DMA_ADDR_T_64BIT
typedef u64 dma_addr_t;
#else
typedef u32 dma_addr_t;
#endif /* dma_addr_t */

#endif /* __KERNEL__ */

/*
 * Below are truly Linux-specific types that should never collide with
 * any application/library that wants linux/types.h.
 */

#ifdef __CHECKER__
#define __bitwise__ __attribute__((bitwise))
#else
#define __bitwise__
#endif
#ifdef __CHECK_ENDIAN__
#define __bitwise __bitwise__
#else
#define __bitwise
#endif

 #ifdef __KERNEL__
typedef unsigned __bitwise__ gfp_t;
typedef unsigned __bitwise__ fmode_t;

#ifdef CONFIG_PHYS_ADDR_T_64BIT
typedef u64 phys_addr_t;
#else
typedef u32 phys_addr_t;
#endif

typedef phys_addr_t resource_size_t;

typedef struct {
	int counter;
} atomic_t;

#ifdef CONFIG_64BIT
typedef struct {
	long counter;
} atomic64_t;
#endif

struct list_head {
	struct list_head *next, *prev;
};

struct hlist_head {
	struct hlist_node *first;
};

struct hlist_node {
	struct hlist_node *next, **pprev;
};

struct ustat {
	__kernel_daddr_t	f_tfree;
	__kernel_ino_t		f_tinode;
	char			f_fname[6];
	char			f_fpack[6];
};

/**
 * struct rcu_head - callback structure for use with RCU
 * @next: next update requests in a list
 * @func: actual update function to call after the grace period.
 */
struct rcu_head {
	struct rcu_head *next;
	void (*func)(struct rcu_head *head);
};

#endif	/* __KERNEL__ */
#endif /*  __ASSEMBLY__ */
#endif /* _LINUX_TYPES_H */
