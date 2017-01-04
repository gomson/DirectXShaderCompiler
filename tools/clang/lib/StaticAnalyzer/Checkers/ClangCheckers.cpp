//===--- ClangCheckers.h - Provides builtin checkers ------------*- C++ -*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// ClangCheckers.cpp                                                         //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "clang/StaticAnalyzer/Checkers/ClangCheckers.h"
#include "clang/StaticAnalyzer/Core/CheckerRegistry.h"

// FIXME: This is only necessary as long as there are checker registration
// functions that do additional work besides mgr.registerChecker<CLASS>().
// The only checkers that currently do this are:
// - NSAutoreleasePoolChecker
// - NSErrorChecker
// - ObjCAtSyncChecker
// It's probably worth including this information in Checkers.td to minimize
// boilerplate code.
#include "ClangSACheckers.h"

using namespace clang;
using namespace ento;

void ento::registerBuiltinCheckers(CheckerRegistry &registry) {
#define GET_CHECKERS
#define CHECKER(FULLNAME,CLASS,DESCFILE,HELPTEXT,GROUPINDEX,HIDDEN)    \
  registry.addChecker(register##CLASS, FULLNAME, HELPTEXT);
#include "Checkers.inc"
#undef GET_CHECKERS
}