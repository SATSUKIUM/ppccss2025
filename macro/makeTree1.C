#include <TStyle.h>
#include <TCanvas.h>

#include <TSystem.h>

// C++の標準ライブラリ
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

// 時刻情報
#include <iomanip>
#include <chrono>
#include <ctime>

// ヒストグラム関係
#include <TH1.h>
#include <TH2.h>

// グラフ
#include <TGraphErrors.h>
#include <TLegend.h>

// 見栄え関係
#include <TPad.h>
#include <TColor.h>

// 乱数
#include <TRandom.h>
#include <TRandom3.h>

// ファイル書き出し
#include <TFile.h>

// fitting
#include <RooRealVar.h>
#include <RooGaussian.h>
#include <RooPlot.h>

// tree
#include <TTree.h>

#include <TMath.h>
#include <TF1.h>

void makeTree1(){
    const Int_t nentries = 5;
    Int_t    a_ntrack[nentries]  = {0, 1, 2, 3, 4};                          // 荷電粒子の軌跡No.
    Double_t a_momentum[nentries] = {3200.4, 2893.2, 3603.9, 9899.1, 5674.3}; // 運動量[MeV]
    Double_t a_position[nentries] = {7643, 9834, 11232, 10232, 8092};         // 座標 z [mm]
    Int_t    a_charge[nentries]   = {-1, 1, 1, -1, 1};                        // 電荷

    TFile *file = TFile::Open("tree.root","RECREATE");
    TTree *tree = new TTree("tree","tree");

    Int_t ntrack;
    Double_t momentum;
    Double_t position;
    Int_t charge;

    tree->Branch("ntrack", &ntrack, "ntrack/I");
    tree->Branch("momentum", &momentum, "momentum/D");
    tree->Branch("position", &position, "position/D");
    tree->Branch("charge", &charge, "charge/I");

    for(Int_t ii=0; ii<nentries; ii++){
        ntrack = a_ntrack[ii];
        momentum = a_momentum[ii];
        position = a_position[ii];
        charge = a_charge[ii];

        tree->Fill();
    }

    tree->Write();
    file->Close();
}