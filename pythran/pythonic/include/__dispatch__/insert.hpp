#ifndef PYTHONIC_INCLUDE_DISPATCH_INSERT_HPP
#define PYTHONIC_INCLUDE_DISPATCH_INSERT_HPP

#include "pythonic/include/utils/functor.hpp"

PYTHONIC_NS_BEGIN

namespace __dispatch__
{
  template <class Any, class... Arg0>
  auto insert(Any &&any, Arg0 &&... arg0)
    -> decltype(any.insert(std::forward<Arg0>(arg0)...));

  DEFINE_FUNCTOR(pythonic::__dispatch__, insert);
}
PYTHONIC_NS_END

#endif
