/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libkeynote project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "KN1Parser.h"
#include "KN1Token.h"
#include "KNXMLReader.h"

namespace libkeynote
{

KN1Parser::KN1Parser(const WPXInputStreamPtr_t &input, const WPXInputStreamPtr_t &, KNCollector *const collector, const KNDefaults &defaults)
  : KNParser(input, collector, defaults)
{
}

KN1Parser::~KN1Parser()
{
}

void KN1Parser::processXmlNode(const KNXMLReader &reader)
{
  // TODO: implement me
  (void) reader;
}

KNXMLReader::TokenizerFunction_t KN1Parser::getTokenizer() const
{
  return KN1Tokenizer();
}

}

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
