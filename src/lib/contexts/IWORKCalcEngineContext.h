/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libetonyek project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef IWORKCALCENGINECONTEXT_H_INCLUDED
#define IWORKCALCENGINECONTEXT_H_INCLUDED

#include "IWORKXMLContextBase.h"

namespace libetonyek
{

class IWORKCalcEngineContext : public IWORKXMLElementContextBase
{
public:
  explicit IWORKCalcEngineContext(IWORKXMLParserState &state);

protected:
  IWORKXMLContextPtr_t element(int name) override;
};

}

#endif // IWORKCALCENGINECONTEXT_H_INCLUDED

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
