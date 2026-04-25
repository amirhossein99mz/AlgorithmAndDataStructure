#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ──────────────────────────────────────────────
 * mergeSort: merges two sorted halves of arr[]
 * into arr2[], then copies back into arr[].
 *   left..middle   = first half
 *   middle+1..right = second half
 * ────────────────────────────────────────────── */
void mergeSort(char *arr, char *arr2, int left, int middle, int right) {
    int i = left, j = middle + 1, k = left;

    while (i <= middle && j <= right) {
        if (arr[i] <= arr[j]) arr2[k++] = arr[i++];
        else                  arr2[k++] = arr[j++];
    }

    while (i <= middle) arr2[k++] = arr[i++];
    while (j <= right)  arr2[k++] = arr[j++];

    for (int e = left; e <= right; e++)
        arr[e] = arr2[e];
}

/* ──────────────────────────────────────────────
 * merge: recursive merge-sort entry point.
 *   Splits arr[left..right] in half, sorts each
 *   half recursively, then merges them.
 * ────────────────────────────────────────────── */
void merge(char *arr, int left, int right) {
    if (left >= right) return;

    int middle = left + (right - left) / 2;
    merge(arr, left,        middle);
    merge(arr, middle + 1,  right);

    char *arr2 = malloc(right - left + 1);
    mergeSort(arr, arr2, left, middle, right);
    free(arr2);
}

/* ──────────────────────────────────────────────
 * is_valid: returns 1 if the string contains only
 * lowercase letters in non-decreasing order.
 * ────────────────────────────────────────────── */
int is_valid(char *s) {
    if (!s || !*s) return 0;
    for (int i = 0; s[i]; i++) {
        if (!islower(s[i]))          return 0;
        if (i > 0 && s[i] < s[i-1]) return 0;
    }
    return 1;
}

/* ──────────────────────────────────────────────
 * merge_string: validates both inputs, then
 * merges s1 and s2 into a single sorted string
 * using the two-pointer merge algorithm.
 * Returns NULL if either string is invalid.
 * ────────────────────────────────────────────── */
char *merge_string(char *s1, char *s2) {
    if (!is_valid(s1) || !is_valid(s2)) {
        printf("Invalid input: strings must be lowercase and sorted.\n");
        return NULL;
    }

    int i = 0, j = 0, k = 0;
    int n1 = strlen(s1);
    int n2 = strlen(s2);

    char *result = malloc(n1 + n2 + 1);

    while (i < n1 && j < n2) {
        if (s1[i] <= s2[j]) result[k++] = s1[i++];
        else                result[k++] = s2[j++];
    }

    while (i < n1) result[k++] = s1[i++];
    while (j < n2) result[k++] = s2[j++];

    result[k] = '\0';
    merge(result, 0, n1 + n2 - 1);   // re-sort via merge sort as safety pass
    return result;
}

int main() {
    char *s1 = "abcdxyz";
    char *s2 = "abcdefgh";

    char *merged = merge_string(s1, s2);
    if (merged) {
        printf("s1     : %s\n", s1);
        printf("s2     : %s\n", s2);
        printf("merged : %s\n", merged);
        free(merged);
    }
    return 0;
}
