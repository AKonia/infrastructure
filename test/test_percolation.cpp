// Copyright 2017 AKonia
#include <gtest/gtest.h>

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include "percolation.h"

TEST(Percolation, correct_working_manual_data_vertical_line) {
  uint32_t field[100];
  memset(field, 0, sizeof(field));
  for (uint32_t i = 0; i < 100; i++)
    if (i % 10 == 3) field[i] = 1;
  EXPECT_EQ(percolationTest(field, 10), true);
}

TEST(Percolation, correct_working_manual_data_vertical_not_completed_line) {
  uint32_t field[100];
  memset(field, 0, sizeof(field));
  for (uint32_t i = 3; i < 90; i += 10) field[i] = 1;
  EXPECT_EQ(percolationTest(field, 10), false);
}

TEST(Percolation, correct_working_manual_data_diagonal_line) {
  uint32_t field[100];
  memset(field, 0, sizeof(field));
  for (uint32_t i = 0; i < 10; ++i) field[i * 10 + i] = 1;
  for (uint32_t i = 0; i < 9; ++i) field[i * 10 + i + 1] = 1;
  EXPECT_EQ(percolationTest(field, 10), true);
}
