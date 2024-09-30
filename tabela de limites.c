#include <stdio.h>
#include <limits.h>

int main() {
    printf("Tipo de Variavel           Minimo                          Maximo\n");
    printf("--------------------------------------------------------------------\n");
    printf("char                        %d                               %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char               0                                %u\n", UCHAR_MAX);
    printf("short int                   %d                               %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short int          0                                %u\n", USHRT_MAX);
    printf("int                         %d                               %d\n", INT_MIN, INT_MAX);
    printf("unsigned int                0                                %u\n", UINT_MAX);
    printf("long int                    %ld                              %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long int           0                                %lu\n", ULONG_MAX);
    printf("long long int               %lld                             %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long int      0                                %llu\n", ULLONG_MAX);
    
    return 0;
}

