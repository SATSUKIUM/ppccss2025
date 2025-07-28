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

// fitting
#include <RooRealVar.h>
#include <RooGaussian.h>
#include <RooPlot.h>

using namespace RooFit;
 
void fitGauss1()
{
  RooRealVar x("x", "x", -10, 10); // フィット変数
  RooRealVar mean("mean", "Mean of Gaussian", 0, -10, 10); // フィットパラメータ
  RooRealVar sigma("sigma", "Width of Gaussian", 1, -10, 10); // フィットパラメータ
 
  RooGaussian gauss("gauss", "gauss(x, mean, sigma)", x, mean, sigma);
 
  RooPlot* xframe = x.frame();
  gauss.plotOn(xframe);
  xframe->Draw();
}