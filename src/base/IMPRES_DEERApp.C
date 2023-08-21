#include "IMPRES_DEERApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
IMPRES_DEERApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

IMPRES_DEERApp::IMPRES_DEERApp(InputParameters parameters) : MooseApp(parameters)
{
  IMPRES_DEERApp::registerAll(_factory, _action_factory, _syntax);
}

IMPRES_DEERApp::~IMPRES_DEERApp() {}

void 
IMPRES_DEERApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<IMPRES_DEERApp>(f, af, s);
  Registry::registerObjectsTo(f, {"IMPRES_DEERApp"});
  Registry::registerActionsTo(af, {"IMPRES_DEERApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
IMPRES_DEERApp::registerApps()
{
  registerApp(IMPRES_DEERApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
IMPRES_DEERApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  IMPRES_DEERApp::registerAll(f, af, s);
}
extern "C" void
IMPRES_DEERApp__registerApps()
{
  IMPRES_DEERApp::registerApps();
}
