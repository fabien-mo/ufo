/*
 * (C) Copyright 2017-2020 UCAR
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 */

#include "oops/interface/ObsFilter.h"
#include "oops/runs/Run.h"
#include "ufo/filters/AutogeneratedFilter.h"
#include "ufo/instantiateObsFilterFactory.h"
#include "ufo/ObsTraits.h"
#include "test/ufo/ObsFilters.h"

int main(int argc,  char ** argv) {
  oops::FilterMaker<ufo::ObsTraits, oops::ObsFilter<ufo::ObsTraits, ufo::AutogeneratedFilter> >
      maker("Autogenerated");

  oops::Run run(argc, argv);
  ufo::instantiateObsFilterFactory<ufo::ObsTraits>();
  ufo::test::ObsFilters tests;
  return run.execute(tests);
}
