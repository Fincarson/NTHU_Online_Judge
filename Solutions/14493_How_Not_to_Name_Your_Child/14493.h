#include <stdlib.h>

char** reallocate_name_list(char** old_name_list, int name_count, int new_capacity);

char* choose_best_name(char **names, int number_of_names, int (*comparing_function)(const char*, const char*));

int compareByBackwardsString(const char* str1, const char* str2);

int compareByDictionary(const char* str1, const char* str2);