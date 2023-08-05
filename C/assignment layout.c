#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{// ./analyse_nums 100000 1 100
    int n = atoi(argv[1]);
    int r1 = atoi(argv[2]);
    int r2 = atoi(argv[3]);

    int range = r2 - r1 + 1; //r1 = 3, r2 = 10, range = 8

    int r = rand() % range + r1;

    double start, end;
    start=clock();

    end = clock();

    double secs = (end - start) / CLOCKS_PER_SEC;

    const int nops = 7;

    int tops = nops * 0.1 * n;

    int count = 0;

    while (count++ < tops)
    {
        int r = rand() % range + r1;
        int op = rand() % nops;
        switch (op)
        {
            case 0 : find(r); break;
            case 1 : add(r); break;
            case 2 : delete(r); break;        
        }
    double end = clock();
//    counts[op]++;
//    times[op] += (end - start);

    }

}