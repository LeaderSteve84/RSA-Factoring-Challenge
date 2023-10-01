#ifndef FACTORS_H
#define FACTORS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

int64_t gcd(int64_t a, int64_t b);
int64_t pollards_rho(int64_t n);
void factorise(int64_t n);


#endif
