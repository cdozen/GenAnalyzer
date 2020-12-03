#include "gen_tree.C"
#include "TTree.h"
#include "TChain.h"
void Loader(){
TChain *chain = new TChain("GenAnalyzer/gen_tree","");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_1.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_2.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_3.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_4.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_5.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_6.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_7.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_8.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_9.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_10.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_11.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_12.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_13.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_14.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_15.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_16.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_17.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_18.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_19.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_20.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_21.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_22.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_23.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_24.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_25.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_26.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_27.root"); 
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_132138/0000/DPS_JJ_noGenFilter_28.root"); 

gen_tree a(chain);
 a.Loop();
   
}
