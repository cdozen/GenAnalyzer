#define tester_cxx
#include "../tester.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TLorentzVector.h"
#include <iostream>
#include <iostream>
//#include <fstream>
//#include <stdio.h>
//#include "TTree.h"
//#include "TFile.h"
//using namespace std;
void tester::Loop()
{



   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();

   Long64_t nbytes = 0, nb = 0;

    EventDumpFile_J1.open("EventDump_J1.txt");
    EventDumpFile_J2.open("EventDump_J2.txt");
    EventDumpFile_J1<< "#run"<<"\t"<<  "#lumi "<<"\t"<< "#evt"<<"\t"<<  "J1_pt"<<"\t"<<  "J1_y" <<"\t"<<  "J2_pt"<<"\t"<<  "J2_y" <<"\n";
    EventDumpFile_J2<< "#run"<<"\t"<<  "#lumi "<<"\t"<< "#evt"<<"\t"<<  "GENups_pt"<<"\t"<<  "GENups_y"<<"\n";

    TH1F *hJ1_pt = new TH1F("hJ1_pt","J1_pT",200,0,40);
    TH1F *hJ1_y = new TH1F("hJ1_y","J1_y",40,-2.,2.);
    TH1F *hJ2_pt = new TH1F("hJ2_pt","J2_pT",200,0,40);
    TH1F *hJ2_y = new TH1F("hJ2_y","J2_y",40,-2.,2.);
    //TFile *myfile = new TFile("7Nov2020_DPSJJ_WITH_genfilter_2018_NO_etptcut.root","RECREATE");
    TFile *myfile = new TFile("30Nov2020_SPS_JJ_2018_doublevec_v3.root","RECREATE");
    //TFile *myfile = new TFile("28Nov2020_SPS_JJ_2018_pt.root","RECREATE");
    TTree *FourMu_tree = new TTree("FourMu_tree","A ROOT tree");
        int Run; 
        int Lumi; 
        int Event;
        double J1_pt;
        double J2_pt;
        double J1_y;
        double J2_y;
       
        FourMu_tree->Branch("Run",&Run,"Run/I");
        FourMu_tree->Branch("Lumi",&Lumi,"Lumi/I");
        FourMu_tree->Branch("Event",&Event,"Event/I");

        FourMu_tree->Branch("J1_pt" ,&J1_pt ,"J1_pt/D"); 
        FourMu_tree->Branch("J1_y" ,&J1_y ,"J1_y/D"); 
        FourMu_tree->Branch("J2_pt" ,&J2_pt ,"J2_pt/D"); 
        FourMu_tree->Branch("J2_y" ,&J2_y ,"J2_y/D"); 

//nentries=100;
   for (Long64_t i=0; i<nentries;i++) {
      Long64_t ientry = LoadTree(i);
      if (ientry < 0) break;
      nb = fChain->GetEntry(i);   nbytes += nb;
      //std::cout<<"\r" << i << " / " << nentries <<  "  percentage== " << ((double)i/(double)nentries)*100 << "%" << flush;  
      std::cout<<"\r" << i << " / " << nentries << flush;  
      // if (Cut(ientry) < 0) continue;
  

    //std::cout<<"GENups_NDaughters  :"<< GENups_NDaughters->size() <<std::endl;
    //std::cout<<"GENups_ID  :"<< GENups_ID->size() <<std::endl;
    //std::cout<<"Run  :"<< nRun <<std::endl;
    //std::cout<<"Lumi  :"<< nLumi <<std::endl;
    //std::cout<<"Event  :"<< nEvent <<std::endl;
/*
 if (nRun ==1 && nEvent ==94 &&  nLumi== 1) {
     for (size_t j = 0; j < GENups_ID->size(); j++)
     { 
            if(GENups_NDaughters->size() !=2) continue;
            if ((*GENups_Daughter_mupt)[j].size() ==0 ) continue;
            if ((*GENups_Daughter_mueta)[j].size() ==0 ) continue;
            if( GENups_y->at(j)> -2 && GENups_y->at(j)<2 && (*GENups_Daughter_mupt)[j][0]>2.0 && (*GENups_Daughter_mupt)[j][1]>2.0 && (*GENups_Daughter_mueta)[j][0]<2.4 && (*GENups_Daughter_mueta)[j][1]<2.4){
            //if("GENups_y->at(0) > -2.0 && GENups_y->at(0) < 2.0 && abs(*GENups_Daughter_mueta)[0][1] < 2.4 && abs(*GENups_Daughter_mueta)[1][0]<2.4 && (GENups_Daughter_mupt[0][1]) > 2 && (*GENups_Daughter_mupt)[1][0] > 2"){
                std::cout<<" pt of 1.muon  : "<< (*GENups_Daughter_mupt)[j][0] <<" pt of 2. muon : "<< (*GENups_Daughter_mupt)[j][1]<<std::endl;
                //std::cout<<" pt of 3.muon  : "<< (*GENups_Daughter_mupt)[1][0] <<" pt of 4. muon : "<< (*GENups_Daughter_mupt)[1][1]<<std::endl;
                std::cout<<" eta of 1.muon  : "<< (*GENups_Daughter_mueta)[j][0] <<" eta of 2. muon : "<< (*GENups_Daughter_mueta)[j][1]<<std::endl;
                std::cout<<"J1 pt :"<< GENups_pt->at(j) <<std::endl;
                //std::cout<<"J2 pt :"<< GENups_pt->at(1) <<std::endl;
                
                J1_pt=GENups_pt->at(j);
                J1_y=GENups_y->at(j);
                FourMu_tree->Fill(); 
                hJ1_pt->Fill(GENups_pt->at(j));
                hJ1_y->Fill(GENups_y->at(j));
                //hJ2_pt->Fill(GENups_pt->at(1));
                //hJ2_y->Fill(GENups_y->at(1));
            //}
        }
                EventDumpFile_J1<<  nRun <<"\t"<< nLumi<<"\t"<<  nEvent<<"\t"<<  GENups_pt->at(j)<<"\t"<<  GENups_y->at(j)<<"\n";
     }
}

*/
//Run 1, Event 231014, LumiSection 2311 
       if (nRun ==1 && nEvent ==231014 &&  nLumi== 2311)
        {
            for (size_t j = 0; j < GENups_ID->size(); j++)
            {
                for (size_t k = j+1; k < GENups_ID->size(); k++)
                { 
                    if(GENups_NDaughters->size() !=2) continue;
                    //if ((*GENups_Daughter_mupt)[j].size() != 0 && (*GENups_Daughter_mupt)[k].size() !=0 ) 
                    //{//continue;
                        if(j==k) continue;
                        //if ((*GENups_Daughter_mueta)[j].size() ==0 && (*GENups_Daughter_mueta)[k].size()==0) continue;
                        //if( GENups_y->at(j)> -2 && GENups_y->at(j)<2 && (*GENups_Daughter_mupt)[j][0]>2.0 && (*GENups_Daughter_mupt)[j][1]>2.0 && (*GENups_Daughter_mueta)[j][0]<2.4 && (*GENups_Daughter_mueta)[j][1]<2.4)
                        if( GENups_y->at(j)> -2 && GENups_y->at(j)<2 && (*GENups_Daughter_mupt)[j][1]>2.0 && (*GENups_Daughter_mupt)[k][0]>2.0 && (*GENups_Daughter_mueta)[j][1]<2.4 && (*GENups_Daughter_mueta)[k][0]<2.4)
                        {
                        //if( GENups_y->at(0)> -2 && GENups_y->at(0)<2 && (*GENups_Daughter_mupt)[0][1]>2.0 && (*GENups_Daughter_mupt)[1][0]>2.0 && (*GENups_Daughter_mueta)[0][1]<2.4 && (*GENups_Daughter_mueta)[1][0]<2.4 ) //&& GENups_y->at(k)> -2 && GENups_y->at(k)<2 && (*GENups_Daughter_mupt)[k][0]>2.0 && (*GENups_Daughter_mupt)[k][1]>2.0 && (*GENups_Daughter_mueta)[k][0]<2.4 && (*GENups_Daughter_mueta)[k][1]<2.4)
                            //std::cout<<" pt of 1.muon  : "<< (*GENups_Daughter_mupt)[0][0] <<" pt of 2. muon : "<< (*GENups_Daughter_mupt)[0][1]<<std::endl;
                            //std::cout<<" eta of 1.muon  : "<< (*GENups_Daughter_mueta)[0][0] <<" eta of 2. muon : "<< (*GENups_Daughter_mueta)[0][1]<<std::endl;
                            //std::cout<<"J1 pt :"<< GENups_pt->at(j) <<std::endl;
                            //std::cout<<"J1 pt size :"<< GENups_pt->size() <<std::endl;
                            J1_pt=GENups_pt->at(j);
                            J1_y=GENups_y->at(j);
                            J2_pt=GENups_pt->at(k);
                            J2_y=GENups_y->at(k);
                            //EventDumpFile<< setw(10) << nRun <<"\t"<< setw(10) <<nLumi<<"\t"<< setw(10) << nEvent<<"\t"<< setw(10) << GENups_pt->at(j)<<"\t"<< setw(10) << GENups_y->at(j)<<"\n";
                            hJ1_pt->Fill(GENups_pt->at(j));
                            hJ1_y->Fill(GENups_y->at(j));
                            hJ2_pt->Fill(GENups_pt->at(k));
                            hJ2_y->Fill(GENups_y->at(k));
                            EventDumpFile_J1<<  nRun <<"\t"<< nLumi<<"\t"<<  nEvent<<"\t"<<  GENups_pt->at(j)<<"\t"<<  GENups_y->at(j)<<"\t"<< GENups_pt->at(k)<<"\t"<< GENups_y->at(k)<<"\n";
                
                            FourMu_tree->Fill(); 

                        }
            
                        //if( GENups_y->at(k)> -2 && GENups_y->at(k)<2 && (*GENups_Daughter_mupt)[k][0]>2.0 && (*GENups_Daughter_mupt)[k][1]>2.0 && (*GENups_Daughter_mueta)[k][0]<2.4 && (*GENups_Daughter_mueta)[k][1]<2.4)
                        //{
            
                            //std::cout<<" pt of 3.muon  : "<< (*GENups_Daughter_mupt)[k][0] <<" pt of 4. muon : "<< (*GENups_Daughter_mupt)[k][1]<<std::endl;
                            //std::cout<<" eta of 3.muon  : "<< (*GENups_Daughter_mueta)[k][0] <<" eta of 4. muon : "<< (*GENups_Daughter_mueta)[k][1]<<std::endl;
                            //std::cout<<"J2 pt :"<< GENups_pt->at(k) <<std::endl;
                
                           // J2_pt=GENups_pt->at(k);
                            //J2_y=GENups_y->at(k);
                            //EventDumpFile_J2<<  nRun <<"\t"<< nLumi<<"\t"<<  nEvent<<"\t"<<  GENups_pt->at(j)<<"\t"<<  GENups_y->at(j)<<"\n";
                            //hJ2_pt->Fill(GENups_pt->at(k));
                            //hJ2_y->Fill(GENups_y->at(k));
                
                            //EventDumpFile<< setw(10) << runNum<<"\t"<< setw(10) <<lumiNum<<"\t"<< setw(10) << evtNum<<"\t"<< setw(10) << GENups_pt->at(k)<<"\t"<< setw(10) << GENups_y->at(k)<<"\n";
                            //}
                    }
                }
            }
        //}

   } //dongu

   TCanvas *c1 = new TCanvas("c1","c1");

    gStyle->SetEndErrorSize(3);
    gStyle->SetErrorX(1.);
    c1->Divide(2,2);
    c1->cd(1);
    hJ1_pt->Draw();
    c1->cd(2);
    hJ1_y->Draw();
    c1->cd(3);
    hJ2_pt->Draw();
    c1->cd(4);
    hJ2_y->Draw();
    c1->SaveAs("J1and2.pdf");

EventDumpFile_J1.close();
EventDumpFile_J2.close();
  FourMu_tree->Write();
   myfile->Close();
}
