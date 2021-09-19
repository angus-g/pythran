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

  public:
    using reference = typename container_type::reference;
    using const_reference = typename container_type::const_reference;
    using iterator = typename container_type::iterator;
    using size_type = typename container_type::size_type;

    deque();
    deque(size_type sz);
    deque(std::initializer_list<T> l);

    template <class InputIterator>
    deque(InputIterator start, InputIterator stop);

    iterator begin();
    iterator end();

    reference fast(long n);
    reference operator[](long n);
    const_reference fast(long n) const;
    const_reference operator[](long n) const;

    long size() const;
  };
}

#ifdef ENABLE_PYTHON_MODULE

template <class T>
struct to_python<types::deque<T>> {
  static PyObject *convert(types::deque<T> const &v);
};

template <class T>
struct from_python<types::deque<T>> {
  static bool is_convertible(PyObject *obj);
  static types::deque<T> convert(PyObject *obj);
};

#endif

PYTHONIC_NS_END

#endif
