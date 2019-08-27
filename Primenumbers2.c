#include <stdio.h>

#include <stdlib.h>

#include <sys/time.h>



#define sqr(x)      ((x) * (x))



int main(int argc, char *argv[]) {

    unsigned long countNum, workNum, max, total = 0;

    

    // Check argument

    switch (argc) {

        case 1:

            max = 78498;

            break;

        case 2:

            max = atol(argv[1]);

            if (max >= 2 && max <= 1000000) { // logical max 4294967295

                break;

            }

        default:

            fprintf(stderr, "Invalid argument\n" );

            return 1;

            break;

    }



    struct timeval startTime, endCalcTime, endTime;

    gettimeofday(&startTime, NULL);



    unsigned long *prime;

    prime = malloc(sizeof(long) * max);

    if (prime == NULL) {

        fprintf(stderr, "Error:out of memory");

        return 1;

    }



    *(prime + total++) = 2;

    *(prime + total++) = countNum = 3;



    while (countNum += 2, total < max) {

        workNum = 0;

        while (workNum++, sqr(*(prime + workNum)) <= countNum) {

            if (countNum % *(prime + workNum) == 0) {

                break; /* not prime */

            }

        }

        if (sqr(*(prime + workNum)) > countNum) {

            *(prime + total++) = countNum;

        }

    }



    gettimeofday(&endCalcTime, NULL);

    

    workNum = 0;

    while (workNum < total) {

        if(workNum % 10 == 0) {

            printf("\n");

        }

        printf("%10lu\n", *(prime + workNum++));

    }

    printf("\nprime count = %lu\n", total);



    gettimeofday(&endTime, NULL);

    

    printf("calc elapsed time = %lf\n", (endCalcTime.tv_sec - startTime.tv_sec) + (endCalcTime.tv_usec - startTime.tv_usec) * 1.0E-6);

    printf("view elapsed time = %lf\n", (endTime.tv_sec - endCalcTime.tv_sec) + (endTime.tv_usec - endCalcTime.tv_usec) * 1.0E-6);



    free(prime);



    return 0;

}