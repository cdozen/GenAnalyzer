// // Description: Double Jpsi combinatorial background  by event-mixing

#include "TCanvas.h"
#include "TROOT.h"
#include "TF1.h"
#include "TF2.h"
#include "TLegend.h"
#include "TH1.h"
#include "TCut.h"
#include "TLorentzVector.h"
#include <iostream>
#include <sstream>      // std::stringstream
#include <fstream>      // ifstream
#include <vector>
#include "Riostream.h"
#include "TFile.h"
//#include "TNtuple.h"
#include "TTree.h"
#include "FMu.C"
//#include "DPSJJ.C"
using namespace std;

void DoubleJpsi_mixmu1only_02(){

    TFile *f = new TFile("../../../7Nov2020_DPSJJ_WITH_genfilter_2018_WITH_etptcut.root");  
    //TFile *f = new TFile("/Users/candandozen/Desktop/Gen_level_eventmixing/TruthNtupMaker/Event_mixing_oldDRmethod/WithGenfilter/DPSJJ_withgenfiler_2018_w_etptcut.root");  
    TTree *fTree = (TTree*) f->Get("FourMu_tree");
 
    FMu *ReadTree = new FMu(fTree);



	TCanvas *cmix = new TCanvas("cmix","mixing",600,400);
	TCanvas *c4mu = new TCanvas("c4mu","4 muons",600,400);
	TCanvas *c2j = new TCanvas("c2j","2 jpsi",600,400);
	TH1F *hmix = new TH1F("hmix","hmix",100,6,10);
	hmix->GetXaxis()->SetTitle("Mix four muon mass [GeV]");
	hmix->GetYaxis()->SetTitle("Events / 0.04GeV");
	hmix->GetYaxis()->SetLabelSize(0.03);

	TH1F *hMFourMu = new TH1F("hMFourMu","hMFourMu",100,6,10);
	hMFourMu->GetXaxis()->SetTitle("four Mu mass [GeV]");
	hMFourMu->GetYaxis()->SetTitle("Events / 0.04GeV");
	hMFourMu->GetYaxis()->SetLabelSize(0.03);

	TH1F *hMDoubleJpsi = new TH1F("hMDoubleJpsi","hMDoubleJpsi",100,6,10);
	hMDoubleJpsi->GetXaxis()->SetTitle("double Jpsi mass [GeV]");
	hMDoubleJpsi->GetYaxis()->SetTitle("Events / 0.04GeV");
	hMDoubleJpsi->GetYaxis()->SetLabelSize(0.03);

	TLorentzVector mu1,mu2,mu3,mu4;
	TLorentzVector J1,J2,J12,J34;
	TLorentzVector DoubleJpsi;
	TLorentzVector FourMu;

	std::vector<TLorentzVector> mu1_p4_vector;
	std::vector<TLorentzVector> mu2_p4_vector;
	std::vector<TLorentzVector> mu3_p4_vector;
	std::vector<TLorentzVector> mu4_p4_vector;
	std::vector<TLorentzVector> mu12_p4_vector;
	std::vector<TLorentzVector> mu34_p4_vector;

        int Ntotal = fTree->GetEntries();
        cout << "!!***************************************!!\n";
        cout << " Readed   :" << Ntotal << "\n";
        cout << "!!***************************************!!\n";
	//Read the event
        for (int i = 0; i < Ntotal; i++)
        {
            ReadTree->GetEntry(i);

   cout<<"\r Read Event:"<< i <<"/"<<Ntotal<<flush;
		mu1  = *ReadTree->mu1;
		mu2  = *ReadTree->mu2;
		mu3  = *ReadTree->mu3;
		mu4  = *ReadTree->mu4;
		J1   = *ReadTree->mu12;
		J2   = *ReadTree->mu34;
		
		
		J12=mu1+mu2;
		J34=mu3+mu4;
		mu1_p4_vector.push_back(mu1);
		mu2_p4_vector.push_back(mu2);
		mu3_p4_vector.push_back(mu3);
		mu4_p4_vector.push_back(mu4);
		mu12_p4_vector.push_back(J12);
		mu34_p4_vector.push_back(J34);

		//std::cout<<m1<<" "<<J12.M()<<std::endl;
		//4 muon combination 
		FourMu=mu1+mu2+mu3+mu4;
		hMFourMu->Fill(FourMu.M()-J12.M()-J34.M()+2*3.096);
		//Double jpsi comnbonation
		DoubleJpsi=J1+J2;
		hMDoubleJpsi->Fill(DoubleJpsi.M()-J12.M()-J34.M()+2*3.096);
		//Fill the branches
		
	}//event dongusundeki okuma isleri bitti. event by event doldurduk 

	cout<<"--->"<<endl;
//combination of the mu12 and mu34 vectors //bu vektorleri kullanarak kombinasyon alicaz 
int num =mu34_p4_vector.size();
	for (unsigned j=0; j<mu2_p4_vector.size();j++){ 
		for (unsigned k=0; k<mu1_p4_vector.size();k++){
			if (j==k) continue;//ayni eventte olmasinlar
			//fiziksel yontem, old deltaR method. 
			if ( fabs(mu1_p4_vector[k].Vect().DeltaR( mu1_p4_vector[j].Vect())) > 0.2) continue;
			//if ( fabs(mu12_p4_vector[k].Vect().DeltaR( mu12_p4_vector[j].Vect())) > 0.15) continue;
			//if ( fabs(mu12_p4_vector[k].Vect().DeltaR( mu12_p4_vector[j].Vect())) > 0.2) continue;
			//if ( fabs(mu12_p4_vector[k].Vect().DeltaR( mu12_p4_vector[j].Vect())) > 0.3) continue;
//Double_t DeltaPhi =(fabs(mu12_p4_vector[k].Phi() - mu12_p4_vector[j].Phi()));
//             Double_t DeltaY =(fabs(mu12_p4_vector[k].Rapidity() - mu12_p4_vector[j].Rapidity()));
//             Double_t DeltaR=sqrt((DeltaPhi*DeltaPhi)+ (DeltaY*DeltaY));
//             if (DeltaR>0.3) continue;
			
//mixing yontem mu12 ile mu34 mix et. 
			TLorentzVector newmu12;
			newmu12= mu1_p4_vector[k]+mu2_p4_vector[j];
			 cout<<"\r Inside loop :"<< j <<"/"<<num<<flush;
			TLorentzVector mixFourMu;
			mixFourMu=newmu12+mu34_p4_vector[j];
			//hmix->Fill(mixFourMu.M());
			//differences ? check it 
			hmix->Fill(mixFourMu.M()-newmu12.M()-mu34_p4_vector[j].M()+2*3.096);
		}
	}
	cmix->cd();
	hmix->Sumw2();
	hmix->SetMarkerColor(kRed);
	hmix->SetLineColor(kRed);
	hmix->Draw("e1");

	cmix->SaveAs("plots_witgenfilt_WITH_etaptcuts_SingleMuonMix_DR02/cmix.png");
        c4mu->cd();
	hMFourMu->SetMarkerColor(kBlue);
	hMFourMu->SetLineColor(kBlue);
	hMFourMu->Draw("e1");
	//
	hmix->Scale((float)hMFourMu->Integral()/hmix->Integral());
	hmix->SetMarkerColor(kRed);
	hmix->SetLineColor(kRed);
	hmix->Draw("e1same");
        c4mu->SaveAs("plots_witgenfilt_WITH_etaptcuts_SingleMuonMix_DR02/c4mu.png");
	c2j->cd();
	hMDoubleJpsi->Draw("e1");
        c2j->SaveAs("plots_witgenfilt_WITH_etaptcuts_SingleMuonMix_DR02/c2j.png");

}


int main(){

	DoubleJpsi_mixmu1only_02();
}
