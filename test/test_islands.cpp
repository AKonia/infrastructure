// Copyright 2017 AKonia
#include <gtest/gtest.h>
#include <cstdint>

#include "islands.h"

TEST(Islands, won_t_deluge_if_complete_island) {
  uint32_t field[100];
  for (int i = 0; i < 100; ++i) field[i] = 1;
  islands(field, 10);
  for (int i = 0; i < 100; ++i) {
    int temp = field[i];
    EXPECT_EQ(temp, 1);
  }
}

TEST(Islands, won_t_deluge_if_complete_water) {
  uint32_t field[100];
  for (int i = 0; i < 100; ++i) field[i] = 0;
  islands(field, 10);
  for (int i = 0; i < 100; ++i) {
    int temp = field[i];
    EXPECT_EQ(temp, 0);
  }
}

TEST(Islands, big_island_in_center) {
  uint32_t field[100];
  for (int i = 0; i < 100; ++i) field[i] = 0;
  for (int i = 4; i < 8; ++i)
    for (int j = 4; j < 8; ++j) field[i * 10 + j] = 1;
  islands(field, 10);

  for (int i = 0; i < 100; ++i) {
    int temp = field[i];
    EXPECT_EQ(temp, 0);
  }
}
