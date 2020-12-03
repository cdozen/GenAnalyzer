#include "tester.C"
//#include "gen_tree.C"
//#include "gen_tree_withmucharge.C"

int main(){

TChain *chain = new TChain("GenAnalyzer/gen_tree","");
chain->AddFile("../SPS_JJ_2018_pythia8_noGenCut_30Nov2020_v3_doublevector.root");
//chain->AddFile("../SPS_JJ_2018_pythia8_noGenCut_30Nov2020_v3_doublevector_NoDuplicate.root");
//chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/SPS_JJ_2018_pythia8_Ntuples_v2/noGenCut/SPSToJJ_13TeV_pythia8/crab_crabOutput2018_SPS_JJ_v2/SPS_JJ_2018_pythia8_noGenCut_27Nov2020.root");
//chain->AddFile("../SPS_JJ_2018_pythia8_noGenCut_27Nov2020.root");

//Ntuples with gen filter
/*chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_1.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_2.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_3.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_4.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_5.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_6.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_7.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_8.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_9.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_10.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_11.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_12.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_13.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_14.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_15.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_16.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_17.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_18.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_19.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter_v2/DPSTo4mu_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_withgenfilter/201107_133922/0000/ROOTDiles_DPS_JJ_withGenFilter_7Nov2020_20.root");


*/

//no gen filter//

/*chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_1.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_2.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_3.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_4.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_5.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_6.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_7.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_8.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_9.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_10.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_11.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_12.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_13.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_14.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_15.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_16.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_17.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_18.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_19.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_20.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_21.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_22.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_23.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_24.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_25.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_26.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_27.root");
chain->AddFile("root://cmsxrootd.fnal.gov//store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/No_GenFilter_v2/DPSToJJ_13TeV_pythia8/crab_crabOutput2018_DPSMCJJ_NoGenCut/201016_183241/0000/DPS_JJ_noGenFilter_28.root");
*/





tester* a =new tester(chain);
//gen_tree* a =new gen_tree(chain);




 a->Loop();
    
}
