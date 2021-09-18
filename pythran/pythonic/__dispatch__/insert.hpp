#ifndef PYTHONIC_DISPATCH_INSERT_HPP
#define PYTHONIC_DISPATCH_INSERT_HPP

#include "pythonic/include/__dispatch__/insert.hpp"

PYTHONIC_NS_BEGIN

namespace __dispatch__
{
  template <class Any, class... Arg0>
  auto insert(Any &&any, Arg0 &&... arg0)
    -> decltype(any.insert(std::forward<Arg0>(arg0)...))
  {
    return any.insert(std::forward<Arg0>(arg0)...);
  }
}

PYTHONIC_NS_END

#endif
