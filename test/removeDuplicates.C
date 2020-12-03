#include <iostream>
#include <set>

void removeDuplicates() {

    TString filename = "SPS_JJ_2018_pythia8_noGenCut_30Nov2020_v3_doublevector.root";

    std::cout<<filename<<std::endl;

    TFile *oldfile = new TFile(filename);
    //TTree *oldtree = (TTree*)oldfile->Get("oniaTree");
    TTree *oldtree = (TTree*)oldfile->Get("GenAnalyzer/gen_tree");

    Long64_t nentries = oldtree->GetEntries();
    std::cout<<nentries<<" total entries."<<std::endl;
    Int_t nRun, nLumi, nEvent;
    oldtree->SetBranchAddress("nRun",&nRun);
    oldtree->SetBranchAddress("nLumi",&nLumi);
    oldtree->SetBranchAddress("nEvent",&nEvent);
    //Create a new file + a clone of old tree in new file
    TFile *newfile = new TFile("SPS_JJ_2018_pythia8_noGenCut_30Nov2020_v3_doublevector_NoDuplicate.root","recreate");
    TTree *newtree = oldtree->CloneTree(0);
    std::set<TString> runlumieventSet;
    int nremoved = 0;
    for (Long64_t i=0;i<nentries; i++) {
        if (i%100==0) std::cout<<'\r'<<"Number of entries:  "<<i<<" / "<<nentries<<flush;
            //std::cout<<i<<"/"<<nentries<<std::endl;
        oldtree->GetEntry(i);

        TString s_Run  = std::to_string(nRun);
        TString s_Lumi = std::to_string(nLumi);
        TString s_Event = std::to_string(nEvent);
        TString runlumievent = s_Run+":"+s_Lumi+":"+s_Event;
        
        if (runlumieventSet.find(runlumievent)==runlumieventSet.end()) {
            runlumieventSet.insert(runlumievent);
            newtree->Fill();
        } else {
            nremoved++;
        }
    }

    std::cout<<nremoved<<" duplicates."<<std::endl;
    newtree->Print();
    newtree->AutoSave();
    delete oldfile;
    delete newfile;
}


