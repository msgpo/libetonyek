/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libetonyek project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef IWORKXMLCONTEXTBASE_H_INCLUDED
#define IWORKXMLCONTEXTBASE_H_INCLUDED

#include <boost/enable_shared_from_this.hpp>
#include <boost/optional.hpp>

#include "IWORKXMLContext.h"
#include "IWORKTypes_fwd.h"

namespace libetonyek
{

class IWORKXMLParserState;

class IWORKCollector;

template<class Base, class State, class Collector = IWORKCollector>
class IWORKXMLContextBase : public Base
{
public:
  explicit IWORKXMLContextBase(State &state)
    : Base(state)
    , m_state(state)
  {
  }

  template<typename T>
  IWORKXMLContextBase(State &state, const T &a)
    : Base(state, a)
    , m_state(state)
  {
  }

  State &getState()
  {
    return m_state;
  }

protected:
  Collector &getCollector() const
  {
    return m_state.getCollector();
  }

  int getToken(const char *const value) const
  {
    return m_state.getTokenizer().getId(value);
  }

  bool isCollector() const
  {
    return m_state.m_enableCollector;
  }

protected:
  State &m_state;
};

class IWORKXMLContextMinimal : public IWORKXMLContext
{
protected:
  IWORKXMLContextMinimal();

  void startOfElement() override;
  void endOfElement() override;
};

class IWORKXMLContextElement : public IWORKXMLContextMinimal, public boost::enable_shared_from_this<IWORKXMLContextElement>
{
protected:
  explicit IWORKXMLContextElement(IWORKXMLParserState &);

  void attribute(int name, const char *value) override;
  void text(const char *value) override;

  const boost::optional<ID_t> &getId() const;
  void setId(const char *value);

private:
  boost::optional<ID_t> m_id;
};

class IWORKXMLContextText : public IWORKXMLContextMinimal
{
protected:
  explicit IWORKXMLContextText(IWORKXMLParserState &);

  IWORKXMLContextPtr_t element(int token) override;
};

class IWORKXMLContextMixed : public IWORKXMLContextMinimal, public boost::enable_shared_from_this<IWORKXMLContextMixed>
{
protected:
  explicit IWORKXMLContextMixed(IWORKXMLParserState &);
};

class IWORKXMLContextEmpty : public IWORKXMLContextMinimal
{
protected:
  explicit IWORKXMLContextEmpty(IWORKXMLParserState &);

  void attribute(int name, const char *value) override;
  IWORKXMLContextPtr_t element(int token) override;
  void text(const char *value) override;

  const boost::optional<ID_t> &getId() const;
  void setId(const char *value);
  const boost::optional<ID_t> &getRef() const;

private:
  boost::optional<ID_t> m_id;
  boost::optional<ID_t> m_ref;
};

typedef IWORKXMLContextBase<IWORKXMLContextElement, IWORKXMLParserState> IWORKXMLElementContextBase;
typedef IWORKXMLContextBase<IWORKXMLContextText, IWORKXMLParserState> IWORKXMLTextContextBase;
typedef IWORKXMLContextBase<IWORKXMLContextMixed, IWORKXMLParserState> IWORKXMLMixedContextBase;
typedef IWORKXMLContextBase<IWORKXMLContextEmpty, IWORKXMLParserState> IWORKXMLEmptyContextBase;

}

#endif // IWORKXMLCONTEXTBASE_H_INCLUDED

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
