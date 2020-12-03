/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SetHistograms.h
 * Author: Candan
 *
 * Created on November 20, 2019, 11:02 PM
 */

#ifndef SETHISTOGRAMS_H
#define SETHISTOGRAMS_H
#include "TCanvas.h"
#include "TAxis.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TLegend.h"
 
        ///*******************************//
        /// Define Histograms
        ///*******************************//
        TFile *fout = new TFile("Plots.root","recreate");  
        TH1F *mix_J1pt        = new TH1F("mix_J1pt","",20,0,40);
        TH1F *mix_J1eta       = new TH1F("mix_J1eta","",20,-5.0,5.0);
        TH1F *mix_J1rapid     = new TH1F("mix_J1rapid","",20,-3.0,3.0);
        TH1F *mix_J1phi       = new TH1F("mix_J1phi","",20,-5,5);
       // TH2F *mix_Y2Dpteta   = new TH2F("mix_Y2Dpteta","mix_Y2Dpteta",20,-5,5,20,0,40);
       // TH2F *mix_Y2Dptrapid = new TH2F("mix_Y2Dptrapid","mix_Y2Dptrapid",20,-5,5,20,0,40);
       // TH2F *mix_Y2Detarapid = new TH2F("mix_Y2Detarapid","mix_Y2Detarapid",20,-5,5,20,-5,5);
               ///
        TH1F *J1pt    = new TH1F("J1pt","",20,0,40);        
        TH1F *J1eta   = new TH1F("J1eta","",20,-5.0,5.0);
        TH1F *J1rapid = new TH1F("J1rapid","",20,-3.0,3.0);
       TH1F *J1phi   = new TH1F("J1phi","",20,-5.0,5.0);
       // TH2F *Y2Dpteta = new TH2F("Y2Dpteta","Y2Dpteta",20,-5,5,20,0,40);
       // TH2F *Y2Dptrapid = new TH2F("Y2Dptrapid","Y2Dptrapid",20,-5,5,20,0,40);
       // TH2F *Y2Detarapid = new TH2F("Y2Detarapid","Y2Detarapid",20,-5,5,20,-5,5);
       // TH2F *Y2Dptphi = new TH2F("Y2Dptphi","Y2Dptphi",20,-4,4,20,0,40);
       // TH2F *Y2Detaphi = new TH2F("Y2Detaphi","Y2Detaphi",20,-5,5,20,-4,4);
        



        //fourMuMass histograms
        TH1F *hMFourMu = new TH1F("hfourMuMass","hfourMuMass",100,6,10);
        TH1F *hMDoubleJpsi = new TH1F("hMDoubleJpsi","hMDoubleJpsi",100,6,10);
        TH1F *h_mix = new TH1F("h_mix","h_mix",100,6,10);
        TH1F *h_mix_high = new TH1F("h_mix_high","h_mix_high",100,6,10);
        //TH1F *hfourMuMass_mix_aftercut = new TH1F("hfourMuMass_mix_aftercut","hfourMuMass_mix_aftercut",100,6,10);
        //TH1F *hfourMuMass_mix_smallrange = new TH1F("hfourMuMass_mix_smallrange","hfourMuMass_mix_smallrange",100,6,10);
        
        //TH1F *hfourMuMass_physkbg_mix = new TH1F("hfourMuMass_physkbg_mix","hfourMuMass_physkbg_mix",100,6,10);
	 //TH1F *hfourMuMass_physkbg_mix_smallrange = new TH1F("hfourMuMass_physkbg_mix_smallrange","hfourMuMass_physkbg_mix_smallrange",65,13,26);
        //TH2F *Ymumu2D_physkbg_mix = new TH2F("Ymumu2D_physkbg_mix","Ymumu2D_physkbg_mix",60,-6,6,60,-6,6);
	

        ///*******************************//
	// Clear the histos
        ///*******************************//  
        void clearHistograms(){
        mix_J1pt->Clear();
        mix_J1eta->Clear()       ;
        mix_J1rapid->Clear()     ;
        mix_J1phi->Clear()      ;
        //mix_Y2Dpteta->Clear()   ;
        //mix_Y2Dptrapid->Clear();
        
       ///
        J1pt->Clear();        
        J1eta->Clear();
        J1rapid->Clear();
        J1phi->Clear();
        //Y2Dpteta->Clear()   ;
        //Y2Dptrapid->Clear();
       //// 
       h_mix-> Clear();
       h_mix_high-> Clear();
        
        
        
        ////
        hMFourMu->Clear(); 
        hMDoubleJpsi->Clear();

        
        }

        ///*******************************//
	// Set initial values
        ///*******************************//
        void define_and_setHistograms(){
        mix_J1pt->Sumw2();
        mix_J1rapid->Sumw2();
        mix_J1eta->Sumw2();
        mix_J1phi->Sumw2();
        J1pt->Sumw2();
        J1eta->Sumw2();
        J1rapid->Sumw2();     
        J1phi->Sumw2();
        
        J1pt->GetXaxis()->SetTitle("Upsilon p_{T} [GeV]"); 
        J1eta->GetXaxis()->SetTitle("Upsilon #eta"); 
        J1rapid->GetXaxis()->SetTitle("Upsilon Rapidity"); 
        J1phi->GetXaxis()->SetTitle("Upsilon #phi"); 
        
        /*mix_Y2Dpteta->GetXaxis()->SetTitle("#Upsilon_mix #eta");
	    mix_Y2Dpteta->GetYaxis()->SetTitle("#Upsilon_mix p_{T} (GeV)");
	    mix_Y2Dptrapid->GetXaxis()->SetTitle("#Upsilon_mix Rapidity");
	    mix_Y2Dptrapid->GetYaxis()->SetTitle("#Upsilon_mix p_{T} (GeV)");
*/
        
       
       
       
       hMFourMu->SetStats(0);
hMDoubleJpsi->SetStats(0);
h_mix->SetStats(0);
h_mix_high->SetStats(0);
        
hMFourMu->GetXaxis()->SetTitle("4 muon mass [GeV]");
hMFourMu->GetYaxis()->SetTitle("Candidates / GeV");
hMFourMu->GetYaxis()->SetLabelSize(0.03);

hMDoubleJpsi->GetXaxis()->SetTitle("Double JPsi [GeV]");
hMDoubleJpsi->GetYaxis()->SetTitle("Candidates / GeV");
hMDoubleJpsi->GetYaxis()->SetLabelSize(0.03);

h_mix->GetXaxis()->SetTitle("Double JPsi [GeV]");
h_mix->GetYaxis()->SetTitle("Candidates / GeV");
h_mix->GetYaxis()->SetLabelSize(0.03);

h_mix_high->GetXaxis()->SetTitle("Double JPsi [GeV]");
h_mix_high->GetYaxis()->SetTitle("Candidates / GeV");
h_mix_high->GetYaxis()->SetLabelSize(0.03);

}
        
        
        //******************************************//
        // Plot Function
        //******************************************//        
        void ScaledPlot(
        
                    TString CanvasName,
                        TH1F *hist1,
                        TH1F *hist2,
                        TString Xtitle,
                        TString Ytitle,
                        bool Ratio=true
                    )
        {
                
        TCanvas *c1 = new TCanvas(CanvasName.Data(),CanvasName.Data(),800,600);
		hist1->SetStats(0);
		hist2->SetStats(0);
        hist1->SetTitle(CanvasName.Data()); 
		hist1->Scale(1/hist1->Integral());
		hist2->Scale(1/hist2->Integral());
		double maximum_range = max(hist1->GetMaximum(),hist2->GetMaximum());
		hist1->SetMinimum(0);
		hist1->SetMaximum(1.3*maximum_range);
		hist1->SetMarkerStyle(20);
		hist1->SetMarkerColor(kBlack);
		hist1->SetLineColor(kBlack);
        hist1->Draw("hist p");
		TLegend* leg3 = new TLegend(0.7,0.7,0.9,0.9);
		leg3->AddEntry(hist1,hist1->GetName(),"lep");
		leg3->AddEntry(hist2,hist2->GetName(),"lep");
		leg3->Draw("same");
		hist2->SetMarkerStyle(22);
		hist2->SetMarkerColor(kBlue);
        hist2->Draw("hist p same");
                  if (Ratio)
                             {
                		c1->SetBottomMargin(0.3);
		                hist1->GetXaxis()->SetTitleSize(0);
                		hist1->GetXaxis()->SetLabelSize(0);
                 		TH1F *Totratio = (TH1F*)hist2->Clone("Totratio");
          		        Totratio->Divide(hist1);
       			        Totratio->GetXaxis()->SetMoreLogLabels(kTRUE);
               			Totratio->GetXaxis()->SetNoExponent(kTRUE);
                        TPad *pad1 = new TPad("pad1", "pad1", 0.0, 0.0, 0.93, 0.93);
                        pad1->SetTopMargin(0.7);
                        pad1->SetRightMargin(0.03);
                        pad1->SetFillColor(0);
                        pad1->SetGridy(1);
	                    pad1->SetFillStyle(0);
               	        pad1->Draw();
                 	    pad1->cd(0);
              		    Totratio->GetXaxis()->SetTitle(Xtitle); //"p_{T}(#Upsilon) [GeV]""
                 		Totratio->GetYaxis()->SetTitle(Ytitle);       //"Mixed(#Upsilon)/#Upsilon"
                 		Totratio->GetYaxis()->SetTitleOffset(1.2);
                 		Totratio->GetXaxis()->SetTitleOffset(1.2);
                 		Totratio->GetYaxis()->SetLabelSize(0.03);
                 		Totratio->SetMarkerStyle(20);
                 		Totratio->SetMarkerSize(1.2);
                 		Totratio->SetLineColor(1);
                 		Totratio->SetMarkerColor(1);
                 		Totratio->GetYaxis()->SetNdivisions(204);
                 		Totratio->SetMinimum(0.0);
                 		Totratio->SetMaximum(2.0);
                 		Totratio->Draw("ep");
                 		c1->Modified();
                 		c1->Update();
                  		}
	    c1->SaveAs(CanvasName+".png");
        c1->Clear();
        
        }
#endif /* SETHISTOGRAMS_H */

