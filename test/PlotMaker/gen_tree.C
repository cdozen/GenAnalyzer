#define gen_tree_cxx
#include "gen_tree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TLorentzVector.h"
#include <iostream>
void gen_tree::Loop()
{
//   In a ROOT session, you can do:
//      root> .L gen_tree.C
//      root> gen_tree t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();

   Long64_t nbytes = 0, nb = 0;


    //TFile *myfile = new TFile("7Nov2020_DPSJJ_WITH_genfilter_2018_NO_etptcut.root","RECREATE");
    TFile *myfile = new TFile("27Nov2020_SPS_JJ_2018.root","RECREATE");
    TTree *FourMu_tree = new TTree("FourMu_tree","A ROOT tree");
        int Run; 
        int Lumi; 
        int Event;
        double Mass4mu;
        double Pt4mu;
        double Eta4mu;
        double Phi4mu;
        double Mass_upsilon;
    	double Pt_upsilon;
    	double Eta_upsilon;
        double Y_upsilon;
        double Phi_upsilon;
        double Mass34_upsilon;
    	double Pt34_upsilon;
    	double Eta34_upsilon;
        double Y34_upsilon;
        double Phi34_upsilon;
        double J1_pt;
        double J1_y;
        double J2_pt;
        double J2_y;
        double mu1_pt;
        double mu1_eta;
        double mu1_phi;
        double mu2_pt;
        double mu2_eta;
        double mu2_phi;
        double mu3_pt;
        double mu3_eta;
        double mu3_phi;
        double mu4_pt;
        double mu4_eta;
        double mu4_phi; 
        double mu1_y;
        double mu2_y;
        double mu3_y;
        double mu4_y;
        
        TLorentzVector fourMuFit,mu1,mu2,mu3,mu4,mu12,mu34;
       
        FourMu_tree->Branch("Run",&Run,"Run/I");
        FourMu_tree->Branch("Lumi",&Lumi,"Lumi/I");
        FourMu_tree->Branch("Event",&Event,"Event/I");

        FourMu_tree->Branch("Mass4mu",&Mass4mu,"Mass4mu/D");
        FourMu_tree->Branch("Pt4mu"  ,&Pt4mu  ,"Pt4mu/D");
        FourMu_tree->Branch("Eta4mu" ,&Eta4mu ,"Eta4mu/D");
        FourMu_tree->Branch("Phi4mu" ,&Phi4mu ,"Phi4mu/D"); 
        FourMu_tree->Branch("J1_pt" ,&J1_pt ,"J1_pt/D"); 
        FourMu_tree->Branch("J1_y" ,&J1_y ,"J1_y/D"); 
        FourMu_tree->Branch("J2_pt" ,&J2_pt ,"J2_pt/D"); 
        FourMu_tree->Branch("J2_y" ,&J2_y ,"J2_y/D"); 
          
        FourMu_tree->Branch("Mass_upsilon",&Mass_upsilon,"Mass_upsilon/D");
        FourMu_tree->Branch("Pt_upsilon"  ,&Pt_upsilon  ,"Pt_upsilon/D");
        FourMu_tree->Branch("Eta_upsilon" ,&Eta_upsilon ,"Eta_upsilon/D");
        FourMu_tree->Branch("Y_upsilon"   ,&Y_upsilon   ,"Y_upsilon/D");
        FourMu_tree->Branch("Phi_upsilon" ,&Phi_upsilon ,"Phi_upsilon/D");

        FourMu_tree->Branch("Mass34_upsilon",&Mass34_upsilon,"Mass34_upsilon/D");
        FourMu_tree->Branch("Pt34_upsilon"  ,&Pt34_upsilon  ,"Pt34_upsilon/D");
        FourMu_tree->Branch("Eta34_upsilon" ,&Eta34_upsilon ,"Eta34_upsilon/D");
        FourMu_tree->Branch("Y34_upsilon"   ,&Y34_upsilon   ,"Y34_upsilon/D");
        FourMu_tree->Branch("Phi34_upsilon" ,&Phi34_upsilon ,"Phi34_upsilon/D");
 
        
        FourMu_tree->Branch("fourMuFit",&fourMuFit);
        FourMu_tree->Branch("mu1" ,&mu1);
        FourMu_tree->Branch("mu2" ,&mu2);
        FourMu_tree->Branch("mu3" ,&mu3);
        FourMu_tree->Branch("mu4" ,&mu4);
        FourMu_tree->Branch("mu12",&mu12);
        FourMu_tree->Branch("mu34",&mu34);


        FourMu_tree->Branch("mu1_pt" ,&mu1_pt ,"mu1_pt/D");
        FourMu_tree->Branch("mu1_eta",&mu1_eta,"mu1_eta/D");
        FourMu_tree->Branch("mu1_phi",&mu1_phi,"mu1_phi/D");
        FourMu_tree->Branch("mu2_pt" ,&mu2_pt ,"mu2_pt/D");
        FourMu_tree->Branch("mu2_eta",&mu2_eta,"mu2_eta/D");
        FourMu_tree->Branch("mu2_phi",&mu2_phi,"mu2_phi/D");
        FourMu_tree->Branch("mu3_pt" ,&mu3_pt ,"mu3_pt/D");
        FourMu_tree->Branch("mu3_eta",&mu3_eta,"mu3_eta/D");
        FourMu_tree->Branch("mu3_phi",&mu3_phi,"mu3_phi/D");
        FourMu_tree->Branch("mu4_pt" ,&mu4_pt ,"mu4_pt/D");
        FourMu_tree->Branch("mu4_eta",&mu4_eta,"mu4_eta/D");
        FourMu_tree->Branch("mu4_phi",&mu4_phi,"mu4_phi/D");
        FourMu_tree->Branch("mu1_y"  ,&mu1_y  ,"mu1_y/D");
        FourMu_tree->Branch("mu2_y"  ,&mu2_y  ,"mu2_y/D");
        FourMu_tree->Branch("mu3_y"  ,&mu3_y  ,"mu3_y/D");
        FourMu_tree->Branch("mu4_y"  ,&mu4_y  ,"mu4_y/D");
	 

//nentries=1000000;
   for (Long64_t i=0; i<nentries;i++) {
      Long64_t ientry = LoadTree(i);
      if (ientry < 0) break;
      nb = fChain->GetEntry(i);   nbytes += nb;
      //std::cout<<"\r" << i << " / " << nentries <<  "  percentage== " << ((double)i/(double)nentries)*100 << "%" << flush;  
      std::cout<<"\r" << i << " / " << nentries << flush;  
      // if (Cut(ientry) < 0) continue;
  
        /*4lu muon adaylarını bul*/
  
     std::vector<TLorentzVector> mucollection;
     TLorentzVector temporarymuon;

     /*muondan git*/
     /*
     for (size_t j = 0; j < GENmu_pt->size(); j++)
     {  
         if(GENmu_status->at(j)!= 1) continue;  // status 1 is final one..

        for (size_t k = j+1; k < GENmu_pt->size(); k++)
        {
              if(GENmu_status->at(k)!= 1) continue;  // status 1 is final one..
            //std::cout<<"mu1 :"<<GENmu_mass->at(j)<<" mu2 :"<<GENmu_mass->at(k)<<std::endl;

            TLorentzVector Jpsi;

            mu1.SetPtEtaPhiM(GENmu_pt->at(j),GENmu_eta->at(j),GENmu_phi->at(j),GENmu_mass->at(j));
            mu2.SetPtEtaPhiM(GENmu_pt->at(k),GENmu_eta->at(k),GENmu_phi->at(k),GENmu_mass->at(k));
            Jpsi= mu1+mu2;

            std::cout<<"Jpsimass :"<<Jpsi.M()<<" 1.nin anasi: "<< GENmu_MomId->at(j)<<" 2.nin anasi: "<< GENmu_MomId->at(k) <<std::endl;
        }

     }*/

/// Upsilon dongusu

     for (size_t j = 0; j < GENups_ID->size(); j++)
     {  

        for (size_t k = j+1; k < GENups_ID->size(); k++)
        {

            if ((*GENups_Daughter_mupt)[k].size() !=0 && (*GENups_Daughter_mupt)[j].size() !=0)
            {
              //if((*GENups_barcode)[j] == (*GENups_barcode)[k]) continue;
              if(j== k) continue;
          //  std::cout<<"PASSED :"<<__LINE__<<std::endl;
            TLorentzVector J12, J34 , J1,J2 ,DoubleJpsi, Fourmu;
              //if( (*GENups_Daughter_mupt)[j][0]<2.0 || (*GENups_Daughter_mupt)[j][1]<2.0 || (*GENups_Daughter_mupt)[k][0]<2.0 || (*GENups_Daughter_mupt)[k][1]<2.0) continue;
          //std::cout<<" pt : "<< (*GENups_Daughter_mupt)[j][0] <<" pt : "<< (*GENups_Daughter_mupt)[j][1]<<" pt : "<< (*GENups_Daughter_mupt)[k][0]<<" pt : "<< (*GENups_Daughter_mupt)[k][1]<<std::endl;;
            //std::cout<<"PASSED :"<<__LINE__<<std::endl;
              
              //if( fabs((*GENups_Daughter_mueta)[j][0])>2.4 || fabs((*GENups_Daughter_mueta)[j][1])>2.4 || fabs((*GENups_Daughter_mueta)[k][0])>2.4 || fabs((*GENups_Daughter_mueta)[k][1])>2.4)continue;
          //  std::cout<<"PASSED :"<<__LINE__<<std::endl;
         // std::cout<<" eta : "<< (*GENups_Daughter_mueta)[j][0] <<" eta : "<< (*GENups_Daughter_mueta)[j][1]<<" eta : "<< (*GENups_Daughter_mueta)[k][0]<<" eta : "<< (*GENups_Daughter_mueta)[k][1]<<std::endl;;
         //   std::cout<<"test :"<<(*GENups_Daughter_mupt)[k][0]<<std::endl;
            // Jpsi1
            mu1.SetPtEtaPhiM((*GENups_Daughter_mupt)[j][0],(*GENups_Daughter_mueta)[j][0],(*GENups_Daughter_muphi)[j][0],(*GENups_Daughter_mumass)[j][0]);
            mu2.SetPtEtaPhiM((*GENups_Daughter_mupt)[j][1],(*GENups_Daughter_mueta)[j][1],(*GENups_Daughter_muphi)[j][1],(*GENups_Daughter_mumass)[j][1]);
            // Jpsi2
            mu3.SetPtEtaPhiM((*GENups_Daughter_mupt)[k][0],(*GENups_Daughter_mueta)[k][0],(*GENups_Daughter_muphi)[k][0],(*GENups_Daughter_mumass)[k][0]);
            mu4.SetPtEtaPhiM((*GENups_Daughter_mupt)[k][1],(*GENups_Daughter_mueta)[k][1],(*GENups_Daughter_muphi)[k][1],(*GENups_Daughter_mumass)[k][1]);
            
            J12= mu1+mu2;
            J34= mu3+mu4;
           mu12=J12;
           mu34=J34;
          
            // Upsilon1
            J1.SetPtEtaPhiM((*GENups_pt)[j],(*GENups_eta)[j],(*GENups_phi)[j],(*GENups_mass)[j]  );
            J2.SetPtEtaPhiM((*GENups_pt)[j],(*GENups_eta)[j],(*GENups_phi)[j],(*GENups_mass)[j]  );
            
            DoubleJpsi = J1+ J2;
            Fourmu =mu1+mu2+mu3+mu4;

          //  std::cout<<"Jpsimass :"<<Fourmu.M()<<std::endl;

            /*4mu*/
            
              Mass4mu    = Fourmu.M();
              Pt4mu      = Fourmu.Pt();
              Eta4mu     = Fourmu.Eta();
              Phi4mu     = Fourmu.Phi();
            /*upsilon*/
              Mass_upsilon   =  J12.M();
              Pt_upsilon     =  J12.Pt();
              Eta_upsilon    =  J12.Eta();
              Y_upsilon      =  J12.Rapidity();
              Phi_upsilon    =  J12.Phi();

              Mass34_upsilon =  J34.M();
              Pt34_upsilon   =  J34.Pt();
              Eta34_upsilon  =  J34.Eta();
              Phi34_upsilon  =  J34.Phi();
              Y34_upsilon    =  J34.Rapidity();
             
             J1_pt=J1.Pt(); 
             J2_pt=J2.Pt() ;
             J1_y=J1.Rapidity(); 
             J2_y=J2.Rapidity(); 
             /*muons*/
              
              mu1_pt     = mu1.Pt() ;
              mu1_eta    = mu1.Eta() ;
              mu1_phi    = mu1.Phi() ;
              mu1_y      = mu1.Rapidity() ;

              mu2_pt     = mu2.Pt();
              mu2_eta    = mu2.Eta();
              mu2_phi    = mu2.Phi();
              mu2_y      = mu2.Rapidity();

              mu3_pt     = mu3.Pt();
              mu3_eta    = mu3.Eta();
              mu3_phi    = mu3.Phi();
              mu3_y      = mu3.Rapidity();

              mu4_pt     = mu4.Pt();
              mu4_eta    = mu4.Eta();
              mu4_phi    = mu4.Phi();
              mu4_y      = mu4.Rapidity();
FourMu_tree->Fill();
            }
            
        }

     }

  
  
   } //dongu

   FourMu_tree->Write();
   myfile->Close();
}
