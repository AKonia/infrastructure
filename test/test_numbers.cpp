#include "task_numbers.h"
#include <gtest/gtest.h>

TEST(NumbersTest, can_gen_arr) {	
    const int arr_size = 5;
    int arr[arr_size] = {1, 2, 5, 6, 2};
    int *gen_arr;
    ASSERT_NO_THROW(gen_arr = gen_array_of_mults(arr_size, arr));
}

TEST(NumbersTest, can_gen_right_result_on_typical_case) {
    const int arr_size = 5;
    int arr[arr_size] = { 1, 2, 5, 6, 2 };
    int will_be_result[arr_size] = { 120, 60, 24, 20, 60 };
    int *gen_arr = gen_array_of_mults(arr_size, arr);
    for (int i = 0; i < arr_size; i++)
        EXPECT_EQ(gen_arr[i], will_be_result[i]);
}

TEST(NumbersTest, ignoring_null_input) {
    const int arr_size = 5;
    int * arr = 0;
    int *gen_arr = gen_array_of_mults(arr_size, arr);
    EXPECT_EQ((gen_arr = gen_array_of_mults(arr_size, arr)), 0);
}

TEST(NumbersTest, will_accept_size_eq_one) {
    const int arr_size = 1;
    int arr[arr_size] = { 1};
    int *gen_arr;
    EXPECT_EQ((gen_arr = gen_array_of_mults(arr_size, arr)), 0);
}
