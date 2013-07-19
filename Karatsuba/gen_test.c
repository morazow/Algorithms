#include <stdio.h>

int N;
char buffer[1000001];

int main(int argc, char* argv[]) {
    int i, v;

    if (argc < 2) {
        printf("Usage: size of numbers\n");
        return 0;
    }

    srand(time(NULL));
    sscanf(argv[1], "%d", &N);

    buffer[0] = '0' + (rand()%9 + 1);
    for (i = 1; i < N; i++)
        buffer[i] = '0' + (rand() % 10);
    printf("%s\n", buffer);

    buffer[0] = '0' + (rand()%9 + 1);
    for (i = 1; i < N; i++)
        buffer[i] = '0' + (rand() % 10);
    printf("%s\n", buffer);

    return 0;
}
