#ifndef PYTHONIC_INCLUDE_COLLECTIONS_DEQUE_HPP
#define PYTHONIC_INCLUDE_COLLECTIONS_DEQUE_HPP

#include "pythonic/include/types/deque.hpp"
#include "pythonic/include/utils/functor.hpp"

#include <iterator>
#include <type_traits>

PYTHONIC_NS_BEGIN

namespace collections
{
  template <class Iterable>
  types::deque<typename std::decay<typename std::iterator_traits<typename std::remove_reference<Iterable>::type::iterator>::value_type>::type>
  deque(Iterable &&t);

  DEFINE_FUNCTOR(pythonic::collections, deque);
}

PYTHONIC_NS_END

#endif
