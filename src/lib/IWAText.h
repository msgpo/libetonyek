/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libetonyek project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef IWATEXT_H_INCLUDED
#define IWATEXT_H_INCLUDED

#include <map>
#include <string>

#include <boost/shared_ptr.hpp>

namespace libetonyek
{

class IWORKStyle;
class IWORKText;

class IWAText
{
public:
  explicit IWAText(const std::string text);

  void setParagraphs(const std::map<unsigned, boost::shared_ptr<IWORKStyle> > &paras);
  void setSpans(const std::map<unsigned, boost::shared_ptr<IWORKStyle> > &spans);
  void setLanguages(const std::map<unsigned, std::string> &langs);

  void parse(IWORKText &collector);

private:
  const std::string m_text;

  std::map<unsigned, boost::shared_ptr<IWORKStyle> > m_paras;
  std::map<unsigned, boost::shared_ptr<IWORKStyle> > m_spans;
  std::map<unsigned, std::string> m_langs;
};

}

#endif

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
