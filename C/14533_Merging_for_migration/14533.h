struct data {
    int index;
    int age;
    int height;
};

void sort_by_age(int l, int r, struct data *arr);
void sort_by_height(int l, int r, struct data *arr);
void print_elephants(int l, int r, struct data *arr);

// TODO: Implement the following functions in your function.c
void merge_by_age(int l, int m, int r, struct data *arr);
void merge_by_height(int l, int m, int r, struct data *arr);