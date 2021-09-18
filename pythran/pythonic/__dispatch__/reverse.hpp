#ifndef PYTHONIC_DISPATCH_REVERSE_HPP
#define PYTHONIC_DISPATCH_REVERSE_HPP

#include "pythonic/include/__dispatch__/reverse.hpp"

PYTHONIC_NS_BEGIN

namespace __dispatch__
{
  template <class Any, class... Arg0>
  auto reverse(Any &&any, Arg0 &&... arg0)
    -> decltype(any.reverse(std::forward<Arg0>(arg0)...))
  {
    return any.reverse(std::forward<Arg0>(arg0)...);
  }
}

PYTHONIC_NS_END

#endif
