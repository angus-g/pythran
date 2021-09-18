#ifndef PYTHONIC_INCLUDE_TYPES_DEQUE_HPP
#define PYTHONIC_INCLUDE_TYPES_DEQUE_HPP

#include <deque>

PYTHONIC_NS_BEGIN

namespace types
{
  template <class T>
  class deque
  {
    using _type =
      typename std::remove_cv<typename std::remove_reference<T>::type>::type;
    using container_type = std::deque<_type>;

    utils::shared_ref<container_type> data;
  };
}

PYTHONIC_NS_END

#endif
