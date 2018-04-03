#include <stdio.h>
#include <stdlib.h>

// This file implements a naive 32-bits memory management unit(MMU) simulator
// to do virtual memory control.
//
// NOTE1: The number of bits of virtual (offset) for each layer may be different
//        from the real Intel CPU. We are creating our own MMU.
//
// NOTE2: Please treat all unsigned long long as 4 bytes here because we are using
//        a 64-bit program to simulate a 32-bit MMU.
//
// APIs:
//      init_root(): Initialize the L0 page table (root page table). In modern
//                   OS, a similar API is called in the early stage of the
//                   booting process of the OS.
//
//      page_fault_get_physical_page(address): Gets a physical memory page.
//
//      translate(address): Translates a virtual address to the corresponding
//                          physical address.
//
//
//

#define BITS_IN_L0  (3)
#define ENTRIES_IN_L0 (1 << BITS_IN_L0)
#define BITS_IN_L1  (4)
#define ENTRIES_IN_L1 (1 << BITS_IN_L1)
#define BITS_IN_L2  (5)
#define ENTRIES_IN_L2 (1 << BITS_IN_L2)
#define BITS_IN_OFFSETS (20)

unsigned long long root_page_table[ENTRIES_IN_L0];
unsigned long long page_fault_count = 0;

void init_root()
{
    for (int i = 0; i < ENTRIES_IN_L0; i++) {
        root_page_table[i] = 0;
    }
}

// NOTE: You don't need to understand how this API generates a physical memory
//       page (because it's fake). But you need to understand why we need this
//       API.
unsigned int page_fault_get_physical_page(unsigned int address)
{
    unsigned long long addr = address;
    return (unsigned int)((((addr >> BITS_IN_OFFSETS) << BITS_IN_OFFSETS) + 0x20000000) % 0x100000000);
}

unsigned int translate(unsigned int address)
{
    unsigned long long* l1_page_table;
    unsigned long long* l2_page_table;

    // Layer 0, root
    int index_in_l0 = address >> (32 - BITS_IN_L0);
    printf("Index in L0(root) page table : %X\n", index_in_l0);
    if (root_page_table[index_in_l0] == 0) {
        // page fault
        printf("L0 page fault\n");
        page_fault_count += 1;
        root_page_table[index_in_l0] = (unsigned long long) calloc(ENTRIES_IN_L1, sizeof(unsigned long long));
        l1_page_table = (unsigned long long*) root_page_table[index_in_l0];
    } else {
        l1_page_table = (unsigned long long*) root_page_table[index_in_l0];
    }

    // Layer 1
    // FIXME: index_in_l1 is incorrect.
    int index_in_l1 = 0;
    printf("Index in L1 page table : %X\n", index_in_l1);
    if (l1_page_table[index_in_l1] == 0) {
        // page fault
        page_fault_count += 1;
        printf("L1 page fault\n");
        // FIXME: Constructs the missing L2 page table (yes, it's L2 not L1).
    } else {
        // FIXME: Gets the existing L2 page table (yes, it's L2 not L1).
    }

    // Layer 2
    int index_in_l2 = (address << (BITS_IN_L0 + BITS_IN_L1)) >> (32 - BITS_IN_L2);
    printf("Index in L2 page table : %X\n", index_in_l2);
    if (l2_page_table[index_in_l2] == 0) {
        printf("L2 page fault\n");
        // page fault
        page_fault_count += 1;
        l2_page_table[index_in_l2] = page_fault_get_physical_page(address);
    }
    // FIXME: page_offset is incorrect.
    int page_offset = 0;
    printf("Page offset : %X\n", page_offset);
    // FIXME: return value is incorrect;
    return 0;
}

unsigned long long get_page_fault_count()
{
    return page_fault_count;
}
