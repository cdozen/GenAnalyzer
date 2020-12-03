//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Oct 16 21:10:47 2020 by ROOT version 6.22/02
// from TTree gen_tree/gen tree
// found on file: DPS_JJ_noGenFilter_1.root
//////////////////////////////////////////////////////////

#ifndef gen_tree_h
#define gen_tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
using namespace std;
class gen_tree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           GENfinalState;
   Bool_t          passedFiducialSelection;
   vector<int>     *GEN_barcode;
   vector<int>     *GEN_Nmother;
   vector<int>     *GEN_Ndaughter;
   vector<int>     *GEN_pdgID;
   vector<double>  *GEN_pt;
   vector<double>  *GEN_eta;
   vector<double>  *GEN_phi;
   vector<double>  *GEN_rapidity;
   vector<double>  *GEN_mass;
   vector<int>     *GEN_status;
   vector<vector<int> > *GEN_Daughter_pdgID;
   vector<vector<int> > *GEN_Mother_pdgID;
   vector<vector<int> > *GEN_Mom_barcode;
   vector<vector<int> > *GEN_Dau_barcode;
   
   vector<double>  *GENmu_pt;
   vector<double>  *GENmu_eta;
   vector<double>  *GENmu_phi;
   vector<double>  *GENmu_mass;
   vector<int>     *GENmu_id;
   vector<int>     *GENmu_status;
   vector<int>     *GENmu_MomId;
   vector<int>     *GENmu_MomMomId;

   vector<vector<int> >    *GENups_DaughtersId;
   vector< vector<double>   > *GENups_Daughter_mupt;
   vector<vector<double> > *GENups_Daughter_mueta;
   vector<vector<double> > *GENups_Daughter_murapidity;
   vector<vector<double> > *GENups_Daughter_muphi;
   vector<vector<double> > *GENups_Daughter_mumass;
   vector<vector<int> >    *GENups_Daughter_muid;
   vector<vector<double> > *GENups_Daughter_mustatus;
   vector<vector<int> >    *GENups_Daughter_barcode;
   vector<int>     *GENups_barcode;
   vector<int>     *GENups_MomId;
   vector<int>     *GENups_Mom_barcode;
   vector<double>  *GENups_pt;
   vector<double>  *GENups_eta;
   vector<double>  *GENups_y;
   vector<double>  *GENups_phi;
   vector<double>  *GENups_mass;
   vector<int>     *GENups_ID;
   vector<int>     *GENups_NDaughters;

   // List of branches
   TBranch        *b_GENfinalState;   //!
   TBranch        *b_passedFiducialSelection;   //!
   TBranch        *b_GEN_barcode;   //!
   TBranch        *b_GEN_Nmother;   //!
   TBranch        *b_GEN_Ndaughter;   //!
   TBranch        *b_GEN_pdgID;   //!
   TBranch        *b_GEN_pt;   //!
   TBranch        *b_GEN_eta;   //!
   TBranch        *b_GEN_phi;   //!
   TBranch        *b_GEN_rapidity;   //!
   TBranch        *b_GEN_mass;   //!
   TBranch        *b_GEN_status;   //!
   TBranch        *b_GEN_Daughter_pdgID;   //!
   TBranch        *b_GEN_Mother_pdgID;   //!
   TBranch        *b_GEN_Mom_barcode;   //!
   TBranch        *b_GEN_Dau_barcode;   //!
   TBranch        *b_GENmu_pt;   //!
   TBranch        *b_GENmu_eta;   //!
   TBranch        *b_GENmu_phi;   //!
   TBranch        *b_GENmu_mass;   //!
   TBranch        *b_GENmu_id;   //!
   TBranch        *b_GENmu_status;   //!
   TBranch        *b_GENmu_MomId;   //!
   TBranch        *b_GENmu_MomMomId;   //!
   TBranch        *b_GENups_DaughtersId;   //!
   TBranch        *b_GENups_Daughter_mupt;   //!
   TBranch        *b_GENups_Daughter_mueta;   //!
   TBranch        *b_GENups_Daughter_murapidity;   //!
   TBranch        *b_GENups_Daughter_muphi;   //!
   TBranch        *b_GENups_Daughter_mumass;   //!
   TBranch        *b_GENups_Daughter_muid;   //!
   TBranch        *b_GENups_Daughter_mustatus;   //!
   TBranch        *b_GENups_Daughter_barcode;   //!
   TBranch        *b_GENups_barcode;   //!
   TBranch        *b_GENups_MomId;   //!
   TBranch        *b_GENups_Mom_barcode;   //!
   TBranch        *b_GENups_pt;   //!
   TBranch        *b_GENups_eta;   //!
   TBranch        *b_GENups_y;   //!
   TBranch        *b_GENups_phi;   //!
   TBranch        *b_GENups_mass;   //!
   TBranch        *b_GENups_ID;   //!
   TBranch        *b_GENups_NDaughters;   //!

   gen_tree(TTree *tree=0);
   virtual ~gen_tree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef gen_tree_cxx
gen_tree::gen_tree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DPS_JJ_noGenFilter_1.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("DPS_JJ_noGenFilter_1.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("DPS_JJ_noGenFilter_1.root:/GenAnalyzer");
      dir->GetObject("gen_tree",tree);

   }
   Init(tree);
}

gen_tree::~gen_tree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t gen_tree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t gen_tree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void gen_tree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   GEN_barcode = 0;
   GEN_Nmother = 0;
   GEN_Ndaughter = 0;
   GEN_pdgID = 0;
   GEN_pt = 0;
   GEN_eta = 0;
   GEN_phi = 0;
   GEN_rapidity = 0;
   GEN_mass = 0;
   GEN_status = 0;
   GEN_Daughter_pdgID = 0;
   GEN_Mother_pdgID = 0;
   GEN_Mom_barcode = 0;
   GEN_Dau_barcode = 0;
   GENmu_pt = 0;
   GENmu_eta = 0;
   GENmu_phi = 0;
   GENmu_mass = 0;
   GENmu_id = 0;
   GENmu_status = 0;
   GENmu_MomId = 0;
   GENmu_MomMomId = 0;
   GENups_DaughtersId = 0;
   GENups_Daughter_mupt = 0;
   GENups_Daughter_mueta = 0;
   GENups_Daughter_murapidity = 0;
   GENups_Daughter_muphi = 0;
   GENups_Daughter_mumass = 0;
   GENups_Daughter_muid = 0;
   GENups_Daughter_mustatus = 0;
   GENups_Daughter_barcode = 0;
   GENups_barcode = 0;
   GENups_MomId = 0;
   GENups_Mom_barcode = 0;
   GENups_pt = 0;
   GENups_eta = 0;
   GENups_y = 0;
   GENups_phi = 0;
   GENups_mass = 0;
   GENups_ID = 0;
   GENups_NDaughters = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("GENfinalState", &GENfinalState, &b_GENfinalState);
   fChain->SetBranchAddress("passedFiducialSelection", &passedFiducialSelection, &b_passedFiducialSelection);
   fChain->SetBranchAddress("GEN_barcode", &GEN_barcode, &b_GEN_barcode);
   fChain->SetBranchAddress("GEN_Nmother", &GEN_Nmother, &b_GEN_Nmother);
   fChain->SetBranchAddress("GEN_Ndaughter", &GEN_Ndaughter, &b_GEN_Ndaughter);
   fChain->SetBranchAddress("GEN_pdgID", &GEN_pdgID, &b_GEN_pdgID);
   fChain->SetBranchAddress("GEN_pt", &GEN_pt, &b_GEN_pt);
   fChain->SetBranchAddress("GEN_eta", &GEN_eta, &b_GEN_eta);
   fChain->SetBranchAddress("GEN_phi", &GEN_phi, &b_GEN_phi);
   fChain->SetBranchAddress("GEN_rapidity", &GEN_rapidity, &b_GEN_rapidity);
   fChain->SetBranchAddress("GEN_mass", &GEN_mass, &b_GEN_mass);
   fChain->SetBranchAddress("GEN_status", &GEN_status, &b_GEN_status);
   fChain->SetBranchAddress("GEN_Daughter_pdgID", &GEN_Daughter_pdgID, &b_GEN_Daughter_pdgID);
   fChain->SetBranchAddress("GEN_Mother_pdgID", &GEN_Mother_pdgID, &b_GEN_Mother_pdgID);
   fChain->SetBranchAddress("GEN_Mom_barcode", &GEN_Mom_barcode, &b_GEN_Mom_barcode);
   fChain->SetBranchAddress("GEN_Dau_barcode", &GEN_Dau_barcode, &b_GEN_Dau_barcode);
   fChain->SetBranchAddress("GENmu_pt", &GENmu_pt, &b_GENmu_pt);
   fChain->SetBranchAddress("GENmu_eta", &GENmu_eta, &b_GENmu_eta);
   fChain->SetBranchAddress("GENmu_phi", &GENmu_phi, &b_GENmu_phi);
   fChain->SetBranchAddress("GENmu_mass", &GENmu_mass, &b_GENmu_mass);
   fChain->SetBranchAddress("GENmu_id", &GENmu_id, &b_GENmu_id);
   fChain->SetBranchAddress("GENmu_status", &GENmu_status, &b_GENmu_status);
   fChain->SetBranchAddress("GENmu_MomId", &GENmu_MomId, &b_GENmu_MomId);
   fChain->SetBranchAddress("GENmu_MomMomId", &GENmu_MomMomId, &b_GENmu_MomMomId);
   fChain->SetBranchAddress("GENups_DaughtersId", &GENups_DaughtersId, &b_GENups_DaughtersId);
   fChain->SetBranchAddress("GENups_Daughter_mupt", &GENups_Daughter_mupt, &b_GENups_Daughter_mupt);
   fChain->SetBranchAddress("GENups_Daughter_mueta", &GENups_Daughter_mueta, &b_GENups_Daughter_mueta);
   fChain->SetBranchAddress("GENups_Daughter_murapidity", &GENups_Daughter_murapidity, &b_GENups_Daughter_murapidity);
   fChain->SetBranchAddress("GENups_Daughter_muphi", &GENups_Daughter_muphi, &b_GENups_Daughter_muphi);
   fChain->SetBranchAddress("GENups_Daughter_mumass", &GENups_Daughter_mumass, &b_GENups_Daughter_mumass);
   fChain->SetBranchAddress("GENups_Daughter_muid", &GENups_Daughter_muid, &b_GENups_Daughter_muid);
   fChain->SetBranchAddress("GENups_Daughter_mustatus", &GENups_Daughter_mustatus, &b_GENups_Daughter_mustatus);
   fChain->SetBranchAddress("GENups_Daughter_barcode", &GENups_Daughter_barcode, &b_GENups_Daughter_barcode);
   fChain->SetBranchAddress("GENups_barcode", &GENups_barcode, &b_GENups_barcode);
   fChain->SetBranchAddress("GENups_MomId", &GENups_MomId, &b_GENups_MomId);
   fChain->SetBranchAddress("GENups_Mom_barcode", &GENups_Mom_barcode, &b_GENups_Mom_barcode);
   fChain->SetBranchAddress("GENups_pt", &GENups_pt, &b_GENups_pt);
   fChain->SetBranchAddress("GENups_eta", &GENups_eta, &b_GENups_eta);
   fChain->SetBranchAddress("GENups_y", &GENups_y, &b_GENups_y);
   fChain->SetBranchAddress("GENups_phi", &GENups_phi, &b_GENups_phi);
   fChain->SetBranchAddress("GENups_mass", &GENups_mass, &b_GENups_mass);
   fChain->SetBranchAddress("GENups_ID", &GENups_ID, &b_GENups_ID);
   fChain->SetBranchAddress("GENups_NDaughters", &GENups_NDaughters, &b_GENups_NDaughters);
   Notify();
}

Bool_t gen_tree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void gen_tree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t gen_tree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef gen_tree_cxx
