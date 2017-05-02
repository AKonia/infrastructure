// Copyright 2017 AKonia
#ifndef INCLUDE_SET_H_
#define INCLUDE_SET_H_

#include "avltree.h"

namespace akon {
template <typename DataType>
using set = AVLTree<DataType>;

template <typename DataType>
using multiset = AVLTree<DataType, true>;
}

#endif  // INCLUDE_SET_H_
