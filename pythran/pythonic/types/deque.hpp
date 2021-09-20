#ifndef PYTHONIC_TYPES_DEQUE_HPP
#define PYTHONIC_TYPES_DEQUE_HPP

#include "pythonic/include/types/deque.hpp"

#include "pythonic/utils/shared_ref.hpp"

#include <algorithm>

PYTHONIC_NS_BEGIN

namespace types
{
  template <class T>
  deque<T>::deque()
    : data(utils::no_memory())
  {
  }

  template <class T>
  deque<T>::deque(deque<T>::size_type sz)
    : data(sz)
  {
  }

  template <class T>
  deque<T>::deque(std::initializer_list<T> l)
    : data(std::move(l))
  {
  }

  template <class T>
  template <class InputIterator>
  deque<T>::deque(InputIterator start, InputIterator stop)
    : data()
  {
    std::copy(start, stop, std::back_inserter(*data));
  }

  template <class T>
  typename deque<T>::iterator deque<T>::begin()
  {
    return data->begin();
  }

  template <class T>
  typename deque<T>::iterator deque<T>::end()
  {
    return data->end();
  }

  template <class T>
  typename deque<T>::reference deque<T>::fast(long n)
  {
    return (*data)[n];
  }

  template <class T>
  typename deque<T>::reference deque<T>::operator[](long n)
  {
    if (n < 0)
      n += size();
    return fast(n);
  }

  template <class T>
  typename deque<T>::const_reference deque<T>::fast(long n) const
  {
    return (*data)[n];
  }

  template <class T>
  typename deque<T>::const_reference deque<T>::operator[](long n) const
  {
    if (n < 0)
      n += size();
    return fast(n);
  }

  template <class T>
  long deque<T>::size() const
  {
    return data->size();
  }

  template <class T>
  template <class Tp>
  void deque<T>::push_back(Tp &&x)
  {
    data->push_back(std::forward<Tp>(x));
  }

  template <class T>
  template <class Tp>
  void deque<T>::push_front(Tp &&x)
  {
    data->push_front(std::forward<Tp>(x));
  }

  template <class T>
  none_type deque<T>::append(T const &x)
  {
    data->push_back(x);
    return {};
  }
}

#ifdef ENABLE_PYTHON_MODULE

template <class T>
PyObject *to_python<types::deque<T>>::convert(types::deque<T> const &v)
{
  PyObject *collections_mod = PyImport_ImportModule("collections");
  PyObject *deque_class = PyObject_GetAttrString(collections_mod, "deque");
  PyObject *empty_tuple = PyTuple_New(0);
  PyObject *arg_tuple = PyTuple_New(1);

  PyObject *ret = PyObject_Call(deque_class, empty_tuple, NULL);
  Py_DECREF(empty_tuple);

  PyObject *append_func = PyObject_GetAttrString(ret, "append");

  for (Py_ssize_t i = 0; i < v.size(); i++) {
    PyTuple_SetItem(arg_tuple, 0, ::to_python(v[i]));
    PyObject_Call(append_func, arg_tuple, NULL);
  }

  Py_DECREF(arg_tuple);
  Py_DECREF(append_func);
  Py_DECREF(deque_class);
  Py_DECREF(collections_mod);

  return ret;
}

template <class T>
bool from_python<types::deque<T>>::is_convertible(PyObject *obj)
{
  PyObject *collections_mod = PyImport_ImportModule("collections");
  PyObject *deque_class = PyObject_GetAttrString(collections_mod, "deque");

  bool ret = PyObject_IsInstance(obj, deque_class) &&
    (PyObject_Not(obj) || ::is_convertible<T>(PySequence_Fast_GET_ITEM(obj, 0)));

  Py_DECREF(deque_class);
  Py_DECREF(collections_mod);

  return ret;
}

template <class T>
types::deque<T> from_python<types::deque<T>>::convert(PyObject *obj)
{
  Py_ssize_t l = PySequence_Fast_GET_SIZE(obj);
  types::deque<T> v(l);

  PyObject **core = PySequence_Fast_ITEMS(obj);
  std::transform(core, core + l, v.begin(),
		 [](PyObject *o) { return ::from_python<T>(o); });

  return v;
}

#endif

PYTHONIC_NS_END

#endif
