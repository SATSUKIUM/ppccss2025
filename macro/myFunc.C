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

double form6(double *x, double *par)
{
  double arg = 0;
  if (par[2] != 0) arg = (x[0] - par[1])/par[2];
 
  double val = par[0]*TMath::Exp(-0.5*arg*arg);
 
  if(x[0] < par[3] ||
     x[0] > par[4])
    return val;
  else
    return 0;
}
 
void myFunc()
{
   //第5引数でこの関数のパラメータの数を指定しておく
  TF1 *func6 = new TF1("func6",form6,0,10,5);
 
  func6->SetParameters(10,4,1,5,6);
  func6->SetParNames("Constant","Mean_value","Sigma");
 
  func6->Draw();
}