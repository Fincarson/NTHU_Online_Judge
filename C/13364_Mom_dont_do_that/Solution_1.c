#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char root[5000];
        int layer = 0;
        char* token;
        char* all_dir[40];
        scanf("%s", root);
        token = strtok(root, "/");
        while (token != NULL)
        {
            all_dir[layer] = token;
            token = strtok(NULL, "/");
            layer++;
        }

        char test[5000];
        int test_len = 0;
        char* test_dir[40];
        scanf("%s", test);
        token = strtok(test, "/");
        while (token != NULL)
        {
            test_dir[test_len] = token;
            token = strtok(NULL, "/");
            test_len++;
        }
        int flag = 1;
        for (int j = 0; j < test_len; j++)
        {
            int found = 0;
            for (int k = 0; k < layer; k++)
            {
                if (strcmp(all_dir[k], test_dir[j]) == 0)
                {
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            printf("valid\n");
        else
            printf("not valid\n");

    }
    return 0;
}