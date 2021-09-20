#ifndef PYTHONIC_INCLUDE_DISPATCH_APPEND_HPP
#define PYTHONIC_INCLUDE_DISPATCH_APPEND_HPP

#include "pythonic/include/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace __dispatch__
{
  template <class Any, class... Arg0>
  auto append(Any &&any, Arg0 &&... arg0)
    -> decltype(any.append(std::forward<Arg0>(arg0)...));

  DEFINE_FUNCTOR(pythonic::__dispatch__, append);
}
PYTHONIC_NS_END

#endif
