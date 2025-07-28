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

// ファイル書き出し
#include <TFile.h>


void drawHistogram2()
{
  TH1F* myHist = new TH1F("myHist", "My first histogram", 30, -5., 5.);
  
  TRandom rndm(0);
  Float_t rndm_x;
  for(Int_t i=0; i<500000 ; i++){
    rndm_x = rndm.Gaus(0,1);
    myHist->Fill(rndm_x);
  }
  myHist->SetFillStyle(3004);
  myHist->SetFillColor(2);

  myHist->Draw();

  TFile *file = new TFile("output.root", "RECREATE");
  file->cd();
  myHist->Write();
  file->Close();
}
