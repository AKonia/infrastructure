#ifndef INCLUDE_TASK_NUMBERS_H_
#define INCLUDE_TASK_NUMBERS_H_

int * gen_array_of_mults(const int arr_size, int * arr)
{
    if (!arr || arr_size == 1)
        return 0;
    int *res_arr = new int[arr_size];
    int mul = 1;
    for (int i = 0; i < arr_size; i++)
        mul *= arr[i];
    int mul_one = 1, mul_two = 1;
    for (int i = 0; i < arr_size; i++) {
        res_arr[i] *= mul_one;
        mul_one *= arr[i];
        res_arr[arr_size - 1 - i] *= mul_two;
        mul_two *= arr[arr_size - 1 - i];
    }
    return res_arr;
}

#endif // INCLUDE_TASK_NUMBERS_H_
