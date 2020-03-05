#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void counting_sort(vector<int> &v, int base);
int numero_maior(vector<int> &v);
void radix_sort(vector<int> &v);

#endif