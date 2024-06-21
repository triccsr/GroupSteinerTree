/* iostream specialisations for result and outcome
(C) 2017-2024 Niall Douglas <http://www.nedproductions.biz/> (21 commits)
File Created: July 2017


Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef BOOST_OUTCOME_IOSTREAM_SUPPORT_HPP
#define BOOST_OUTCOME_IOSTREAM_SUPPORT_HPP

#include "outcome.hpp"

#include <iostream>
#include <sstream>

BOOST_OUTCOME_V2_NAMESPACE_BEGIN

namespace detail
{
  template <class T> typename std::add_lvalue_reference<T>::type lvalueref() noexcept;

  template <template <class, class> class ValueStorage, class T, class E> inline std::ostream &value_storage_out(std::ostream &s, const ValueStorage<T, E> &v)
  {
    s << static_cast<uint16_t>(v._status.status_value) << " " << v._status.spare_storage_value << " ";
    if(v._status.have_value())
    {
      s << v._value;  // NOLINT
    }
    if(v._status.have_error())
    {
      s << v._error;  // NOLINT
    }
    return s;
  }
  template <template <class, class> class ValueStorage, class E> inline std::ostream &value_storage_out(std::ostream &s, const ValueStorage<void, E> &v)
  {
    s << static_cast<uint16_t>(v._status.status_value) << " " << v._status.spare_storage_value << " ";
    if(v._status.have_error())
    {
      s << v._error;  // NOLINT
    }
    return s;
  }
  template <template <class, class> class ValueStorage, class T> inline std::ostream &value_storage_out(std::ostream &s, const ValueStorage<T, void> &v)
  {
    s << static_cast<uint16_t>(v._status.status_value) << " " << v._status.spare_storage_value << " ";
    if(v._status.have_value())
    {
      s << v._value;  // NOLINT
    }
    return s;
  }

  template <class T, class E> inline std::ostream &operator<<(std::ostream &s, const value_storage_trivial<T, E> &v) { return value_storage_out(s, v); }
  template <class T, class E> inline std::ostream &operator<<(std::ostream &s, const value_storage_nontrivial<T, E> &v) { return value_storage_out(s, v); }

  template <template <class, class> class ValueStorage, class T, class E> inline std::istream &value_storage_in(std::istream &s, ValueStorage<T, E> &v)
  {
    using type = ValueStorage<T, E>;
    v.~type();
    new(&v) type;
    uint16_t x, y;
    s >> x >> y;
    v._status.status_value = static_cast<detail::status>(x);
    v._status.spare_storage_value = y;
    if(v._status.have_value())
    {
      new(BOOST_OUTCOME_ADDRESS_OF(v._value)) decltype(v._value)();  // NOLINT
      s >> v._value;                                       // NOLINT
    }
    if(v._status.have_error())
    {
      new(BOOST_OUTCOME_ADDRESS_OF(v._error)) decltype(v._error)();  // NOLINT
      s >> v._error;                                       // NOLINT
    }
    return s;
  }
  template <template <class, class> class ValueStorage, class E> inline std::istream &value_storage_in(std::istream &s, ValueStorage<void, E> &v)
  {
    using type = ValueStorage<void, E>;
    v.~type();
    new(&v) type;
    uint16_t x, y;
    s >> x >> y;
    v._status.status_value = static_cast<detail::status>(x);
    v._status.spare_storage_value = y;
    if(v._status.have_error())
    {
      new(BOOST_OUTCOME_ADDRESS_OF(v._error)) decltype(v._error)();  // NOLINT
      s >> v._error;                                       // NOLINT
    }
    return s;
  }
  template <template <class, class> class ValueStorage, class T> inline std::istream &value_storage_in(std::istream &s, ValueStorage<T, void> &v)
  {
    using type = ValueStorage<T, void>;
    v.~type();
    new(&v) type;
    uint16_t x, y;
    s >> x >> y;
    v._status.status_value = static_cast<detail::status>(x);
    v._status.spare_storage_value = y;
    if(v._status.have_value())
    {
      new(BOOST_OUTCOME_ADDRESS_OF(v._value)) decltype(v._value)();  // NOLINT
      s >> v._value;                                       // NOLINT
    }
    return s;
  }
  template <class T, class E> inline std::istream &operator>>(std::istream &s, value_storage_trivial<T, E> &v) { return value_storage_in(s, v); }
  template <class T, class E> inline std::istream &operator>>(std::istream &s, value_storage_nontrivial<T, E> &v) { return value_storage_in(s, v); }
  BOOST_OUTCOME_TEMPLATE(class T)
  BOOST_OUTCOME_TREQUIRES(BOOST_OUTCOME_TPRED(!std::is_constructible<std::error_code, T>::value))
  inline std::string safe_message(T && /*unused*/) { return {}; }
  inline std::string safe_message(const std::error_code &ec) { return " (" + ec.message() + ")"; }
}  // namespace detail

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
BOOST_OUTCOME_TEMPLATE(class R, class S, class P)
BOOST_OUTCOME_TREQUIRES(BOOST_OUTCOME_TEXPR(detail::lvalueref<std::istream>() >> detail::lvalueref<R>()), BOOST_OUTCOME_TEXPR(detail::lvalueref<std::istream>() >> detail::lvalueref<S>()))
inline std::istream &operator>>(std::istream &s, basic_result<R, S, P> &v)
{
  s >> v._iostreams_state();
  if(v.has_error())
  {
    s >> v.assume_error();
  }
  return s;
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
BOOST_OUTCOME_TEMPLATE(class R, class S, class P)
BOOST_OUTCOME_TREQUIRES(BOOST_OUTCOME_TEXPR(detail::lvalueref<std::ostream>() << detail::lvalueref<R>()), BOOST_OUTCOME_TEXPR(detail::lvalueref<std::ostream>() << detail::lvalueref<S>()))
inline std::ostream &operator<<(std::ostream &s, const basic_result<R, S, P> &v)
{
  s << v._iostreams_state();
  if(v.has_error())
  {
    s << v.assume_error();
  }
  return s;
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class R, class S, class P> inline std::string print(const basic_result<R, S, P> &v)
{
  std::stringstream s;
  if(v.has_value())
  {
    s << v.value();
  }
  if(v.has_error())
  {
    s << v.error() << detail::safe_message(v.error());
  }
  return s.str();
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class S, class P> inline std::string print(const basic_result<void, S, P> &v)
{
  std::stringstream s;
  if(v.has_value())
  {
    s << "(+void)";
  }
  if(v.has_error())
  {
    s << v.error() << detail::safe_message(v.error());
  }
  return s.str();
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class R, class P> inline std::string print(const basic_result<R, void, P> &v)
{
  std::stringstream s;
  if(v.has_value())
  {
    s << v.value();
  }
  if(v.has_error())
  {
    s << "(-void)";
  }
  return s.str();
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class P> inline std::string print(const basic_result<void, void, P> &v)
{
  std::stringstream s;
  if(v.has_value())
  {
    s << "(+void)";
  }
  if(v.has_error())
  {
    s << "(-void)";
  }
  return s.str();
}

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
BOOST_OUTCOME_TEMPLATE(class R, class S, class P, class N)
BOOST_OUTCOME_TREQUIRES(BOOST_OUTCOME_TEXPR(detail::lvalueref<std::istream>() >> detail::lvalueref<R>()), BOOST_OUTCOME_TEXPR(detail::lvalueref<std::istream>() >> detail::lvalueref<S>()), BOOST_OUTCOME_TEXPR(detail::lvalueref<std::istream>() >> detail::lvalueref<P>()))
inline std::istream &operator>>(std::istream &s, outcome<R, S, P, N> &v)
{
  s >> v._iostreams_state();
  if(v.has_error())
  {
    s >> v.assume_error();
  }
  if(v.has_exception())
  {
    s >> v.assume_exception();
  }
  return s;
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
BOOST_OUTCOME_TEMPLATE(class R, class S, class P, class N)
BOOST_OUTCOME_TREQUIRES(BOOST_OUTCOME_TEXPR(detail::lvalueref<std::ostream>() << detail::lvalueref<R>()), BOOST_OUTCOME_TEXPR(detail::lvalueref<std::ostream>() << detail::lvalueref<S>()), BOOST_OUTCOME_TEXPR(detail::lvalueref<std::ostream>() << detail::lvalueref<P>()))
inline std::ostream &operator<<(std::ostream &s, const outcome<R, S, P, N> &v)
{
  s << v._iostreams_state();
  if(v.has_error())
  {
    s << v.assume_error();
  }
  if(v.has_exception())
  {
    s << v.assume_exception();
  }
  return s;
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class R, class S, class P, class N> inline std::string print(const outcome<R, S, P, N> &v)
{
  std::stringstream s;
  int total = static_cast<int>(v.has_value()) + static_cast<int>(v.has_error()) + static_cast<int>(v.has_exception());
  if(total > 1)
  {
    s << "{ ";
  }
  s << print(static_cast<const basic_result<R, S, N> &>(static_cast<const detail::basic_result_final<R, S, N> &>(v)));  // NOLINT
  if(total > 1)
  {
    s << ", ";
  }
  if(v.has_exception())
  {
#ifndef BOOST_NO_EXCEPTIONS
    try
    {
      rethrow_exception(v.exception());
    }
    catch(const std::system_error &e)
    {
      s << "std::system_error code " << e.code() << ": " << e.what();
    }
    catch(const std::exception &e)
    {
      s << "std::exception: " << e.what();
    }
    catch(...)
#endif
    {
      s << "unknown exception";
    }
  }
  if(total > 1)
  {
    s << " }";
  }
  return s.str();
}
BOOST_OUTCOME_V2_NAMESPACE_END

#endif
