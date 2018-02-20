#include <stdio.h>
#include "bloom_filter.h"


void check_helper(BloomFilter* bf, char* word) {
    bool is_there = bf->check(bf, word);

    printf("String '%s' was %s in filter.\n", word, is_there ? "FOUND" : "NOT FOUND");
}

int main() {
    BloomFilter* filter = new_filter(13437);

    filter->add(filter, "one");
    filter->add(filter, "another");
    filter->add(filter, "add me to the filter");
    filter->add(filter, "Constantinople");

    check_helper(filter, "probably not");
    check_helper(filter, "Constantinople");
    check_helper(filter, "bnother"); // Very small change to 'another'


    filter->destruct(filter);
    // filter->add(filter, "adding another");
    return 0;
}
