#include "partia.h"
#include <vector>

void merge(std::vector<Partia> &partias, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<Partia> L(n1), R(n2);

  for (int i = 0; i < n1; i++) L[i] = partias[left + i];
  for (int j = 0; j < n2; j++) R[j] = partias[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i].participants >= R[j].participants) partias[k++] = L[i++];
    else partias[k++] = R[j++];
  }

  while (i < n1) partias[k++] = L[i++];
  while (j < n2) partias[k++] = R[j++];
}

void sort(std::vector<Partia> &partias, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    sort(partias, left, mid);
    sort(partias, mid+1, right);

    merge(partias, left, mid, right);
  }
}

std::vector<Partia> Partia::sort(std::vector<Partia> partias) {
  ::sort(partias, 0, partias.size()-1);
  return partias;
}