#ifndef PYTHONIC_INCLUDE_DISPATCH_EXTEND_HPP
#define PYTHONIC_INCLUDE_DISPATCH_EXTEND_HPP

#include "pythonic/include/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace __dispatch__
{
  template <class Any, class... Arg0>
  auto extend(Any &&any, Arg0 &&... arg0)
    -> decltype(any.extend(std::forward<Arg0>(arg0)...));

  DEFINE_FUNCTOR(pythonic::__dispatch__, extend);
}
PYTHONIC_NS_END

#endif
