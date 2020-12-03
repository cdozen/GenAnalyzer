/*
23 Nov. 2020 18:40
23 Nov 18:37 zack:

PT randomisation algorithm: su anda uyguladigimiz:

1- once yüksek pt li adamları sec (ntpl)
2- seçtiğimiz adamların uzerinden fit fonksiyonu bul
3-event by event bakarken cutler hight pt li adama gore alindi. 
4- mixing J1 e gore yapıldı.



 *Highest Pt selecetion has been done on ntuple level and here we randomize the highest PT Jpsi candidates. 



 */
/*
12 November 2020

******mu12 (J1) mixing****** 

Gen Level event mixing with alternate method(PT randomization in each eta/rapidity bins). 

The PDF functions:
We are using three different kind of PDF function are being use to check which one can model the background well. 

1- Landau pdf
2- Error function (ERF)    p d f 
3- Keys (KDE) Pdf
 

For mu12(Jpsi) use rapidity bins.
If you would like to mix single muon mixing then use eta binnings. 


Input file:7Nov2020_DPSJJ_WITH_genfilter_2018_WITH_etptcut.root 

This code generate events in eta/ rapidty binnings by using PT randomization method.


To run on Eta binning: bool Set_Eta = True 
To run on Rapidity binning: bool Set_Eta = False 

for eta binning: 
- full range: {0, 5.0};
- divided small bins = {0, 0.7, 1.2, 1.6, 1.9, 2.2, 2.5, 2.9, 5.0}

for rapidity binning:
-fullRange = {0, 2.5}; 
-divided small bins = {0, 0.5, 0.85, 1.10, 1.3, 1.5, 1.7, 1.9 , 2.5}; 

To run with fullRange:
bool fullRange = true;

If you want to use blind region:
const bool blind_signal = true;
Toi run the code :
root -l testrandomprod.cpp
it will create PDF functions according to the selected binnings and produce event mixing by randomize the Pt with respect to the PDF fucntion used. 

Mass Spectrum Plots:

The mass spectrum plots (FourMuon, DoubleJpsi,FourMuMix) will be saved in "plots" folder.

2D plots:
The original Jpsi (eta/pt/rapdity) vs  mixing Jpsi(eta/pt/rapdity) will be stored in "plots2D" folder.
 

*/
/* 
 * File:   tester.h
 * Author: Candan
 *
 * Created on November 20, 2019, 8:38 PM
 */

#ifndef TESTER_H
#define TESTER_H

/// \file
/// \ingroup tutorial_roofit
/// \notebook -js
///  'ADDITION AND CONVOLUTION' RooFit tutorial macro #208
///
///  One-dimensional numeric convolution
///  (require ROOT to be compiled with --enable-fftw3)
///
///  pdf = landau(t) (x) gauss(t)
///
/// \macro_image
/// \macro_output
/// \macro_code
/// \author 07/2008 - Wouter Verkerke 

#include "TROOT.h"
#include "RooRealVar.h"
#include "RooFormulaVar.h"
#include "RooArgList.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooLandau.h"
#include "RooFFTConvPdf.h"
#include "RooPlot.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TH1.h"
#include "TCut.h"
#include "TLorentzVector.h"
#include "SetHistograms.h"
#include "RooKeysPdf.h"
#include "TF1.h"
#include "RooGenericPdf.h"
#include "TFormula.h"
#include <iostream>
#include <sstream>      // std::stringstream
#include <fstream>      // ifstream
#include <vector>
//#include "JpsiEvents.C"
#include "FMu.C"
#include "TApplication.h"

using namespace std;
using namespace RooFit;


void PlotHistograms()
{


}

void ProduceRandom(TLorentzVector *inputvector, // Input TLorentzVector
                   std::vector<TLorentzVector> &outputVector, // Output vector of TLorentzVector
                   TF1 *func, // Convoluted fit PDF
                   int i,// Event counter
                   double bin1,
                   double bin2,
                   bool Set_Eta
                   )
{



    int count=0;
    for (int k = 0; k < 10000; k++)
    {
        double val=0;
    
        val = func->GetRandom();
        TLorentzVector temp_vector_mix;
        temp_vector_mix.SetPtEtaPhiM(val, inputvector->Eta(), inputvector->Phi(), inputvector->M());
        //for rapidity bin range
      if(!Set_Eta) if(!(abs(temp_vector_mix.Rapidity())> bin1 && abs(temp_vector_mix.Rapidity())< bin2)) continue;
      if(Set_Eta) if(!(abs(temp_vector_mix.Eta())> bin1 && abs(temp_vector_mix.Eta())< bin2)) continue;
       outputVector.push_back(temp_vector_mix);
        count++;
        if (count==1000) break;
    }

}
//*************************************//
// Produce Random Distribution
//*************************************//

void testrandomprod()
{   
    gROOT->SetBatch();
    define_and_setHistograms();
    //*************************************//
    //  Set_Eta  -- true Eta bins, false Rapidity bins
    //*************************************//    
    bool Set_Eta = false; //false for rapidity
    bool fullRange = false;
    const bool blind_signal = false;
    
    //*************************************//
    std::vector<double> ybins;
    // Define rapidity bins ..
    // double ybins[]= { 0,0.7,1.2,1.6,1.9,2.2,2.5};
    if (!Set_Eta)
    {
        if (fullRange)ybins = {0, 2.5}; // rapidity bins
        if (!fullRange)ybins = {0, 0.5, 0.85, 1.10, 1.3, 1.5, 1.7, 1.9 , 2.5}; // rapidity bins
        //if (!fullRange)ybins = {0, 0.6, 0.9, 1.1, 1.3, 1.5, 1.8, 2.5}; // rapidity bins
    }
    else //eta range for upsilon
    {
        if (fullRange) ybins = {0, 5.0};
        if (!fullRange) ybins = {0, 0.7, 1.2, 1.6, 1.9, 2.2, 2.5, 2.9, 5.0};
    }


    int y_size = ybins.size();

    // S e t u p   c o m p o n e n t   p d f s 
    // ---------------------------------------

    //TFile *f = new TFile("test.root");  //2016 Double Jpsi
    //TFile *f = new TFile("7Nov2020_DPSJJ_WITH_genfilter_2018_WITH_etptcut.root");  
    TFile *f = new TFile("../DPS2JJwSPS/DPS2JJ_highestPtSelection.root");  
    //TFile *f = new TFile("fourMuMass_tree.root");  
    //TTree *fTree = (TTree*) f->Get("JpsiEvents");
    TTree *fTree = (TTree*) f->Get("FourMu_tree");
 
    //JpsiEvents *ReadTree = new JpsiEvents(fTree);
    FMu *ReadTree = new FMu(fTree);
     /*
    RooRealVar *var_Pt_J1   = new RooRealVar("J1_pt", "J1_pt", 0.0, 50, "GeV");
    RooRealVar *var_Y_J1    = new RooRealVar("J1_y", "J1_y", -5.0, 5.0, "GeV");
    RooRealVar *var_Eta_J1  = new RooRealVar("J1_eta", "J1_eta", -5.0, 5.0, "GeV");
    */
    RooRealVar *var_Pt_upsilon_high   = new RooRealVar("Pt_upsilon_high", "Pt_upsilon_high", 0.0, 50, "GeV");

    RooRealVar *var_Y_upsilon_high    = new RooRealVar("Y_upsilon_high", "Y_upsilon_high", -5.0, 5.0, "GeV");

    RooRealVar *var_Eta_upsilon_high  = new RooRealVar("Eta_upsilon_high", "Eta_upsilon_high", -5.0, 5.0, "GeV");

    RooArgSet *observables  = new RooArgSet("Observables");

    observables->add(*var_Pt_upsilon_high);
    if (!Set_Eta){
    observables->add(*var_Y_upsilon_high);
    } 
    if (Set_Eta){
    observables->add(*var_Eta_upsilon_high);    
    } 
   
   
 // Construct landau(t,ml,sl) ;
    RooRealVar ml("ml", "mean landau", 5., -0.0, 40);
    RooRealVar sl("sl", "sigma landau", 1, 0.1, 20);
    RooLandau landau("lx", "lx", *var_Pt_upsilon_high, ml, sl);
    //RooLandau landau("lx", "lx", *var_Pt_J1, ml, sl);

    // Construct gauss(t,mg,sg)
    RooRealVar mg("mg", "mg", 0);
    RooRealVar sg("sg", "sg", 2, 0.01, 10);
    RooGaussian gauss("gauss", "gauss", *var_Pt_upsilon_high, mg, sg);
    //RooGaussian gauss("gauss", "gauss", *var_Pt_J1, mg, sg);

    // ---------------------------------------
    // C o n s t r u c t   ERF    p d f 
    // ---------------------------------------
    RooRealVar* m0shift = new RooRealVar("m0shift", "m0shift", 1, 0., 5.);
    RooRealVar* width = new RooRealVar("width", "width", 0.5, 0., 5.);
    RooRealVar* par3 = new RooRealVar("par3", "par3", 5, 0., 15.);
    //**************************************//
    // Loop on Every rapidity bin
    //**************************************//
    TString GraphTitle;
    for (int n = 0; n < y_size - 1; n++)
    {
        TCut mycuty;

        /*
        Select the highest Pt Jpsi  
        */
        if (!Set_Eta)
        {
            mycuty = Form(" (abs(%s) > %.2f) && (abs(%s) < %.2f)", "Y_upsilon_high", ybins[n], "Y_upsilon_high", ybins[n + 1]);
        }
        else
        {                                                  
            mycuty = Form("(abs(%s) > %.2f) && (abs(%s) < %.2f)", "Eta_upsilon_high", ybins[n], "Eta_upsilon_high", ybins[n + 1]);
        }
	//int Ntotal = fTree->GetEntries();

        RooDataSet *dataset = new RooDataSet("DataSet", "DataSet", *observables, RooFit::Import(*fTree), RooFit::Cut(mycuty));
        
     
        TString totalbin;
        if (!Set_Eta)
        {
            totalbin = Form("%s_%.2f_%.2f", "Y_upsilon", ybins[n], ybins[n + 1]);
        }
        else
        {
            totalbin = Form("%s_%.2f_%.2f", "Eta_upsilon", ybins[n], ybins[n + 1]);
        }
        //*******************************************************************//
        ///PDF Models
        // Activate only 1 fit model
        //*******************************************************************//      
        // Fitno1-) Construct landau (x) gauss
        // RooFFTConvPdf *lxg=new RooFFTConvPdf ("lxg","landau (X) gauss",*var_Pt_J1,landau,gauss) ;
        //*******************************************************************//      
        //Fitno2-) Construct Keys Pdf
          //RooKeysPdf *lxg= new RooKeysPdf("KDE","KDE", *var_Pt_J1, *dataset, RooKeysPdf::MirrorBoth, 1);         
          RooKeysPdf *lxg= new RooKeysPdf("KDE","KDE", *var_Pt_upsilon_high, *dataset, RooKeysPdf::MirrorBoth, 1);         
        //*******************************************************************//      
        //Fitno3-) Construct ERF
         //RooGenericPdf* lxg = new RooGenericPdf("ERF", "LikeSignPdf", "exp(-@0/par3)*(TMath::Erf((@0-m0shift)/width)+1)", RooArgList(*var_Pt_J1, *m0shift, *width, *par3));
        //*******************************************************************//      
        //*******************************************************************//      



       //*******************************************************************//
        /// Fitter ...
        //*******************************************************************//
        cout << "!!******************************!" << endl;
        cout << "Fitting : " << lxg->GetName() << "\n";
        cout << "!!******************************!" << endl;

        // ----------------------------------------------------------------------
        // S a m p l e ,   f i t   a n d   p l o t   c o n v o l u t e d   p d f 
        // ----------------------------------------------------------------------
        // Fit gxlx to data
        lxg->fitTo(*dataset, RooFit::NumCPU(4, RooFit::BulkPartition));

         // Set func for error from Muhammad
          TF1 *func ;
          func = lxg->asTF(RooArgList(*var_Pt_upsilon_high));
        
        // Plot data, landau pdf, landau (X) gauss pdf
        GraphTitle = lxg->GetName();
        if (!Set_Eta)
        {
            GraphTitle += "_J1_Pt_RapidityBin";
        }
        else
        {
            GraphTitle += "_J1_Pt_EtaBin";
        }
        //RooPlot* frame = var_Pt_J1->frame(Title(GraphTitle + totalbin));
        RooPlot* frame = var_Pt_upsilon_high->frame(Title(GraphTitle + totalbin));
        dataset->plotOn(frame);
        lxg->plotOn(frame);

        //keys_pdfs->plotOn(frame, RooFit::LineColor(kGreen));
        //****************************//
        //Dataset Generation
        //****************************//
        int Ntotal = fTree->GetEntries();
        cout << "!!***************************************!!\n";
        cout << " Readed   :" << Ntotal << "\n";
        cout << "!!***************************************!!\n";

        vector<TLorentzVector> mu12_MixFourMuVect;
        vector<TLorentzVector> mu12_MixingVect;
        vector<TLorentzVector> rand_MixingVect;
        vector<TLorentzVector*> mu12_OriginalVect;
        vector<TLorentzVector*> mu34_OriginalVect;
        vector<TLorentzVector*> mu1_OriginalVect;
        vector<TLorentzVector*> mu2_OriginalVect;
        vector<TLorentzVector*> mu3_OriginalVect;
        vector<TLorentzVector*> mu4_OriginalVect;
        ///*************************************//
        // Txt dosyasından okunacaklar
        //*************************************//
       
        TLorentzVector *mu1= new TLorentzVector();
        TLorentzVector *mu2 = new TLorentzVector();
        TLorentzVector *mu3 = new TLorentzVector();
        TLorentzVector *mu4= new TLorentzVector();
	TLorentzVector *J1 = new TLorentzVector();
        TLorentzVector *J2= new TLorentzVector();
        TLorentzVector *J12= new TLorentzVector();
        TLorentzVector *J34= new TLorentzVector();
	TLorentzVector *DoubleJpsi= new TLorentzVector();;
	TLorentzVector *FourMu= new TLorentzVector();;
	std::vector<TLorentzVector*> mu1_p4_vector;
	std::vector<TLorentzVector*> mu2_p4_vector;
	std::vector<TLorentzVector*> mu3_p4_vector;
	std::vector<TLorentzVector*> mu4_p4_vector;
	std::vector<TLorentzVector*> mu12_p4_vector;
	std::vector<TLorentzVector*> mu34_p4_vector;
	TLorentzVector *J_high = new TLorentzVector();
	//float mymumass=0.1134289267;
       // Read from the txt file 
        for (int i = 0; i < Ntotal; i++)
        {
            ReadTree->GetEntry(i);
            
         //cout<<ReadTree->px11<<"  "<<ReadTree->py11<<" "<<ReadTree->pz11<<" "<<mymumass<<endl;;//Jpsi_1 dau1
            
	mu1  = ReadTree->mu1;//->SetXYZM(ReadTree->px11,ReadTree->py11,ReadTree->pz11,mymumass);//Jpsi_1 dau1
        mu2  = ReadTree->mu2;//->SetXYZM(ReadTree->px12,ReadTree->py12,ReadTree->pz12,mymumass);//Jpsi_1 dau2
        mu3  = ReadTree->mu3;//->SetXYZM(ReadTree->px21,ReadTree->py21,ReadTree->pz21,mymumass);//Jpsi_2 dau1
        mu4  = ReadTree->mu4;//->SetXYZM(ReadTree->px22,ReadTree->py22,ReadTree->pz22,mymumass);//Jpsi_2 dau2
        J1   = ReadTree->mu12;//->SetXYZM(ReadTree->px1,ReadTree->py1,ReadTree->pz1,ReadTree->m1); 
        J2   = ReadTree->mu34;//->SetXYZM(ReadTree->px2,ReadTree->py2,ReadTree->pz2,ReadTree->m2); 
	*J12=*mu1+*mu2;
	*J34=*mu3+*mu4;
	//4 muon combination
	//*FourMu=*mu1+*mu2+*mu3+*mu4;
	*FourMu=*J12+*J34;
	//hMFourMu->Fill(FourMu->M()-J12->M()-J34->M()+2*3.096);
	//Double Jpsi Combination
        *DoubleJpsi=*J1+*J2;
	//hMDoubleJpsi->Fill(DoubleJpsi->M()-ReadTree->m1-ReadTree->m2+2*3.096);
	//*J12=*mu1+*mu2;
        //*J34=*mu3+*mu4;
       	//*FourMu = *J12 +*J34;
            
	//if(!Set_Eta)if (!(abs(J1->Rapidity()) > ybins[n] && abs(J1->Rapidity()) < ybins[n + 1]))continue;  // check rapidiy
        //for eta binning
    //    if(Set_Eta)if (!(abs(J1->Eta()) > ybins[n] && abs(J1->Eta()) < ybins[n + 1]))continue;  // check eta
        cout << "\r" << "Entry :" << i << "/" << Ntotal << flush;
        
	//ProduceRandom(ReadTree->mu12,RandomYvector,datasetgen,lxg,i);
       //if(J1->Pt()>J2->Pt()){
            if(!Set_Eta)if (!(abs(ReadTree->Y_upsilon_high) > ybins[n] && abs(ReadTree->Y_upsilon_high) < ybins[n + 1]))continue;  // check rapidiy
        //for eta binning
        if(Set_Eta)if (!(abs(ReadTree->Y_upsilon_high) > ybins[n] && abs(ReadTree->Y_upsilon_high) < ybins[n + 1]))continue;  // check eta
        

       if(J1->Pt()>J2->Pt()){
        J_high->SetPtEtaPhiM(ReadTree->Pt_upsilon_high,ReadTree->Eta_upsilon_high,ReadTree->Phi_upsilon_high,J1->M()); ///ntpl da mass_upsilon_high ekle
}else{ 
J_high->SetPtEtaPhiM(ReadTree->Pt_upsilon_high,ReadTree->Eta_upsilon_high,ReadTree->Phi_upsilon_high, J2->M());
}
	//ProduceRandom(J1, mu12_MixingVect, func, i, ybins[n], ybins[n + 1], Set_Eta);
	ProduceRandom(J1, rand_MixingVect, func, i, ybins[n], ybins[n + 1], Set_Eta);
	J1pt->Fill(J1->Pt());
        J1eta->Fill(J1->Eta());
        J1rapid->Fill(J1->Rapidity());
        J1phi->Fill(J1->Phi());
        mu12_OriginalVect.push_back(J1);
              
       // mu12_MixingVect.push_back(RandomYvector);

       ///*******************************//
       /// Fill Histograms
        ///*******************************//
        
	
	/*J1pt->Fill(J1->Pt());
        J1eta->Fill(J1->Eta());
        J1rapid->Fill(J1->Rapidity());
        J1phi->Fill(J1->Phi());
        */
	hMFourMu->Fill(FourMu->M()-J12->M()-J34->M()+2*3.096);
    hMDoubleJpsi->Fill(DoubleJpsi->M()-J12->M()-J34->M() +2*3.096);
            
        TLorentzVector mixFourMu;
        TLorentzVector mixFourMu_high;
        //mix
        //for (auto s = 0; s < mu12_MixingVect.size(); s++)
        for (auto s = 0; s < rand_MixingVect.size(); s++)
                
          {

                mixFourMu = *J34 + rand_MixingVect[s];
                mixFourMu_high = *J_high + rand_MixingVect[s];
                h_mix->Fill(mixFourMu.M()-rand_MixingVect[s].M()-J34->M()+2*3.096);
                h_mix_high->Fill(mixFourMu_high.M()-rand_MixingVect[s].M()-J_high->M()+2*3.096);
		
		//mixFourMu = *J34 + mu12_MixingVect[s];
                //h_mix->Fill(mixFourMu.M());//-mu12_MixingVect[s].M()-J34->M()+2*3.096);
                //h_mix->Fill(mixFourMu.M()-mu12_MixingVect[s].M()-J34->M()+2*3.096);
                //hfourMuMass_physkbg_mix->Fill(mixFourMu.M()-mu12_MixingVect[s].M()-J34->M()+2*3.096);
                
		mix_J1pt->Fill(rand_MixingVect[s].Pt());
                mix_J1eta->Fill(rand_MixingVect[s].Eta());
                mix_J1rapid->Fill(rand_MixingVect[s].Rapidity());
		/*mix_J1pt->Fill(mu12_MixingVect[s].Pt());
                mix_J1eta->Fill(mu12_MixingVect[s].Eta());
                mix_J1rapid->Fill(mu12_MixingVect[s].Rapidity());
          */ }
      	//

       //************************************//   
       //clear vect
       //************************************//   

        //mu12_MixingVect.clear();
        rand_MixingVect.clear();
        mu12_OriginalVect.clear();

        }// Event loop

        //tata..
        //************************************//   
        //clear vect
        //************************************//   
        TString MainfCanv = "fitplot_" + GraphTitle + totalbin;
        TCanvas *c1 = new TCanvas(MainfCanv, MainfCanv, 600, 600);
        gPad->SetLeftMargin(0.15);
        frame->GetYaxis()->SetTitleOffset(1.4);
        frame->Draw();
        c1->SaveAs(MainfCanv + ".png");

    } // End Loop on Rapidity/eta bin
    //***********************************************************//  
    // Draw frame on canvas
    //***********************************************************//  
    TString Cname = "Graph_total_" + GraphTitle;
    
    if (fullRange) Cname += "_FullRange_";
    if (!fullRange) Cname += "_BinnedTotal_";
          
    ScaledPlot(Cname, J1pt, mix_J1pt, "p_{T}(J#Psi) [GeV]", "Mixed(J#Psi)/J#Psi");
    ScaledPlot(Cname, J1eta, mix_J1eta, "#Eta_J1", "Mixed(J#Psi)/J#Psi");
    ScaledPlot(Cname, J1rapid, mix_J1rapid, "Rapidity (J#Psi)", "Mixed(J#Psi)/J#Psi");
    ScaledPlot(Cname, J1phi, mix_J1phi, "Phi (J#Psi)", "Mixed(J#Psi)/J#Psi");
//ScaledPlot("muon_pt vs mixed_muon_pt",hfourMuFitmu3Pt, h_mix_fourMuFitmu3Pt, "p_{T}(#muon) [GeV]", "Mixed(#muon)/#muon");    
//ScaledPlot("muon_eta vs mixed_muons_eta",hfourMuFitmu3Eta, h_mix_fourMuFitmu3Eta, "#Eta (#muon) [GeV]", "Mixed(#muon)/#muon");
//ScaledPlot("muon_y vs mixed_muon_y",hfourMuFitmu3Rap, h_mix_fourMuFitmu3Rap, "Rapidty (#muon) [GeV]", "Mixed(#muon)/#muon");

///draw Histograms:
    
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    TCanvas *cjpsimix = new TCanvas("cjpsimix","cjpsimix",800,600);
    TCanvas *c4mumix = new TCanvas("c4mumix","c4mumix",800,600);
    TCanvas *cjpsimix_high = new TCanvas("cjpsimix_high","cjpsimix_high",800,600);
    TCanvas *c4mumix_high = new TCanvas("c4mumix_high","c4mumix_high",800,600);
    //TCanvas *c2j = new TCanvas("c2j","c2j",800,600);
    //TCanvas *c2mix = new TCanvas("c2mix","c2mix",800,600);

   //c4mu->cd();
    c1->cd();
    //Four Mu Mass
    hMFourMu->Sumw2();
    hMFourMu->Draw("e1");
    //h_mix->Scale((float)hMFourMu->Integral()/h_mix->Integral());
    //h_mix->SetMarkerColor(kRed);
    //h_mix->Draw("e1same");
    c1->SaveAs("plots/hMFourMu.png");
    //c2->cd();
    //hMDoubleJpsi->Draw("e1");
    //c2->SaveAs("plots/hMDoubleJpsi.png");
 
    //Four Mu Mass
    //hMFourMu->Draw("e1");
    //float scaleEntries = hMFourMu->Integral();
    //hMFourMu->SetStats(0);
    //c2->SaveAs("plots/hMFourMu.png");
    
    // Double Jpsi
    hMDoubleJpsi->Sumw2();
    hMDoubleJpsi->SetMarkerStyle(24);
    hMDoubleJpsi->SetMarkerColor(kBlue);
    float scaleEntries = hMDoubleJpsi->Integral();
    hMDoubleJpsi->Draw("e1");  
    c1->SaveAs("plots/hMDoubleJpsi.png");
    
    // mix
    h_mix->Sumw2();
    h_mix->Scale((float)hMDoubleJpsi->Integral()/h_mix->Integral());
    h_mix->SetMarkerStyle(22);    
    h_mix->SetLineColor(kRed);
    h_mix->SetMarkerColor(kRed);
    //h_mix->Scale(scaleEntries/h_mix->Integral());
    h_mix->Draw("e1");
    c1->SaveAs("plots/h_mix.png");

     // mix high
    h_mix_high->Sumw2();
    h_mix_high->Scale((float)hMDoubleJpsi->Integral()/h_mix->Integral());
    h_mix_high->SetMarkerStyle(22);    
    h_mix_high->SetLineColor(kRed);
    h_mix_high->SetMarkerColor(kRed);
    //h_mix->Scale(scaleEntries/h_mix->Integral());
    h_mix_high->Draw("e1");
    c1->SaveAs("plots/h_mix_high.png");


    // mix
    //h_mix->SetMarkerStyle(22);
    //h_mix->SetMarkerColor(kBlue);
    //h_mix->Scale((float)hMDoubleJpsi->Integral()/h_mix->Integral());
    //h_mix->Draw("e1");  
    //c2->SaveAs("plots/h_mix.png");
   
    //hMFourMu->Draw("e1");
    //h_mix->Scale((float)hMFourMu->Integral()/h_mix->Integral());
    //h_mix->SetMarkerColor(kRed);
    //h_mix->Draw("e1same"); 
    //c2->SaveAs("plots/hFourMuvsmix.png");
 
    // compare original vs mix
    cjpsimix->cd(); 
    //TCanvas *c3 = new TCanvas("c3","c3",800,600);
    hMDoubleJpsi->SetMarkerStyle(20);
    hMDoubleJpsi->SetMarkerColor(kBlue);
    hMDoubleJpsi->SetLineColor(kBlue);
    hMDoubleJpsi->Draw("e1");
    std::cout << "hMDoubleJpsi->Integral() = " << hMDoubleJpsi->Integral() << std::endl;
    h_mix->Scale(hMDoubleJpsi->Integral()/h_mix->Integral());
    h_mix->SetLineColor(kRed);
    h_mix->SetMarkerColor(kRed);
    h_mix->Draw("e1same");
    std::cout << "h_mix->Integral() = " << h_mix->Integral() << std::endl;


    TString total_data = "data (" + std::to_string((int)hMDoubleJpsi->Integral()) + " total)";
    TLegend* leg = new TLegend(0.7,0.7,0.9,0.9);
    leg->AddEntry(hMDoubleJpsi,total_data,"lep");
    leg->AddEntry(h_mix,"mixed BG","lep");
    leg->Draw("same");
    cjpsimix->SaveAs("plots/hMDoubleJpsi_origVSphyskbg.png");
    //hMDoubleJpsi->SetMarkerStyle(20);
    //hMDoubleJpsi->SetMarkerColor(kBlack);
    TH1F *hMDoubleJpsi_copy = (TH1F*)hMDoubleJpsi->Clone("hMDoubleJpsi_copy");
    if(blind_signal)
        { for(int i=1; i <= hMDoubleJpsi_copy->GetSize()-2; i++)
            {
                if(i>= hMDoubleJpsi_copy->FindBin(6.2) && i<= hMDoubleJpsi_copy->FindBin(8))
                     hMDoubleJpsi_copy->SetBinContent(i,0);
   
            }    
         }
    hMDoubleJpsi_copy->SetLineColor(kBlue);
    hMDoubleJpsi_copy->SetMarkerColor(kBlue);
    hMDoubleJpsi_copy->Draw("e1");
    h_mix->Scale(scaleEntries/h_mix->Integral());
    h_mix->SetLineColor(kRed);
    h_mix->SetMarkerColor(kRed);
    h_mix->Draw("e1same");
    leg->Draw("same");
    cjpsimix->SaveAs("plots/hMDoubleJpsi_origVSphyskbg_blind.png");
 
   // compare original vs mix high
    cjpsimix_high->cd(); 
    //TCanvas *c3 = new TCanvas("c3","c3",800,600);
    hMDoubleJpsi->SetMarkerStyle(20);
    hMDoubleJpsi->SetMarkerColor(kBlue);
    hMDoubleJpsi->SetLineColor(kBlue);
    hMDoubleJpsi->Draw("e1");
    std::cout << "hMDoubleJpsi->Integral() = " << hMDoubleJpsi->Integral() << std::endl;
    h_mix_high->Scale(hMDoubleJpsi->Integral()/h_mix_high->Integral());
    h_mix_high->SetLineColor(kRed);
    h_mix_high->SetMarkerColor(kRed);
    h_mix_high->Draw("e1same");
    std::cout << "h_mix_high->Integral() = " << h_mix_high->Integral() << std::endl;


    TString total_data_high = "data (" + std::to_string((int)hMDoubleJpsi->Integral()) + " total)";
    TLegend* leg_high = new TLegend(0.7,0.7,0.9,0.9);
    leg_high->AddEntry(hMDoubleJpsi,total_data,"lep");
    leg_high->AddEntry(h_mix_high,"mixed BG","lep");
    leg_high->Draw("same");
    cjpsimix_high->SaveAs("plots/hMDoubleJpsi_origVSphyskbg_high.png");
    //hMDoubleJpsi->SetMarkerStyle(20);
    //hMDoubleJpsi->SetMarkerColor(kBlack);
    TH1F *hMDoubleJpsi_copy_2 = (TH1F*)hMDoubleJpsi->Clone("hMDoubleJpsi_copy_2");
    if(blind_signal)
        { for(int i=1; i <= hMDoubleJpsi_copy_2->GetSize()-2; i++)
            {
                if(i>= hMDoubleJpsi_copy_2->FindBin(6.2) && i<= hMDoubleJpsi_copy_2->FindBin(8))
                     hMDoubleJpsi_copy_2->SetBinContent(i,0);
   
            }    
         }
    hMDoubleJpsi_copy_2->SetLineColor(kBlue);
    hMDoubleJpsi_copy_2->SetMarkerColor(kBlue);
    hMDoubleJpsi_copy_2->Draw("e1");
    h_mix_high->Scale(scaleEntries/h_mix_high->Integral());
    h_mix_high->SetLineColor(kRed);
    h_mix_high->SetMarkerColor(kRed);
    h_mix_high->Draw("e1same");
    leg_high->Draw("same");
    cjpsimix_high->SaveAs("plots/hMDoubleJpsi_origVSphyskbg_blind_high.png");
  

  
   //std::cout << __LINE__ << " Checked " << std::endl;
    c4mumix->cd();
    hMFourMu->SetMarkerStyle(20);
    hMFourMu->SetMarkerColor(kBlue);
    hMFourMu->SetLineColor(kBlue);
    hMFourMu->Draw("e1");
    std::cout << "hMFourMu->Integral() = " << hMFourMu->Integral() << std::endl;
    h_mix->Scale(hMFourMu->Integral()/h_mix->Integral());
    h_mix->SetLineColor(kRed);
    h_mix->SetMarkerColor(kRed);
    h_mix->Draw("e1same");
    std::cout << "h_mix->Integral() = " << h_mix->Integral() << std::endl;


    TString total_data4mu = "data4mu (" + std::to_string((int)hMFourMu->Integral()) + " total)";
    TLegend* leg1 = new TLegend(0.7,0.7,0.9,0.9);
    leg1->AddEntry(hMFourMu,total_data4mu,"lep");
    leg1->AddEntry(h_mix,"mixed BG","lep");
    leg1->Draw("same");
    c4mumix->SaveAs("plots/hMFourMu_origVSphyskbg.png");
 
  //4 muon ocmbination high ////std::cout << __LINE__ << " Checked " << std::endl;
    c4mumix_high->cd();
    hMFourMu->SetMarkerStyle(20);
    hMFourMu->SetMarkerColor(kBlue);
    hMFourMu->SetLineColor(kBlue);
    hMFourMu->Draw("e1");
    std::cout << "hMFourMu->Integral() = " << hMFourMu->Integral() << std::endl;
    h_mix_high->Scale(hMFourMu->Integral()/h_mix_high->Integral());
    h_mix_high->SetLineColor(kRed);
    h_mix_high->SetMarkerColor(kRed);
    h_mix_high->Draw("e1same");
    std::cout << "h_mix_high->Integral() = " << h_mix_high->Integral() << std::endl;


    TString total_data4mu_high = "data4mu (" + std::to_string((int)hMFourMu->Integral()) + " total)";
    TLegend* leg1_high = new TLegend(0.7,0.7,0.9,0.9);
    leg1_high->AddEntry(hMFourMu,total_data4mu,"lep");
    leg1_high->AddEntry(h_mix_high,"mixed BG","lep");
    leg1_high->Draw("same");
    c4mumix_high->SaveAs("plots/hMFourMu_origVSphyskbg_high.png");
  

   
    clearHistograms();
    fout->Write();
    f->Close();
    fout->Close();

}//end Testrandomproduction function


int main(int argc, char* argv[])
{
    cout << "TestRandom Production!" << endl;
    TApplication myapp("TestRandom Prod", &argc, argv);
   testrandomprod();


    return 0;
    
}
#endif /* TESTER_H */


