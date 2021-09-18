#ifndef PYTHONIC_DISPATCH_EXTEND_HPP
#define PYTHONIC_DISPATCH_EXTEND_HPP

#include "pythonic/include/__dispatch__/extend.hpp"

PYTHONIC_NS_BEGIN

namespace __dispatch__
{
  template <class Any, class... Arg0>
  auto extend(Any &&any, Arg0 &&... arg0)
    -> decltype(any.extend(std::forward<Arg0>(arg0)...))
  {
    return any.extend(std::forward<Arg0>(arg0)...);
  }
}

PYTHONIC_NS_END

#endif
