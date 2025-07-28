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

// // 色
// #include <TColor.h>

void fitGauss2()
{
 
  // ガウス分布のデータを作成する
  TH1F *hist = new TH1F("hist", "hist", 20, -10, 10);
 
  Double_t tree_x;
  TTree *tree = new TTree("tree", "tree");
  tree->Branch("x", &tree_x, "x/D");
 
  TRandom3 rndm(0);
  for(int ii = 0; ii < 100; ii++) {
    float rndm_x = rndm.Gaus(0, 1);
    hist->Fill(rndm_x);
    tree_x = rndm_x;
    tree->Fill();
  }
 
  // PDFの作成とフィット
  RooRealVar x("x", "x", -10, 10);
  RooRealVar mean("mean", "Mean of Gaussian", 0, -10, 10);
  RooRealVar sigma("sigma", "Width of Gaussian", 1, -10, 10);
 
  RooGaussian gauss("gauss", "gauss(x, mean, sigma)", x, mean, sigma);
 
  RooDataHist data_h("data_h", "binned dataset", x, hist);   // binned data
  RooDataSet data_t("data_t", "unbinned dataset", RooArgSet(x), Import(*tree));  // unbinned data
 
  RooPlot* xframe = x.frame();
  data_h.plotOn(xframe);
 
  gauss.fitTo(data_h);
  gauss.plotOn(xframe);
 
  gauss.fitTo(data_t);
  gauss.plotOn(xframe,LineColor(kRed));
 
  xframe->Draw();
}