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

void readNtuple(){
TH1F  *hist = new TH1F("lep_pt", "p_{T} of muons", 100, 0, 100000);
 
  TFile *file = TFile::Open("./mcsample.root", "READ");
  TTree *tree = dynamic_cast<TTree*>(file->Get("mini"));
 
  Int_t lep_max = tree->GetMaximum("lep_n");
 
  // branchに対応付ける変数を作成
  Int_t   eventNumber;
  UInt_t  lep_n;
  Float_t lep_pt[lep_max];
  UInt_t  lep_type[lep_max];
 
  // ローカル変数のアドレスを各branchに対応付け
  tree->SetBranchAddress("eventNumber", &eventNumber);
  tree->SetBranchAddress("lep_n",       &lep_n);
  tree->SetBranchAddress("lep_pt",      lep_pt);
  tree->SetBranchAddress("lep_type",    lep_type);
 
  // TTreeの全Entry数でループを回し、1 entryずつ解析する
  Int_t nevents = tree->GetEntries();
  for(Int_t ii = 0; ii < nevents; ii++) {
 
    // ii番目のentryに格納されている各branchの値を、対応付けた変数に与える　
    tree->GetEntry(ii);
 
     // そのentryに保存されているレプトンの数だけループし、ミューオンを探す
    for (Int_t lep1 = 0; lep1 < lep_n; lep1++) {
 
      // ミューオンのみを選ぶ
      if (lep_type[lep1] != 13) continue;
 
      hist->Fill(lep_pt[lep1]);
      std::cout << lep_pt[lep1] << std::endl;
    }
  }
 
  hist->Draw();
}