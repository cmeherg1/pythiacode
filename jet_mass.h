#ifndef MAKENTUPLEFROMPYTHIA_H
#define MAKENTUPLEFROMPYTHIA_H

#define CERRD cout<<"Problem on "<<__FILE__<<"  "<<__LINE__<<endl;

//#include <TROOT.h>
//#include "TFile.h"
//#include "TTree.h"
//#include "TH1D.h"

#include <vector>
#include <string>

#include "Pythia8/Pythia.h"

//used for the output particle ntuple

std::vector<int>    fspart_id;
std::vector<double> fspart_px;
std::vector<double> fspart_py;
std::vector<double> fspart_pz;
std::vector<double> fspart_e;

int truth_q1_id;
double truth_q1_px;
double truth_q1_py;
double truth_q1_pz;
double truth_q1_e;

int truth_q2_id;
double truth_q2_px;
double truth_q2_py;
double truth_q2_pz;
double truth_q2_e;

#endif

