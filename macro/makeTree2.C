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


void makeTree2(){
    Int_t    ntrack;
    Double_t momentum;
    Double_t position;
    Int_t    charge;

    TFile *file = TFile::Open("tree.root","RECREATE");
    TTree *tree = new TTree("tree","tree");

    TString input = "data/particles.txt";
    tree->ReadFile(input.Data(), "ntrack/I:momentum/D:position/D:charge/I");

    tree->Write();
    file->Close();
}