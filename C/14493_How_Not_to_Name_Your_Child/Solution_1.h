#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

char** reallocate_name_list(char** old_name_list, int name_count, int new_capacity) {
    char** new_list = (char**)malloc(new_capacity * sizeof(char*));
    if (new_list == NULL) return NULL;
    for (int i = 0; i < name_count; i++) {
        new_list[i] = old_name_list[i];
    }
    free(old_name_list);
    return new_list;
}

char* choose_best_name(char **names, int number_of_names, int (*comparing_function)(const char*, const char*)) {
    if (number_of_names == 0) return NULL;
    char* best_name = names[0];

    for (int i = 1; i < number_of_names; i++) {
        if (comparing_function(names[i], best_name) < 0) {
            best_name = names[i];
        }
    }
    return best_name;
}

int compareByBackwardsString(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = len1 < len2 ? len1 : len2;

    for (int i = 0; i < min_len; i++) {
        char ch1 = str1[len1 - 1 - i];
        char ch2 = str2[len2 - 1 - i];

        if (ch1 != ch2) {
            return ch1 - ch2;
        }
    }
    return len1 - len2;
}

int compareByDictionary(const char* str1, const char* str2) {
    int cmp = strcasecmp(str1, str2);
    if (cmp != 0)
        return cmp;
    return strcmp(str1, str2);
}