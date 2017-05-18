// Copyright 2017 AKonia
#include <gtest/gtest.h>
#include <cstdlib>
#include <ctime>

#include "../include/priority_queue.h"

TEST(Priority_queue_test_case, can_fill_pq) {
  akon::PriorityQueue<int> pq;
  for (int i = 10; i > 0; --i) ASSERT_NO_THROW(pq.insert(i));
}

TEST(Priority_queue_test_case, pq_really_makes_its_work) {
  akon::PriorityQueue<int> pq;
  for (int i = 10; i > 0; --i) {
    pq.insert(i);
  }
  for (int i = 1; i <= 10; ++i) {
    EXPECT_EQ(pq.top(), i);
    pq.pop();
  }
}

TEST(Priority_queue_test_case, can_sort_randomized_array_with_pq) {
  srand(time(0));
  akon::PriorityQueue<int> pq;
  int last = 0;
  for (int i = 0; i < 100; ++i) {
    unsigned int a = 0;
    rand_r(&a);
    a %= 100;
    pq.insert(a);
  }
  last = pq.top();
  pq.pop();
  while (!pq.isEmpty()) {
    EXPECT_TRUE((last <= pq.top()));
    last = pq.top();
    pq.pop();
  }
}
