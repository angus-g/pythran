#ifndef PYTHONIC_INCLUDE_TYPES_DEQUE_HPP
#define PYTHONIC_INCLUDE_TYPES_DEQUE_HPP

#include <deque>

PYTHONIC_NS_BEGIN

namespace types
{
  template <class T>
  using container = std::deque<T>;

  template <class T>
  class deque
  {
    typedef
      typename std::remove_cv<typename std::remove_reference<T>::type>::type
      _type;
    typedef container<_type> container_type;
    utils::shared_ref<container_type> data;
  };
}

PYTHONIC_NS_END

#endif
