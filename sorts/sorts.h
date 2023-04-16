#ifndef SORTS_H_
#define SORTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int arr[], int n);

void selectionSort(int arr[], int n);

int partition(int arr[], int low, int high);

void quickSort(int arr[], int low, int high);

void insertionSort(int arr[], int n);

void merge(int arr[], int left, int mid, int right);

void mergeSort(int arr[], int left, int right);

void heapify(int arr[], int n, int i);

void heapSort(int arr[], int n);

#endif