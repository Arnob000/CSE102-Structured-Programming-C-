//
// Author: Saifur Rahman
// Last Modified: 10 JUL 2019
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, data[100], j = 0;
    int a, b;

    // Alternately, you can do (if you know the maximum number of names
    // that may come as input.
    //      char* name[25] = {0};
    char **name = NULL;

    scanf("%d", &n);
    name = (char**)malloc(n*sizeof(char*));
    for (i = 0; i <n; i++) {
        scanf("%d", &a);
        name[i] = (char*)malloc((a+1)*sizeof(char));
        scanf("%s", name[i]);
    }

    for (i = 0; i <n; i++) {
        printf("%s\n", name[i]);
        free(name[i]);
    }
    free(name);

    //
    // Challange: Can you sort names that you have read, before printing them out?
    //

    return 0;
}
