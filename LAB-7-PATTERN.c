#include <stdio.h>
#include <string.h>

void search(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            printf("Pattern found at index %d\n", i);
    }
}

int main() {
    char text[] = "HIHELLOHIHELLPHIHELLO";
    char pattern[] = "HIHELLP";
    search(text, pattern);
    return 0;
}
