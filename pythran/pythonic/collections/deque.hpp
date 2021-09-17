#ifndef PYTHONIC_COLLECTIONS_DEQUE_HPP
#define PYTHONIC_COLLECTIONS_DEQUE_HPP

#include "pythonic/include/collections/deque.hpp"

#include "pythonic/types/deque.hpp"

PYTHONIC_NS_BEGIN

namespace collections
{
  template <class Iterable>
  types::deque<typename std::decay<typename std::iterator_traits<
      typename std::remove_reference<Iterable>::type::iterable>::value_type>::
                   type>
  deque(Iterable &&t)
  {
    return types::deque<typename std::decay<
      typename std::iterator_traits<typename std::remove_reference<
	Iterable>::type::iterator>::value_type>::type(t.begin(), t.end());
  }
}
PYTHONIC_NS_END

#endif
