//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "IMPRES_DEERTestApp.h"
#include "IMPRES_DEERApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
IMPRES_DEERTestApp::validParams()
{
  InputParameters params = IMPRES_DEERApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

IMPRES_DEERTestApp::IMPRES_DEERTestApp(InputParameters parameters) : MooseApp(parameters)
{
  IMPRES_DEERTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

IMPRES_DEERTestApp::~IMPRES_DEERTestApp() {}

void
IMPRES_DEERTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  IMPRES_DEERApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"IMPRES_DEERTestApp"});
    Registry::registerActionsTo(af, {"IMPRES_DEERTestApp"});
  }
}

void
IMPRES_DEERTestApp::registerApps()
{
  registerApp(IMPRES_DEERApp);
  registerApp(IMPRES_DEERTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
IMPRES_DEERTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  IMPRES_DEERTestApp::registerAll(f, af, s);
}
extern "C" void
IMPRES_DEERTestApp__registerApps()
{
  IMPRES_DEERTestApp::registerApps();
}
