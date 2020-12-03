#include "FMu.C"

int main(){

TChain *chain = new TChain("FourMu_tree","");
//Ntuples with gen filter
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/GEN_MC/Double_Jpsi/Noetaptrootfiles/7Nov2020_DPSJJ_WITH_genfilter_2018_NO_etptcut.root");


FourMu_tree* a = new FourMu_tree(chain);




 a->Loop();
    
}
