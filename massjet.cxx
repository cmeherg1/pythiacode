
//#include "jet_mass.h"

// #include <utility>
// #include <iomanip>


// FastJet
#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequence.hh"

// Pythia
#include "Pythia8/Pythia.h"

using namespace Pythia8;
using namespace fastjet;

int main()
{
    string ConfigFile = "config_hadronicZjet_ATLAS_13TeV.cmnd";
    int charge_id;
    //int nEvents = 100;
    int nEvents = 50000;

    Pythia pythia;
    pythia.readFile(ConfigFile);
    pythia.init();
    
    // Fastjet analysis - select algorithm and parameters
    double Rparam = 0.8;
    vector<fastjet::PseudoJet> input_particles;

    std::vector<fastjet::PseudoJet> particles;

    fastjet::Strategy               strategy = fastjet::Best;
    fastjet::RecombinationScheme    recombScheme = fastjet::E_scheme;
    fastjet::JetDefinition         *jetDef = NULL;

    jetDef = new fastjet::JetDefinition(fastjet::antikt_algorithm, Rparam, recombScheme, strategy);
    // Do not forget to free memenory afterwards

    // The fun starts here ;)
    Hist masshist("Jet Masses", 80,0.0,140);
    for (int i = 0; i < nEvents ; ++i)
    {
        if (!pythia.next()) continue;

        double esum = 0;
        input_particles.clear();

        for(int j = 0; j < pythia.event.size(); j++){
            if(pythia.event[j].isFinal()){
                px = pythia.event[j].px();
                py = pythia.event[j].py();
                pz = pythia.event[j].pz();
                e = pythia.event[j].e();
                input_particles.push_back(fastjet::PseudoJet(px,py,pz,e));
            
                esum += e;
            }
            
            
        }
        
        fastjet::ClusterSequence cs(input_particles, *jetDef);
        vector<fastjet::PseudoJet> alljets = sorted_by_pt(cs.inclusive_jets(500.0));
        
        masshist.fill(alljets[0].m());
    }

    // Write your FastJet analysis here
    delete jetDef;


    HistPlot hpl("massplot2");
    hpl.plotFrame("massplot3", masshist, "$m_{J}$ from boosted Z boson",
    "$m_{J}$ (GeV)",
    "Arbitrary Units",
    "h", "Number of jets = " );
    hpl.plot();
    return 0;
}


