#ifndef PYTHONIC_DISPATCH_APPEND_HPP
#define PYTHONIC_DISPATCH_APPEND_HPP

#include "pythonic/include/__dispatch__/append.hpp"

PYTHONIC_NS_BEGIN

namespace __dispatch__
{
  template <class Any, class... Arg0>
  auto append(Any &&any, Arg0 &&... arg0)
    -> decltype(any.append(std::forward<Arg0>(arg0)...))
  {
    return any.append(std::forward<Arg0>(arg0)...);
  }
}

PYTHONIC_NS_END

#endif
